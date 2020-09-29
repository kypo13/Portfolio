#include<stdio.h>
void swap(int *a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition (int data[100],int l,int h){
	int pivot=data[l];
	int i=l;
	int j=h;
	while(i<j){
		do{
			i++;
		}while(data[i]<=pivot);
		do{
			j--;
		}while(data[j]>pivot);
		if (i<j){
			swap(&data[i],&data[j]);
		}
		swap(&data[l],&data[j]);
	}
	return j;
}
void quicksort(int data[100],int l,int h){
	int j;
	if (l<h){
	j=partition(data,l,h);
	quicksort(data,l,j);
	quicksort(data,j+1,h);
	}
}
int main(){
	int n;
	int data[100];
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	quicksort(data,0,n-1);
	for (int i=0;i<n;i++){
		printf("%d  ",data[i]);
	}
	return 0;
}
