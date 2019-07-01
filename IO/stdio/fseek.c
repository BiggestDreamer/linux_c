#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int count = 0;
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		close(fp);
		perror("fopen: ");
		exit(1);
	}
	/*
	while(fgetc(fp) != EOF)
	{
		count++;
	}

	printf("count = %d\n", count);
	*/
	fseek(fp, 0, SEEK_END);
	printf("%ld\n", ftell(fp));
	fclose(fp);
	exit(0);
}
