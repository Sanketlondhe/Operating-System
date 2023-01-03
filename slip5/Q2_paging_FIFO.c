/* ASSIGNMENT 4 Set A
Q.2. Write the simulation program to implement demand paging and show the page scheduling and total number of page faults for the following given page reference string. Give input n as the number of memory frames.
Reference String :3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
i. Implement FIFO*/
#include<stdio.h>
int n=15,nf;//n is length of reference string
int in[20]={3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};//Reference String
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;

void getData()
{
	printf("\nEnter no of frames:");
	scanf("%d",&nf);
}

void initialize()
{
	pgfaultcnt=0;
	for(i=0; i<nf; i++)
		p[i]=9999;
}

int isHit(int data)
{
	hit=0;
	for(j=0; j<nf; j++)
	{
		if(p[j]==data)
		{
			hit=1;
			break;
		}
	}
	return hit;
}

int getHitIndex(int data)
{
	int hitind;
	for(k=0; k<nf; k++)
	{
		if(p[k]==data)
		{
			hitind=k;
			break;
		}
	}
	return hitind;
}

void dispPages()
{
	for (k=0; k<nf; k++)
	{
		if(p[k]!=9999)
			printf(" %d",p[k]);
	}
}

void dispPgFaultCnt()
{
	printf("\nTotal no of page faults:%d",pgfaultcnt);
}

void fifo()
{
	initialize();
	for(i=0; i<n; i++)
	{
		printf("\nFor %d :",in[i]);
		
		if(isHit(in[i])==0)
		{
			for(k=0; k<nf-1; k++)
			p[k]=p[k+1];

		p[k]=in[i];
		pgfaultcnt++;
		dispPages();
	}
	else
		printf("No page fault");
	}
	dispPgFaultCnt();
}


int main()
{
        getData();
        fifo();
}
 

