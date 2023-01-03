//Bankers algorithm
#include<stdio.h>
int main()
{
  // p0,p1,p2,p3,p4 are the process names here
int n,m,i,j,l,k,a,b;
n=5;//Number of process
m=4;// Number of resources
int need[n][m];
//allocation matrix
int alloc[5][4]={{0,0,1,2},//p0
  {1,0,0,0},
   {1,3,5,4},
   {0,6,3,2},
   {0,0,1,4}};

// max matrix
int max[5][4] = {{0,0,1,2},
  
   {1,7,5,0},
   {2,3,5,6},
   {0,6,5,2},
   {0,6,5,6}};
printf("Allocation\t   Max\t\tNeed(Max-Allocation)");
printf("\n");
 for(a=0;a<n;a++)
{
   for(b=0;b<m;b++)
      printf("%d ",alloc[a][b]);
    printf("\t");
   for(b=0;b<m;b++)
      printf("%d ",max[a][b]);
    printf("\t");
   for(b=0;b<m;b++)
    {
      need[a][b] = max [a][b]-alloc[a][b];
      printf("%d ",need[a][b]);
    }
  printf("\n");
}  
   

int avail[4]=  {1,5,2,0};//available resources
 int f[n],ans[n],ind=0;
for(k=0;k<n;k++)
{
  f[k]=0;
}
printf("\nAvail matrix\n");
int y=0;
for(k=0;k<5;k++)
{
  for(i=0;i<n;i++)
{
   if(f[i]==0)
{
  int flag=0;
  for(j=0;j<m;j++)
{
  if (need[i][j]>avail[j])
{
    flag=1;
    break;
}
}
if(flag==0)
{
  ans[ind++]=i;
  for(y=0;y<m;y++)
  avail[y]+=alloc[i][y];
  f[i]=1;
}
}
}
}
for(i=0;i<m;i++)
  printf("%d  ",avail[i]);
printf("\n\nFollowing is the safe sequence\n");
for(i=0;i<n-1;i++)
  printf("p%d->",ans[i]);
printf("p%d",ans[n-1]);
printf("\n");
return (0);
}
 


