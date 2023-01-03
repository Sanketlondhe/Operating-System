/*
Write the simulation program using SJF(NON preemptive).
The arrival time and first CPU bursts of different jobs should be
input to the system.The Assume the fixed I/O waiting time (2 units).
The next CPU burst should be generated using random function.
The output should give the Gantt chart,
Turnaround Time and Waiting time for each process and average times
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int AT[20]={1,3,6,7,9},BT[20];//={7,3,2,10,8};
char ch ='-';
int CT[20],TT[20],p[20]={1,2,3,4,5},wt[20],tat[20],temp_BT[20];
int flag[20], first_time=1,finish = 0, shortest_job_pos;
int i,j,x,n=5,pos,temp,cmpl_T;
float Total_TT=0,Total_WT=0;
int find_min_AT(int a[]);
int find_min_BT(int a[]);
int SJF(int bt[])
{
    int min_pos,k;
    if(first_time == 1)
    {
       shortest_job_pos = find_min_AT(AT);
       x=cmpl_T=AT[shortest_job_pos];
       printf("======SJF Non Preemptive====\n");
       printf("\n Gantt Chart    \n");
       printf(" ");
       for(i=0;i<= (n-1)*8;i++)
	printf("%c",ch);

       printf("\n");

       for(i=0;i<n+1;i++)
	  printf("|      ");

       printf("\n");
       printf("|" );
     }
    for(i=0;i<n;i++)
    {
      if( first_time ==1 && flag[shortest_job_pos] == 0)// first job
       {
		cmpl_T += BT[shortest_job_pos];
		CT[shortest_job_pos]=cmpl_T;
		TT[shortest_job_pos]=cmpl_T-AT[shortest_job_pos];
		Total_TT+=TT[i];
		//printf("%d\t",cmpl_T);
		flag[shortest_job_pos]= 1;
		first_time=0;
       }
       else //if(first_time == 0),now it is not first job,find the shortest job
       {
	  for ( i= 0;i<n; i++)
	  {
	   if( AT[i] <= cmpl_T && flag[i]==0)
	       temp_BT[i]= BT[i];
	  }
	    for( i=0;i<=cmpl_T ; i++)
	    {
		shortest_job_pos = find_min_BT(temp_BT);
		cmpl_T += temp_BT[shortest_job_pos];
		CT[shortest_job_pos]=cmpl_T;
		TT[shortest_job_pos]=cmpl_T-AT[shortest_job_pos];
		wt[shortest_job_pos]=TT[shortest_job_pos]-temp_BT[shortest_job_pos];
		Total_TT+=TT[shortest_job_pos];
		break;
	   }      // end of for
	 }// end of else if
	 for(k=0;k<n;k++)
	    temp_BT[k]=0;
	 printf("  P%d  |",p[shortest_job_pos]);
	 finish++;
	 if (finish == n)
	    return 0;
       } //end of for
//}//end of while
return k;
}
//---------------------------------------------------------
int sort_CT()
{
int i,j,temp;
for(i=0;i<n;i++)
    {
	for(j=i+1;j<n;j++)
	{
	    if(CT[j] < CT[i])
	     {
		temp=CT[i];
		CT[i]=CT[j];
		CT[j]=temp;
	     }
	}
}
}
//----------------------------------------------------------------
int find_min_AT(int a[])
 {
    int i, minimum, minimum_pos;
    minimum= a[0];
    //first_time = 1;
    for ( i=0 ;i<n ; i++)
    {
     if (a[i] < minimum  && flag[i] != 1)
	{
	minimum = a[i];
	minimum_pos= i;
	}
    }
    return minimum_pos;
}
//-----------------------------------------------------------------
int find_min_BT(int a[])
 {
    int i,j,minimum, minimum_pos;
    for(i=0;i<n ;i++)
     if ( a[i] !=0)
     {
	  minimum= a[i];
	  break;
     }
    for ( j=i+1;j<n; j++)
     if (a[j] < minimum  && flag[j] != 1)
	minimum = a[j];
    flag[i]= 1;
    return i;
}
//----------------------------------------------------------------------
 int main()
{
    int k,min,pos,p_id,CT_1[20];
    float avg_wt,avg_tat;
    time_t t;

    
    for(i=0;i<n;i++)
    flag[i] = 0;
    /*printf("Enter number of process:");
    scanf("%d",&n);
      */
 /* printf("Enter Arrival time of the processess\n");
    printf("AT\n");
    for(i=0;i<n;i++)
    {
	scanf("%d",&AT[i]);
    }*/
    printf("Enter the Burst time of first process\n");
    scanf("%d",&BT[0]);

  /*printf("Enter the Burst time of the process\n");
   for(i=0;i<n;i++)
    {
	scanf("%d",&BT[i]);
    }*/
   /* Intializes random number generator */
     srand((unsigned) time(&t));

   /* For Burst time generate n random numbers from 0 to 10 */
    for( i = 1 ; i < n ; i++ )
	 BT[i]= rand() % 10;
    printf("Burst Times generated using random funtion are...\n");
    for (i=0;i<n;i++)
       printf("%d\n",BT[i]);
    

   //sorting of burst times
    for(i=0;i<n;i++)
    {
	pos=i;
	for(j=i+1;j<n;j++)
	{
	    if(BT[j]<BT[pos])
		pos=j;
	}

	temp=BT[i];
	BT[i]=BT[pos];
	BT[pos]=temp;

	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;

	temp=AT[i];
	AT[i]=AT[pos];
	AT[pos]=temp;

    }

    cmpl_T=0;
    SJF(BT);
    printf("\n");
    printf(" ");
    for(i=0;i<= (n-1)*8;i++)
    {
	   printf("%c",ch);
    }
    printf("\n%d   ",x);
    for(i=0;i<n;i++)
      CT_1[i]= CT[i];
    sort_CT();
    for (i=0;i<n;i++)
    {
	  printf("   %d  ",CT[i]);
    }
    printf("\n\n\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\t\n");
    for(i=0;i<n;i++)
    {
	printf(" P%d\t  %d\t\t%d\t\t    %d\t\t  %d\t\t%d\n",i+1,AT[i],BT[i],CT_1[i],TT[i],wt[i]);
    }
    for(i=0;i<n;i++)
       Total_WT+= wt[i];
    avg_wt=(float)Total_WT/n;
    printf("\nAverage Waiting Time=%.1f",avg_wt);

    for(i=0;i<n;i++)
       Total_TT+= TT[i];
    avg_tat=(float)Total_TT/n;
    printf("\nAverage Turnaround Time=%.1f",avg_tat);
    return 0;
}
