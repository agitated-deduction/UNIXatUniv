/* ----------------------------------------------------------------------------------------------------
 *  파일		: errheader.h
 *  기능		: 오류 처리
 	코드 출처: UNIX 고급 프로그래밍 제 3판-Stevens, Rago(appendix B)
 *----------------------------------------------------------------------------------------------------*/
#include <errno.h>
#include <stdarg.h>
#include "apue.h"

static void err_doit(int, int, const char *, va_list);

void err_ret(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

void err_sys(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_cont(int error, const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, error, fmt, ap);
	va_end(ap);
}

void err_exit(int error, const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, error, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_dump(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	abort();
	exit(1);
}

void err_msg(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);
}

void err_quit(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);
	exit(1);
}

static void err_doit(int errnoflag, int error, const char *fmt, va_list ap){
	char buf[4096];
	vsnprintf(buf, 4095, fmt, ap);
	if(errnoflag)
		snprintf(buf+strlen(buf), 4095-strlen(buf)-1, ": %s", strerror(error));
	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(NULL);
}
