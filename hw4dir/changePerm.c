/*======================================================================
 * 파일 : changePerm.c
 * 기능 : 파일 권한과 소유권을 변경한다.
 * 작성자: 201521672 박소연
 * 날짜 : 2018-04-02
 * 참고 : https://www.experts-exchange.com/questions/21652253/Character-string-to-mode-t-conversion.html
 *======================================================================*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int changePerm(int argc, char *argv1, char *argv2, char* argv3, char *argv4){

	if(argc !=6){
		fprintf(stderr, "usage: ./release [option] [find.txt/file_info.txt] [permission] [uid] [gid]\n");
		return 1;
	}
	char* file = (char*)argv1;
	int i = atoi(argv2);
	char perms[8];

	sprintf(perms, "%d", i);
	mode_t mode = strtol(perms, NULL, 8);
	
	chmod(file, mode);
	chown(file, atoi(argv3), atoi(argv4));
	return 0;
}

