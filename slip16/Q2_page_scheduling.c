/*ASSIGNMENT-4-SET-B-Q.1
 Write the simulation program to implement demand paging and show the page scheduling and total number of page faults for the following given page reference string. Give input n as the number of memory frames.
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
i. Implement OPT

*/#include<stdio.h>
int n=16,nf;//n is length of reference string 
int in[20]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};//reference string 
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
 
 
 void optimal()
{
    initialize();
    int near[50];
    for(i=0; i<n; i++)
    {
         printf("\nFor %d :",in[i]);
 
        if(isHit(in[i])==0)
        {
            for(j=0; j<nf; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i; k<n; k++)
                {
                    if(pg==in[k])
                    {
                        near[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
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
            optimal();
}
