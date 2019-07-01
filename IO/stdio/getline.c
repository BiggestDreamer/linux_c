#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *fp;
	char *linebuf;
	size_t linesize;
	if(argc < 2)
	{
		fprintf(stderr, "usage...\n");
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen: ");
		exit(1);
	}
	//these two lines are very important!!!
	linebuf = NULL;
	linesize = 0;


	while(1)
	{
		if(getline(&linebuf, &linesize, fp)<0)
		{
			break;
		}
		printf("%d\n", strlen(linebuf));
	}


	free(linebuf);
	fclose(fp);
	exit(0);
}
