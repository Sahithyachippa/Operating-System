#include<stdio.h>
#include<stdlib.h>
struct process{
	int pro,at,bt,ct,tat,wt,c;
};
int findprocess(struct process *p,int n,int time,int dbt[])
{
	int min=9999,index=-1;
	for(int i=0;i<n;i++)
	{
		if(p[i].at<=time && p[i].c==0)
		{
			if(dbt[i]<min)
			{
				min=dbt[i];
				index=i;
			}
		}
	}
	return index;
}
int main()
{
	float atat=0,awt=0;
	int n;
	printf("enter number of process: ");
	scanf("%d",&n);
	struct process *p;
	p=(struct process*)malloc(n*sizeof(struct process));
	printf("enter process,arrival time,burst time: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&p[i].pro,&p[i].at,&p[i].bt);
		p[i].c=0;
	}
	int dbt[n];
	for(int i=0;i<n;i++)
	{
		dbt[i]=p[i].bt;
	}
	int k=0,time=0;
	printf("GanttChatt: ");
	while(k<n)
	{
		int index=findprocess(p,n,time,dbt);
		if(index!=-1)
		{
			time++;
			dbt[index]=dbt[index]-1;
			if(dbt[index]==0)
			{
				p[index].c=1;
				p[index].ct=time;
				k++;
				printf("P%d ",p[index].pro);
			}
		}
		else
		{
			time++;
			printf("- ");
		}
	}
	for(int i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		atat+=p[i].tat;
		awt+=p[i].wt;
	}
	printf("\npro\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pro,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	printf("\nAverage TAT: %f",atat);
	printf("\nAverage WT: %f",awt);
}
