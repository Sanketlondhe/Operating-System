/* ASSIGNMENT 2 SET B
Q.2 Write the program to simulate Non-preemptive Priority scheduling.
The arrival time andfirst CPU-burst and priority for different n
number of processes should be input to thealgorithm.
Assume the fixed IO waiting time (2 units).
The next CPU-burst should be generated randomly.
The output should give Gantt chart, turnaround time and waiting
time for each process. Also find the average waiting time and turnaround time.
*/

//INPUT-------
//no of processes = 7
// Arrival time= 0,2,1,4,6,5,7
// Priority  =  2,6,3,5,7,4,10
// burst time = 5
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
    
    int p[20],wt[20],CT[20], TT[20],RT[20],i,j,n;
    int Total_wt=0,Total_TT=0,pos,temp,cmpl_T;
    float avg_wt,avg_tat;
    time_t t;
    char ch ='-';
	
	int at[20];//={0,2,1,4,6,5,7};
	int bt[20];//={3,5,4,2,9,4,10};
	int pr[20];//={2,6,3,5,7,4,10};
	

void main()
{
    
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    for(i=0; i< n; i++)
      p[i]=i+1;

    printf("Enter Arrival time of the processess\n");
    printf("AT\n");
    for(i=0;i<n;i++)
    {
	scanf("%d",&at[i]);
    }
   /* printf("Enter Burst time of the processess\n");
    printf("BT\n");
    for(i=0;i<n;i++)
    {
	scanf("%d",&bt[i]);
    }*/

    printf("Enter Priority of the processess\n");
    for(i=0;i<n;i++)
    {
	scanf("%d",&pr[i]);
    }

    printf("Enter the Burst time of first process\n");
    scanf("%d",&bt[0]);
    
   // Intializes random number generator */
     srand((unsigned) time(&t));

   /* For Burst time generate n random numbers from 0 to 10 */
    for( i = 1 ; i < n ; i++ )
	 bt[i]= rand() % 10;
    printf("Burst Times generated using random funtion are...\n");
    for (i=0;i<n;i++)
       printf("%d\n",bt[i]);
   

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
	pos=i;
	for(j=i+1;j<n;j++)
	{
	    if(pr[j]<pr[pos])
		pos=j;
	}
	temp=at[i];
	at[i]=at[pos];
	at[pos]=temp;

	temp=pr[i];
	pr[i]=pr[pos];
	pr[pos]=temp;

	temp=bt[i];
	bt[i]=bt[pos];
	bt[pos]=temp;

	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
    }

    wt[0]=0; //waiting time for first process is zero
    cmpl_T=0;
    Total_wt=0;
    Total_TT=0;

   // Printing Gantt Chart
    printf("\n        =======Non Preemptive Priority Scheduling========\n");
    printf("\n Gantt Chart    \n");
       printf(" ");
       for(i=0;i<= n*8;i++)
	   printf("%c",ch);

       printf("\n");
       printf("|");

       for(i=0;i<n;i++)
	printf("  P%d   |",p[i]);
       printf("\n");
      // printf("|" );
    for(i=0;i<n;i++)
    {
	cmpl_T+=bt[i];
	CT[i]=cmpl_T;
	TT[i]=CT[i]-at[i];
	wt[i]= TT[i] - bt[i];
	RT[i]= wt[i] + at[i];
	Total_wt+=wt[i];
	Total_TT+=TT[i];
	//printf("%d\t",cmpl_T);
     }
    printf(" ");
    for(i=0;i<n*8;i++)
    {
	   printf("%c",ch);
    }
    printf("\n0");
    for(i=0;i<n;i++)
      printf("%8d",CT[i]);

    printf("\n\nPID  Priority    AT\t  BT\t  CT\t  TT\t  WT\t  RT\n");
    printf("-------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
	printf("\nP%d\t  %d\t  %d\t  %d\t  %d\t  %d\t  %d\t  %d",p[i],pr[i],at[i],bt[i],CT[i],TT[i],wt[i],RT[i]);
    }

    avg_wt=Total_wt/n; //average waiting time
    avg_tat=Total_TT/n;//average turnaround time
    printf("\n\nAverage Waiting Time=%.1f",avg_wt);
    printf("\nAverage Turnaround Time=%.1f\n",avg_tat);
    
}
