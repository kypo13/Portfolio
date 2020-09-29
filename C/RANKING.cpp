#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		int a;
		scanf("%d",&a);
		int array[1005];
		for (int j=0; j<a; j++){
			scanf("%d",&array[j]);
		}	
			printf("Case #%d: ",i+1);
			int count=1;
			for (int k=0; k<a; k++){
				for (int l=0; l<a; l++){	
					if (array[k]<array[l]){
						count++;
					}
				}
				if (k==0){
				printf("%d",count);	
				}	
				else{
					printf(" %d",count);
				}
				count=1;
			}
			printf("\n");
		}
	}
