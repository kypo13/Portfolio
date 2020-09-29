#include<stdio.h>
int main(){
	int banyak,bykdata,array,data[100020],swap;
	scanf("%d",&banyak);
	for (int i=1;i<=banyak;i++){
		scanf("%d %d",&bykdata,&array);
		printf("Case #%d:\n",i);
		for (int j=0;j<bykdata;j++){
			scanf("%d",&data[j]);
		}
		for (int j=0;j<bykdata;j++){
			for (int k=0;k<bykdata;k++){
				if (data[k]>data[j]){
					swap=data[j];
					data[j]=data[k];
					data[k]=swap;
				}
			}
		}
		for (int j=0;j<array;j++){
			for (int k=j;k<bykdata;k=k+array){
				if (k+array>=bykdata){
					printf("%d\n",data[k]);
				}
				else printf("%d ",data[k]);
			}
		}
		
	}
	return 0;
}
