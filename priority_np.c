#include<stdio.h>
#include<stdlib.h>
struct process{
	int pr,pri,at,bt,ct,tat,wt,visit;
};
int findprocess(struct process *p,int n,int t)
{
	int min=9999,index=-1;
	for(int i=0;i<n;i++)
	{
		if(p[i].at<=t && p[i].visit==0)
		{
			if(p[i].pri<min)
			{
				min=p[i].pri;
				index=i;
			}
			if(p[i].pr==min)
			{
				if(p[i].at<p[index].at)
				{
					index=i;
				}
			}
		}
	}
	return index;
}
int main()
{
	int n,t=0,ct=0,k=0;
	float atat=0,awt=0;
	struct process *p;
	p=(struct process*)malloc(n*sizeof(struct process));
	printf("enter number of process: ");
	scanf("%d",&n);
	printf("enter process,priority,arrival time,burst time: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&p[i].pr,&p[i].pri,&p[i].at,&p[i].bt);
		p[i].visit=0;
	}
	
	printf("GanttChatt: ");
	while(k<n)
	{
		int index=findprocess(p,n,t);
		if(index!=-1)
		{
			p[index].visit=1;
			p[index].ct=ct+p[index].bt;
			p[index].tat=p[index].ct-p[index].at;
			p[index].wt=p[index].tat-p[index].bt;
			t=p[index].ct;
			ct=t;
			k++;
			atat+=p[index].tat;
			awt+=p[index].wt;
			printf("P%d ",p[index].pr);
		}
		else
		{
			t=t+1;
			ct=ct+1;
			printf("- ");
		}
	}
	printf("\npro\tpri\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pr,p[i].pri,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	printf("Average turn around time: %f",atat/n);
	printf("\nAverage turn around time: %f",awt/n);
}
