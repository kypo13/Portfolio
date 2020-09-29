#include<stdio.h>
int main()
{
	int tcase,n,ar;
	int data[1002];
	scanf("%d %d",&n,&tcase);
	for (int i=1;i<=n;i++){
		scanf("%d",&data[i]);
	}
	int temp;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n-1;j++){
			if (data[j]>data[j+1]){
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
	}
	for (int i=1;i<=tcase;i++){
		scanf("%d",&ar);
		printf("%d\n",data[ar]);
	}
	return 0;
}
