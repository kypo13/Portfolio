#include<stdio.h>
int main(){
	int n,query;
	int temp;
	int search[100],data[100];
	scanf("%d %d",&n,&query);
	for (int i=1;i<=n;i++){
		scanf("%d",&data[i]);
	}
	for (int i=1;i<=query;i++){
		scanf("%d",&search[i]);
		temp=0;
		for (int j=1;j<=query;j++){
			for (int k=1;k<=n;k++){
				if (search[j]='a'){
					continue;
				}
				if (search[j]==data[k]){
					search[j]='a';
					temp++;
					
				}
			}
		}
		printf("%d\n",temp);
	}
	return 0;
}
