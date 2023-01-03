/*Q2)2. Write a C program to accept the number of process and resources and find the need matrix content and display it. */
//no process=5
//no of resources=3
//no of instance 1=10
//-------------- 2=5
//-------------- 3=7

/* allocation matrix= 0 1 0
		      2 0 0
		      3 0 2
		      2 1 1
		      0 0 2
		      
   max matrix = 7 5 3
		3 2 2
		9 0 2
		2 2 2
		4 3 3

   avail matrix = 3 3 2*/ 
#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,m,i,j,k,a,b;
int alloc[10][10],max[10][10],need[10][10],avail[10][10];
int work[10];  //available resources
int total_resources[10],temp[10];

printf("Enter no of processes: ");
scanf("%d",&n);

printf("Enter no of resources: ");
scanf("%d",&m);

for(i=0;i<m;i++)
{
   printf("Enter no. of instances of resource %d: \n",i+1);
   scanf("%d",&total_resources[i]);
}

printf("Enter allocation matrix\n");
for (i=0;i<n;i++) {
  for (j=0;j<m;j++) {
 	scanf("%d",&alloc[i][j]);
   }
}

printf("Enter MAX matrix\n");
for (i=0;i<n;i++) {
   for (j=0;j<m;j++) {
 	scanf("%d",&max[i][j]);
   }
}
printf("Enter Avail matrix\n");

   for (j=0;j<m;j++) {
 	scanf("%d",&avail[i][j]);

}

/*for(i=0;i<m;i++) // Initialize temp to 0
   temp[i]=0;

for(j=0;j<m;j++)
{
  for(i=0;i<n;i++)
	{    
	temp[j]+=alloc[i];//columwise addition of allocation matrix
	}
}
printf("TemP array is ....\n");
for(i=0;i<m;i++) // Initialize temp to 0
   printf("%d  ",temp[i]);

    

for(i=0;i<m;i++)
   work[i]=total_resources[i]-temp[i];*/

printf("Allocation Matrix is .....\n");
for (i=0;i<n;i++)
{
   for (j=0;j<m;j++)
 	printf("%d  ",alloc[i][j]);
    printf("\n");
}

printf("Max Matrix is .....\n");
for (i=0;i<n;i++)
{
   for (j=0;j<m;j++)
 	printf("%d  ",max[i][j]);
    printf("\n");
}
for(i=0;i<n;i++)
{
	  for(j=0;j<m;j++)
	  {
		need[i][j]=max[i][j]-alloc[i][j];
	  }
	  printf("\n");
}



printf("Need Matrix is ....\n");
	for(i=0;i<n;i++)
	{
	  for(j=0;j<m;j++)
	  {
		printf("%d\t",need[i][j] );
	  }
	  printf("\n");
	}
}
