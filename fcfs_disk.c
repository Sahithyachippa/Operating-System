#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,i,sum,head;
printf("enter size of array\n");

scanf("%d",&n);
printf("enter elements of array\n");
int a[n];
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter head\n");
scanf("%d",&head);


sum=abs(a[0]-head);
for(i=1;i<n;i++)
{
sum=sum+abs(a[i]-a[i-1]);

}
printf("the total head movements are %d\n",sum);

}


