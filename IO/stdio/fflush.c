#include <stdio.h>
#include <stdlib.h>

/*
*in most cases, buffer is benefit
* line buffer: \n flush, fource flush(stdout)
* full buffer: full flush, fource flush
* no buffer: stderr
*
 **/
int main()
{
	int i;
	//printf("before while\n");
	printf("before while");
	fflush(stdout);
	while(1);
	printf("after while");
	exit(0);
}
