#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
 pid_t pid=fork();
 if(pid<0)
 {
  printf("ERROR");
  exit(1);
 }
 else if(pid==0)
 {
  printf("Hello World\tPID is %d\n",getpid());
  exit(0);
 }
 else
 {
  printf("Hiii\tPID is %d\n",getpid());
  exit(1);
 }
 return 0;
}
