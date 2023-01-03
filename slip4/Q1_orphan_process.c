#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int pid=fork();
	if(pid>0)
	{
	 printf("in parent process\n");
	 printf("PID: %d\n",getpid());
	}
	else if(pid==0)
	{
	 sleep(10);
	 printf("\nin child process");
	 printf("\nPID: %d",getpid());
	 printf("\nChild PID: %d",getpid());
	}
	return 0;
}
