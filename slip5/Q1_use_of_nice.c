#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int pid,retnice;
	printf("press del to stop process\n");
	pid=fork();
		for(;;)
		{
		 if(pid==0)
		 {
		  retnice=nice(-5);
		  printf("Child gets higher CPU priority %d \n",retnice);
		  sleep(1);
		 }
		 else
		 {
		  retnice=nice(4);
		  printf("Parent gets higher lower CPU priority %d \n",retnice);
		  sleep(1);
		 }
		}
}
