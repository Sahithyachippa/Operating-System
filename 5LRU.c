#include<stdio.h>
int lru(int t[],int m){
	int min=t[0],loc=0;
	for(int i=1;i<m;i++){
		if(t[i]<min){
			min=t[i];
			 loc=i;
			}
		}
	return loc;
	}
	//1 2 3 2 1 5 2 1 6 2 5 6 3 1 3 6 1 2 4 3		
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
				c++;
				t[j]=c;
				break;
				}
			}
		if(f1==0){
			for(j=0;j<m;j++){
				if(b[j]==-1){
					f2=1;
					pf++;
					c++;
					b[j]=r[i];
					t[j]=c;
					break;
					}
				}
			}
		if(f2==0){
			int index=lru(t,m);
			c++;
			t[index]=c;
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
				
			
