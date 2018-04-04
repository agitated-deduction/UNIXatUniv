/*===========================================================
* 파 일	: hardlink.c
* 기 능	: ln
* 개발자 : 201521672 박소연
* 날 짜 : 1차 개발: 2018-03-25
* 참 고	: https://github.com/marcomc/hardlink/blob/master/hardlink.c
=============================================================*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
if (argc != 3){
	fprintf(stderr,"usage: hardlink source destination\n");
}
if(link(argv[1], argv[2])!=0)
	perror("링크 생성 실패");
exit(0);
}
