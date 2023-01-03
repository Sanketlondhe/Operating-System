/*
ASSIGNMENT 2 - SET-A
1. Write the simulation program using FCFS. 
The arrival time and first CPU bursts of different jobs should be input to the system. 
Assume the fixed I/O waiting time (2 units). The next CPU burst should be generated using random function. 
The output should give the Gantt chart, Turnaround Time and Waiting time for each process and average times.
*/

//INPUT:------
// Arriavl time = 1,2,3,4,5
// Burst time = 2
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
//arrival time = 0,1,2,3,4
//burst time  = 2 0r anything we can give
int main()
{
	int AT[10];//={0,1,2,3,4};
	int BT[10];//={2,6,4,9,12};
	int WT[10],TT[10],i,j,n;
    int burst=0,cmpl_T;
    float Avg_WT,Avg_TT,Total=0;
    time_t t;
    printf("Enter number of the process\n");
    scanf("%d",&n);
    printf("Enter Arrival time of the processess\n");
    printf("AT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&AT[i]);
    }
    /*printf("Enter the Burst time of processess\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&BT[i]);
    }*/
  
   printf("Enter the Burst time of first process\n");
    scanf("%d",&BT[0]);
   /*/* Intializes random number generator */
       srand((unsigned)time(&t));

   /* For Burst time generate n random numbers from 0 to 10 */
    for( i = 1 ; i < n ; i++ ) 
         BT[i]= rand() % 10;
    printf("Burst Times generated using random funtion are...\n");
    for (i=0;i<n;i++)
       printf("%d\n",BT[i]);
    
    // Logic for calculating Waiting time
    for(int i=0;i<n;i++)
    {
        if(i==0)
            WT[i]=AT[i];
        else
            WT[i]=burst-AT[i];
        burst+=BT[i];
        Total+=WT[i];
    }
    Avg_WT=Total/n;
    
    // Logic for calculating Turn around time
    cmpl_T=0;
    Total=0;
    char ch ='-';
    printf(" ");
    for(i=0;i<n*8;i++)
    {
           printf("%c",ch);
    }
    printf("\n");
    for(i=0;i<n+1;i++)
    {
           printf("|       ");
    }
    printf("\n");
    for(i=0;i<n+1;i++)
    {
           printf("|       ");
    }
    printf("\n");
    printf(" ");
    for(i=0;i<n*8;i++)
    {
           printf("%c",ch);
    }
    printf("\n0  \t");
    for(i=0;i<n;i++)
    {
        cmpl_T+=BT[i];
        TT[i]=cmpl_T-AT[i];
        Total+=TT[i];
        printf("%d\t",cmpl_T);
     }
    Avg_TT=Total/n;
    
    // printing of outputs
    
    printf("\nProcess ,Waiting_time ,TurnA_time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",i+1,WT[i],TT[i]);
    }
    printf("Average waiting time is : %f\n",Avg_WT);
    printf("Average turn around time is : %f\n",Avg_TT);
    return 0;
} 
