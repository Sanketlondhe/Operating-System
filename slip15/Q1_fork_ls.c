#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int f;
	char *binaryPath="/bin/ls";
	char *arg1 ="-lh";
	char *arg2 ="/home";
	printf("Creating a child process with fork ....\n");
	fork();
	sleep(5);
	printf("Parent process is sleeping for 5 sec....");
	execl(binaryPath,binaryPath,arg1,arg2,NULL);
	printf("Sleep is now over \n");
	return 0;
}

