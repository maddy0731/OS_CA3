#include<stdio.h>
struct process
{
int pro_name;
int arrT,burT,waiturnT,turnT,priority,burTcopy;
}queue1[10],queue2[10];
void main()
{
struct process temp;
int i,time=0,t1,t2,bu_t=0,largest,totalProcess,count=0,k,pf2=0,totalProcess2,n,pos,j,flag=0,y;
float wait_time=0,turnaround_time= 0,average_waiting_time,average_turnaround_time;
printf("\nEnter Total Number of Processes:\t");
scanf("%d",&totalProcess);
n=totalProcess;
for(i=0;i<totalProcess;i++)
{
printf("\nEnter Process name:-");
scanf("%d",&queue1[i].pro_name);
printf("\nEnter Details For processor %d:\n",queue1[i].pro_name);
printf("Enter Arrival Time:-");
scanf("%d",&queue1[i].arrT);
printf("Enter Burst Time:-");
scanf("%d",&queue1[i].burT);
queue1[i].burTcopy=queue1[i].burT;
printf("Enter Priority:\t");
scanf("%d",&queue1[i].priority);
}
printf("\nEnter Time Quantum for Fixed priority queue:-");
scanf("%d",&t1);
printf("\nEnter Time Quantum for Round Robin queue:-");
scanf("%d",&t2);
printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
for(i=0;i<totalProcess;i++)
{
pos=i;
for(j=i+1;j<totalProcess;j++)
{
if(queue1[j].arrT<queue1[pos].arrT)
pos=j;
}
temp=queue1[i];
queue1[i]=queue1[pos];
queue1[pos]=temp;
}
time=queue1[0].arrT;
for(i=0;totalProcess!=0;i++)
{
while(count!=t1)
{
count++;
if(queue1[i].arrT<=time)
{
for(j=i+1;j<totalProcess;j++)
{
if(queue1[j].arrT==time&&queue1[j].priority<queue1[i].priority)
{
queue2[pf2]=queue1[i];
pf2++;
for(k=i;k<totalProcess-1;k++)
queue1[k]=queue1[k+1];
totalProcess--;
count=0;
i=j-1;
j--;
}
}
}
time++;
