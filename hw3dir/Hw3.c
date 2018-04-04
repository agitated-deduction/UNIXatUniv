/*======================================================================
* 파 	일	: Hw3.c
* 개 발 자	: 201521672 박소연
* 날 	짜	: 1차 개발: 2018-03-23
* 기 	능	: exam 파일을 생성하고 문자열을 입력.
*		  입력한 문자열을 lseek을 이용하여
		  앞에서 뒤쪽으로 2칸씩 이동하며 출력하고
		  뒤쪽에서 앞쪽으로 3칸씩 이동하며 출력한다. 
========================================================================*/
#include<fcntl.h>
#include"../apue.h"

#define BUFFSIZE 4096

int main(void){
	int n;
	char buf[BUFFSIZE];
	char *file = "./exam";					//생성되는 파일.

	int fd = creat(file, 0744);
	close(fd);

	open(file, O_RDWR);
	//System Software Security
	while((n = read(STDIN_FILENO, buf, BUFFSIZE))>0){
		if (write(fd, buf, n) != n)
			err_sys("write error");
	}											//파일에 글자를 입력함
	if (n<0)
		err_sys("read error");
	int tmp  = lseek(fd, 0, SEEK_SET);			//tmp는 현재 오프셋을 저장함
	printf("\n===================\n");
	printf("2칸씩 뒤로 이동하며 출력 :\n");
	while((n=pread(fd, buf, 2,tmp))>0){			//(03-25)pread는 읽으면서 오프셋의 위치를 변경시키지 않음
		write(STDOUT_FILENO, buf, n);
		tmp = lseek(fd, 2, SEEK_CUR);
	}printf("\n===================\n");
	printf("3칸씩 앞으로 이동하며 출력 :\n");
	tmp = lseek(fd, -3, SEEK_END);	
	while((n = pread(fd, buf, 3, tmp))>0){
		write(STDOUT_FILENO, buf, n);
		tmp = lseek(fd, -3, SEEK_CUR);
	//	if((n = pread(fd, buf, 3, tmp))>(-1)){
	//		write(STDOUT_FILENO, buf, n);
	//	}
	}printf("\n");
	close(fd);
	exit(0);
}
