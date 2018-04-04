/*======================================================================
 * 파일 : printFinfo.c
 * 기능 : find.txt에 저장되어 있는 경로의 파일들에 대한 정보를 file_info.txt에 저장한다.
 * 작성자: 201521672 박소연
 * 날짜 : 2018-04-01
 *======================================================================*/
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

#define MAX_PATHNAME 4096

static void check_file_type(struct stat *);
static void check_file_permission(struct stat *);

FILE *fp2;

int printFinfo(void){
	FILE *fp = fopen("find.txt", "r");
	fp2 = fopen("file_info.txt", "w");
	char str[MAX_PATHNAME];
	struct stat buf;
	char tmp[64];

	while(1){
		fgets(str, MAX_PATHNAME, fp);
		if(feof(fp)) break;
		int len = strlen(str);
		str[len-1] = '\0';
		if(lstat(str,&buf)<0){
			fprintf(stderr,"error at lstat() %s\n",str);
			perror("lstat");
			return 1;
		}
		check_file_type(&buf);
		check_file_permission(&buf);

		fprintf(fp2,"i-node number : %ld \n", buf.st_ino);
		fprintf(fp2,"Number of hard links : %d\n", buf.st_nlink);
		fprintf(fp2,"User ID :  %d\n", buf.st_uid);
		fprintf(fp2,"Group ID : %d\n", buf.st_gid);
		fprintf(fp2,"Total Size : %ld\n", buf.st_size);
		fprintf(fp2,"Block Size : %ld\n", buf.st_blksize);
		fprintf(fp2,"Number of blocks : %ld\n\n", buf.st_blocks);
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}
static void check_file_type(struct stat *buf){
	if(S_ISREG(buf->st_mode))
		fprintf(fp2, "File Type : Recular File\n");
	else if(S_ISDIR(buf->st_mode))
		fprintf(fp2, "File Type : Directory\n");
	else if(S_ISCHR(buf->st_mode))
		fprintf(fp2, "File Type : Character Special File\n");
	else if(S_ISBLK(buf->st_mode))
		fprintf(fp2, "File Type : Block Special File\n");
	else if(S_ISFIFO(buf->st_mode))
		fprintf(fp2, "File Type : Fifo\n");
	else if(S_ISLNK(buf->st_mode))
		fprintf(fp2, "File Type : Symbolic Link\n");
	else if(S_ISSOCK(buf->st_mode))
		fprintf(fp2, "File Type : Socket\n");
	else
		fprintf(fp2, "Unknown file type\n");
}
static void check_file_permission(struct stat *buf){
	char per_buf[9]= {'-','-','-','-','-','-','-','-','-'};
	if((buf->st_mode&S_IRUSR)) per_buf[0] = 'r';
	if((buf->st_mode&S_IWUSR)) per_buf[1] = 'w';
	if((buf->st_mode&S_IXUSR)) per_buf[2] = 'x';
	if((buf->st_mode&S_IRGRP)) per_buf[3] = 'r';
	if((buf->st_mode&S_IWGRP)) per_buf[4] = 'w';
	if((buf->st_mode&S_IXGRP)) per_buf[5] = 'x';
	if((buf->st_mode&S_IROTH)) per_buf[6] = 'r';
	if((buf->st_mode&S_IWOTH)) per_buf[7] = 'w';
	if((buf->st_mode&S_IXOTH)) per_buf[8] = 'x';
	if((buf->st_mode&S_ISUID)) per_buf[2] = 's';
	if((buf->st_mode&S_ISGID)) per_buf[5] = 's';
	if((buf->st_mode&S_ISVTX)) per_buf[8] = 't';
	
	fprintf(fp2, "%s\n", per_buf);
}
