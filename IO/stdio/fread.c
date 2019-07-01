#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024

int main(int argc, char* argv[])
{
	FILE *fps, *fpd;
	int buf[BUFSIZE];
	int n;
	fps = fopen(argv[1], "r");
	if(fps == NULL){
		perror("fopen: ");
		exit(1);
	}

	fpd = fopen(argv[2], "w");
	if(fpd == NULL){
		close(fps);
		perror("fopen: ");
		exit(1);
	}
	while((n=fread(buf,1, BUFSIZE, fps))>0){
		fwrite(buf,1,n, fpd);
	}


	fclose(fps);
	fclose(fpd);
	exit(0);
}
