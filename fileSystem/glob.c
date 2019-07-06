#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>

#define PAT "/etc/a*.conf"

static int arrFunc(const char* errpath, int eerrno)
{
	puts(errpath);
	fprintf(stderr,"Error message:%s\n",strerror(eerrno));
	return 0;
}
int main()
{
	glob_t globres;
	int err, i;
	err = glob(PAT, 0, arrFunc, &globres);
	if(err)
	{
		printf("error code=%d\n", err);
		exit(1);
	}
	for(i=0; i<globres.gl_pathc; i++)
		puts(globres.gl_pathv[i]);
	globfree(&globres);
	exit(0);
}
