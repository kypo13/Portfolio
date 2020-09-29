#include<stdio.h>

void swap(int *x, int *y){
	int temp;
	
	temp = *x;
	*x   = *y;
	*y   = temp;
}

int partition(int array[10001], int low, int high){
	int i = low - 1;
	int pivot = high;
	int j;
	
	for(j=low; j<=high-1; j++){
		if(array[j] < array[pivot]){
			i++;
			swap(&array[i], &array[j]);
		}	
	}
	swap(&array[i+1], &array[pivot]);
	
	return (i + 1);
}

void quicksort(int array[10001], int low, int high){
	int pi;
	
	if (low < high){
		pi = partition(array, low, high);
		
		
		quicksort(array, low, pi-1);
		quicksort(array, pi+1, high);
	}
}

int main(){
	int jumlah;
	int array[10001];
	
	printf("Masukkan Jumlah Array : " );
	scanf("%d", &jumlah);
	
	for(int i=0; i<jumlah; i++){
		scanf("%d", &array[i]);
	}
	
	quicksort(array, 0, jumlah-1);
	
	for(int j=0; j<jumlah; j++){
		printf("%d ", array[j]);
	}
	return 0;
}
