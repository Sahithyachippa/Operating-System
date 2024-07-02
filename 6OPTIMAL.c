#include<stdio.h>
	//1 2 3 2 1 5 2 1 6 2 5 6 3 1 3 6 1 2 4 3
	//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
	int search(int key,int r[],int start,int n){
		for(int i=start;i<n;i++){
			if(key==r[i])
				return i;
			}
		return -1;
	}
int greatest(int t[],int m){
	int max=1,pos;
	for(int i=0;i<m;i++){
		if(t[i]==-1){
			return i;
			}
		}	
		for(int i=0;i<m;i++){
			if(t[i]>max){
				max=t[i];
				pos=i;
				}
			}
		return pos;
}				
								
int main(){
	int n,m,i,j,pf=0,c=0;
	printf("Enter the reference string size and no.of frames:");
	scanf("%d %d",&n,&m);
	int r[n],b[m],t[m];
	printf("Enter reference string:");
	for(i=0;i<n;i++){
		scanf("%d",&r[i]);
		}
	for(j=0;j<m;j++){
		b[j]=-1;
		}
	printf("r[i]\tb[0]\tb[1]\tb[2]\n");		
	for(i=0;i<n;i++){
		int f1=0,f2=0;
		for(j=0;j<m;j++){
			if(r[i]==b[j]){
				f1=f2=1;
				break;
				}
				}
		if(f1==0){
			for(j=0;j<m;j++){
				if(b[j]==-1){
					b[j]=r[i];
					pf++;
					f2=1;
					break;
					}
				}
			}
		if(f2==0){
			for(j=0;j<m;j++){
				t[j]=search(b[j],r,i,n);
				}
			int index=greatest(t,m);
			b[index]=r[i];
			pf++;
			}
		printf("\n");
        printf("%d\t\t\t",r[i]);
        for( j= 0; j < m; j++)
        {
            if(b[j] != -1)
                printf(" %d\t\t\t", b[j]);
            else
                printf(" - \t\t\t");
        }
        }	
			
		printf("\npf:%d",pf);
	}			
					
							
