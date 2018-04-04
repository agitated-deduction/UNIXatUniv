/*======================================================================
 * 파일 : main.c
 * 기능 : 파일을 관리하는 함수들을 포함한다. 옵션을 설정하고 호출한다.
 		-g: getUinfo
 		-f: findSfile
 		-p: printFinfo
 		-c: changePerm
 * 작성자: 201521672 박소연
 * 날짜 : 2018-04-02
 * 참고 : https://www.experts-exchange.com/questions/21652253/Character-string-to-mode-t-conversion.html
 *======================================================================*/
#include<stdio.h>


int main(int argc, char *argv[]){
	if( argc <2){
		fprintf(stderr, "usage: ./release [option] [content]----\noptions: -g, -p, -f, -c\n");
		return 1;
	}

	if (strcmp(argv[1],"-g") == 0)getUinfo();
	if (strcmp(argv[1],"-f")==0){
		//char *tmp[] = {argv[2], argv[3]};
		findSfile(argc, argv[2], argv[3]);
	}
	if (strcmp(argv[1],"-p")==0)printFinfo();
	if (strcmp(argv[1],"-c")==0){
		//char *tmp[] = {argv[2], argv[3], argv[4], argv[5]};
		changePerm(argc, argv[2], argv[3], argv[4], argv[5]);
	}

	return 0;
}
