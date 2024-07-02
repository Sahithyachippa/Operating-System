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
  
  for(i=0;i<n;i++)
 {
  if(s[i]<min)
  {
   min=s[i];
   }
}
printf("min is %d",min);

 for(i=0;i<n;i++)
 {
  if(s[i]>max)
  {
   max=s[i];
   }
}
printf("\n max is %d",max);

rsum=abs(head-limit)+abs(limit-min);
lsum=abs(head-0)+abs(0-max);

printf("\nright and left sums : %d %d",rsum,lsum);


}
