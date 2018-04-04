/*============================================================
 * 파일 : getUinfo.c
 * 기능 : 사용자의 정보를 읽어온다.
 * 작성자 : 201521672 박소연
 * 날짜 : 2018-03-30
 * ===========================================================*/
#include<stdio.h>
#include<unistd.h>
#include<pwd.h>
#include<sys/types.h>
#include<time.h>

int getUinfo(void){
	struct passwd *pw;
	uid_t uid;
	time_t time_now;
	
	uid = getuid();
	pw = getpwuid(uid);

	printf("My information = name: %s, uid: %d, gid: %d, home: %s\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir);

	endpwent();
	//time(&time_now);
}
