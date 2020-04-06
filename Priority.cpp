#include<stdio.h>
int arrival_time1[30],arrival_time2[30],priority2[30],process2[30],arrival_time3[30];
int burst_time1[30],burst_time2[30],burst_time3[30];

int Total=0,t1=0,t2=0,t3=0;

int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0;
//j is the 1st QUEUE.It keeps a count on the total elements in the queue.
//k is second QUEUE.It keeps a count on the total elements in the queue.
//l is third QUEUE.It keeps a count on the total elements in the queue.

int position,q,temp1,sum=0,waiting_time2[30],turnaround_time2[30];
float avg_waiting_time2,avg_turnaround_time2;
void priority()
{
	for(i=0;i<k;i++)
    {
        position=i;
        for(q=i+1;q<k;q++)
        {
            if(priority2[q]<priority2[position])
            {
                position=q;
            }
        }
        temp1=priority2[i];
        priority2[i]=priority2[position];
        priority2[position]=temp1; 
        
        temp1=burst_time2[i];
        burst_time2[i]=burst_time2[position];
        burst_time2[position]=temp1;
        
        temp1=process2[i];
        process2[i]=process2[position];
        process2[position]=temp1;
    }
    waiting_time2[0]=0;
    for(i=1;i<k;i++)
    {
        waiting_time2[i]=0;
        for(q=0;q<i;q++)
        {
            waiting_time2[i]=waiting_time2[i]+burst_time2[q];
        }
        sum=sum+waiting_time2[i];
    }
    avg_waiting_time2=sum/k;
    sum=0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0;i<k;i++)
    {
    	turnaround_time2[i]=burst_time2[i]+waiting_time2[i];
        sum=sum+turnaround_time2[i];
        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",process2[i],burst_time2[i],waiting_time2[i],turnaround_time2[i]);
    }
    avg_turnaround_time2=sum/k;
    printf("\nAverage Waiting Time:\t%f",avg_waiting_time2);
    printf("\nAverage Turnaround Time:\t%f\n",avg_turnaround_time2);
    
    for(i=0;i<k;i++)
    {
    	while(burst_time2[i]!=0)
    	{
    		if(burst_time2[i]>10)
    		{
				printf("\nProcess[%d] of Queue2 is running for 10 units",i+1);
				burst_time2[i]=burst_time2[i]-10;
			}
			else if(burst_time2[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,burst_time2[i]);
				burst_time2[i]=0;
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
	priority();
	return 0;
}
