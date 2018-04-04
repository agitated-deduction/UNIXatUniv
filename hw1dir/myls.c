/* ----------------------------------------------------------------------------------------------------
 *  파일		: myls.c
 *  기능		: ls 명령어 구현 
 *			-a: 숨김파일을 포함하여 모든 파일 및 디렉토리 이름을 보여줌
 *			-l: 파일 및 디렉토리의 상세정보 나열
 *  개발자	: 201521672 박소연 
 *  날짜		: 1차 개발 : 2018년 3월 10일 
 *  참고		: https://github.com/zhujinliang/ls
 			  UNIX 고급 프로그래밍 제 3판-Stevens, Rago
 			  https://www.joinc.co.kr/w/man/2/stat
 *----------------------------------------------------------------------------------------------------*/
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include "../apue.h"

/* 
function : get_option
기능 : 세부옵션 확인. 옵션에 따른 플래그 설정
세부 옵션 -a, -l 두 가지.
입력값 : argv 옵션 스트링
*/
static bool is_a = false;
static bool is_l = false;

void get_option(char* argv){
	if (strstr(argv,"a")!=NULL) is_a = true;
	if (strstr(argv,"l")!=NULL) is_l = true;
	//a혹은 l 입력시에만 처리. 다른 값은 반응 없음.(2018-03-11)
}
/*
function : print_list
기능 : 세부 옵션과 디렉토리 명에 따른 정보 출력
	./myls -option directory_name
	option : -a, -l, 입력없음 가능,-al 가능(2018-03-11)
	-a: 숨김 파일을 포함하여 모든 파일의 파일이름을 출력
	-l: 접근 권한, user ID of owner, group ID of owner, file name 출력
	directory_name : 입력하면 입력된 디렉토리 내부의 파일들 정보,
					입력하지 않으면, 현재 디렉토리 내부의 파일들 정보
	warning : passing argument 1of 'strgtime' from incompatible pointer type.
*/
void print_list(char* path){
	DIR *dp;
	struct dirent *dir;
	//char *fileName = NULL;
	struct stat st; //파일 정보 저장 구조체
	//char* flag = NULL;
	char time[256];

	char temp[200];
	if (path == NULL){
		//path = temp;
		path = getcwd(temp,200);
	}
	if ((dp = opendir(path)) == NULL)
		err_sys("can't open.");
		//fileName = dir->d_name;
	while((dir = readdir(dp))!=NULL){
		if (!is_a){
			if (strncmp(dir->d_name,".",1) == 0) continue;
		}
		if (is_l){
			lstat(dir->d_name, &st);
			printf("\n");
	        (S_ISDIR(st.st_mode)) ? printf("d"): printf("-");
	        //permissions
	        (st.st_mode & S_IRUSR) ? printf("r"): printf("-");
	        (st.st_mode & S_IWUSR) ? printf("w"): printf("-");
	        (st.st_mode & S_IXUSR) ? printf("x"): printf("-");
	        (st.st_mode & S_IRGRP) ? printf("r"): printf("-");
	        (st.st_mode & S_IWGRP) ? printf("w"): printf("-");
	        (st.st_mode & S_IXGRP) ? printf("x"): printf("-");
	        (st.st_mode & S_IROTH) ? printf("r"): printf("-");
	        (st.st_mode & S_IWOTH) ? printf("w"): printf("-");
	        (st.st_mode & S_IXOTH) ? printf("x"): printf("-");
	        

	        printf("%3d%3d%3d", st.st_nlink, st.st_uid, st.st_gid);        
	        
	    	strftime(time, sizeof(time), "%Y-%m-%d %H:%M", localtime(&st.st_mtime));
	        printf("%10ld   %s  ", st.st_size, time);
	    }
	    printf("%3s\t", dir->d_name);
		
	}	
	if (closedir(dp))
    {
    	//오류처리
       err_sys("can't close the directory\n");
    }printf("\n");
}

int main (int argc, char *argv[]){
	
	int flag = 1;
	if (argc == 1){
		print_list(NULL);
	}
	else if (argc == 2||argc == 3){
		if (strncmp(&argv[1][0],"-",1)==0||argc == 3){
		get_option(argv[1]);
			flag++;
		}
		print_list(argv[flag]);
	}
	else
		err_quit("wrong usage\n");
	
}
