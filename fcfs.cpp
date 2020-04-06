#include<stdio.h>
int arrival_time1[30],arrival_time2[30],priority2[30],process2[30],arrival_time3[30];
int burst_time1[30],burst_time2[30],burst_time3[30];
int Total=0,t1=0,t2=0,t3=0;
int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0;
int p,waiting_time3[30],turnaround_time3[30];
float avg_waiting_time3=0.0,avg_turnaround_time3=0.0;

void fcfs()
{
	waiting_time3[0] = 0;   
    for(i=1;i<l;i++)
    {
        waiting_time3[i] = 0;
        for(p=0;p<i;p++)
        {
            waiting_time3[i]=waiting_time3[i]+burst_time3[p];
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<l;i++)
    {
        turnaround_time3[i]=burst_time3[i]+waiting_time3[i];
        avg_waiting_time3=avg_waiting_time3+waiting_time3[i];
        avg_turnaround_time3=avg_turnaround_time3+turnaround_time3[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,burst_time3[i],waiting_time3[i],turnaround_time3[i]);
    }
    avg_waiting_time3=avg_waiting_time3/l;
    avg_turnaround_time3=avg_turnaround_time3/l;
    printf("\nAverage Waiting Time=%f",avg_waiting_time3);
    printf("\nAverage Turnaround Time=%f",avg_turnaround_time3);
    for(i=0;i<l;i++)
    {
    	while(burst_time3[i]!=0)
    	{
    		if(burst_time3[i]>10)
    		{
				printf("\nProcess[%d] of Queue3 is running for 10 units",i+1);
				burst_time3[i]=burst_time3[i]-10;
			}
			else if(burst_time3[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,burst_time3[i]);
				burst_time3[i]=0;
			}
		}
	}
}
int main()
{ 
	printf("Entering priority from 1 to 5 goes to first(j) queue and performs\n ROUND ROBIN Algorithm\n");
	printf("Entering priority from 1 to 5 goes to Second(k) queue and performs\n PRIORITY Algorithm\n");
	printf("Entering priority from 1 to 5 goes to Third(l) queue and performs\n FIRST_COME_FIRST_SERVE Algorithm\n");
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
		scanf("%d",&pr[i]);
		Total=Total+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("\n\nProcess[%d] belongs to Queue 1\n",i+1);
			arrival_time1[j]=at[i];
			burst_time1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrival_time2[k]=at[i];
			burst_time2[k]=bt[i];
			priority2[k]=pr[i];
			process2[k]=k+1;
			k++;
			t2=t2+bt[i];
		}
		
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n\n\n\n",i+1);
			arrival_time3[l]=at[i];
			burst_time3[l]=bt[i];
			l++;
			t3=t3+bt[i];
		}
	}
	fcfs();
	return 0;
}
