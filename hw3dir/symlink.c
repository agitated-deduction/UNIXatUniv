/*===========================================================
* 파 일	:symlink.c
* 기 능	: ln -s
* 개발자 : 201521672 박소연
* 날 짜	: 1차 개발: 2018-03-27
* 참 고	: 시스템 소프트웨어 실습교재
=============================================================*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
if(symlink(argv[1], argv[2]) == -1){
	printf("symlink failed\n");
	exit(1);
}
printf("link %s to %s\n", argv[1], argv[2]);
exit(0);
}
