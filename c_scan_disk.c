#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main()
{
 int i,j,min=INT_MAX,max=INT_MIN,head,limit,n,lsum=0,rsum=0;
 
 printf("enter the n :");
 scanf("%d",&n);
 printf("enter the head :");
 scanf("%d",&head);
 
 printf("enter the limit :");
 scanf("%d",&limit);
 int s[n];
 for(i=0;i<n;i++)
  {
   scanf("%d",&s[i]);
  }
int max1=1;
int max2=1000;
for(i=0;i<n;i++)
{
	if(s[i]<head && s[i]>max1)
{
max1=s[i];
}
}
for(i=0;i<n;i++)
{
	if(s[i]>head && s[i]<max2)
{
max2=s[i];
}
}
printf("%d %d",max1,max2);
lsum=abs(head-limit)+limit+max1;
rsum=abs(head-0)+limit+(limit-max2);

printf("leftsum and right sumare : %d %d",lsum,rsum);


}
