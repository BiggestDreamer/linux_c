#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define S_TEST(mode) ((mode)&S_IFMT)
static int ftype(const char* fname)
{
	struct stat statres;
	if(stat(fname,&statres)<0)
	{
		perror("stat()");
		exit(1);
	}
	/*if(S_ISREG(statres.st_mode))
		return '-';
	else if(S_ISDIR(statres.st_mode))
		return 'd';
	else if(S_ISSOCK(statres.st_mode))
		return 's';
	else
		return '?';
	*/
	if(S_TEST(statres.st_mode) == S_IFSOCK)
		return 's';
	else if(S_TEST(statres.st_mode)==S_IFLNK)
		return 'l';
	else if(S_TEST(statres.st_mode)==S_IFREG)
		return '-';
	else if(S_TEST(statres.st_mode)==S_IFDIR)
		return 'd';
	else
		return '?';
}

int main(int argc, char** argv)
{
	if(argc<2)
	{
		fprintf(stderr,"Usage...");
		exit(1);
	}
	printf("%c\n",ftype(argv[1]));
}
