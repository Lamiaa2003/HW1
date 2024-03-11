#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

volatile int aborted = 0;

void handl(int sig)
{
	if(sig == SIGINT){
		aborted = 1;
		printf("\nLaunch aborted!\n");
		exit(0);}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{printf("\nERROR! arguments are less than 2\n");
	exit(1);
	}
	
	if(argc > 2)
	{printf("\nERROR! arguments are more than 2\n");
	exit(1);
	}

	int count = atoi (argv[1]);
	signal(SIGINT,handl);
	printf("\nCount is initiated for %d seconds\n",count);
	for( int i=0; i<count; i++){
		if (aborted)
			return 0;
	printf("\nT+%d seconds\n ",i);
	sleep(1);
	}
	printf("\nLaunch is initiated!\n");
	return 0 ; 
}
