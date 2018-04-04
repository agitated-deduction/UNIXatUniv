/*===========================================================
* 파 일	: hardlink.c
* 기 능	: ln -u
* 개발자 : 201521672 박소연
* 날 짜 : 1차 개발: 2018-03-27
* 참 고	: https://github.com/marcomc/hardlink/blob/master/hardlink.c
=============================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){
if(argc !=2)
	fprintf(stderr,"usage: unlink destination\n");	//인수의 개수가 옳지 않으면, 사용법 출력. error
if(unlink(argv[1])!=0)
	perror("unlink error");
exit(0);
}
