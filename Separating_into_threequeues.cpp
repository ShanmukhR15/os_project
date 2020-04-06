#include<stdio.h>
int arrival_time1[30],arrival_time2[30],arrival_time3[30];
int burst_time1[30],burst_time2[30],burst_time3[30];
//j is the 1st QUEUE.It keeps a count on the total elements in the queue.
//k is second QUEUE.It keeps a count on the total elements in the queue.
//l is third QUEUE.It keeps a count on the total elements in the queue.
int main()
{
	printf("Entering priority from 1 to 5 goes to first(j) queue and performs\n ROUND ROBIN Algorithm\n");
	printf("Entering priority from 6 to 10 goes to Second(k) queue and performs\n PRIORITY Algorithm\n");
	printf("Entering priority from 11 to 15 goes to Third(l) queue and performs\n FIRST_COME_FIRST_SERVE Algorithm\n");
	int n,i,at[30],bt[30],p[30],j=0,k=0,l=0;
	printf("Enter the no. of process you want to enter\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process[%d]\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		if(p[i]>=1&&p[i]<=5)
		{
			printf("Process[%d] belongs to Queue 1\n",i+1);
			arrival_time1[j]=at[i];
			burst_time1[j]=bt[i];
			j++;
		}
		
		else if(p[i]>=6&&p[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrival_time2[k]=at[i];
			burst_time2[k]=bt[i];
			k++;
		}
		
		else if(p[i]>=11&&p[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			arrival_time3[l]=at[i];
			burst_time3[l]=bt[i];
			l++;
		}
	}
	return 0;
}
