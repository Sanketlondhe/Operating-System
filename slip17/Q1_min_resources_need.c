/*SET A
1. Write the program to calculate minimum number of resources needed to avoid deadlock.
*/
/*Given: A system has R identical resources, P processes competing for them and N is the maximum need of each process. The task is to find the minimum number of Resources required So that deadlock will never occur. 
Formula: 
R >= P * (N - 1) + 1 
Example:
Input : P = 3, N = 4
Output : R >= 10

Input : P = 7, N = 2
Output : R >= 8 
*/

#include <stdio.h>

// function that calculates the minimum no. of resources
int Resources(int p, int n)
{
	int r = 0;

    r = p * (n - 1) + 1;//Condition so that deadlock will not    //occur

	return r;
}
// Driver code
int main()
{

    int process,need;
    printf("Enter the no of process and max need of every process\n");
    scanf("%d%d",&process,&need);

    printf("R >= %d",Resources(process, need));
    return 0;
}

