#include<stdio.h>
int main(){
	int n,m,i,j,pf=0;
	printf("Enter the reference string size and no.of frames:");
	scanf("%d %d",&n,&m);
	int r[n],b[m];
	printf("Enter reference string:");
	for(i=0;i<n;i++){
		scanf("%d",&r[i]);
		}
	for(j=0;j<m;j++){
		b[j]=-1;
		}
	printf("r[i]\tb[0]\tb[1]\tb[2]\n");		
	for(i=0;i<n;i++){
		int s=0;
		for(j=0;j<m;j++){
			if(r[i]==b[j]){
				s++;
				pf--;
				//break;
				}
			}
			pf++;
			if((pf<=m )&&( s==0)){
				b[i]=r[i];
				}
			else if(s==0){
				b[(pf-1)%m]=r[i];
				}
		printf("%d\t",r[i]);		
	       for(j=0;j<m;j++){
	       if(b[j]!=-1){
	       	printf("%d\t",b[j]);
	       	}
	       else{	
	       	printf("-\t");
	       	}
	       }
	       printf("\n");	
	      }
	      printf("pf:%d",pf);
	     }  				
	
