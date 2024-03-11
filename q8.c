#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>

jmp_buf jump_buffer;

void handl(int sig)
{
	printf("ERROR!.. Division by 0");
	longjmp(jump_buffer,1);
}

int main()
{

if((SIGFPE,handl)==SIG_ERR)
	{perror("Error in setting up the signal handler!");
	exit(1);}
float a,b, result;
if(setjmp(jump_buffer)==0)
{

printf("Enter the value of a: ");
scanf("%f",&a);

while(1)

	{
printf("Enter the value of b: ");
scanf("%f",&b);
	if(b!=0){
		result = a/b;
		printf("Result = %f\n", result);
		break;}
	}
}
	return 0;
}
