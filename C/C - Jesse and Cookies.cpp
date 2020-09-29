#include<stdio.h>
#include<math.h>
//min heap

int heap[1000005];
int count = 0;

int getParentIndex( int index){
	
	return index/2;
}

int getLeftChildParent ( int index) {
	
	return index*2;
}

int getRightChildParent ( int index) {
	
	return index*2+1;
}

void upheapmin(int index) {
	
	if(index <=1) return;
	int parentIdx = getParentIndex(index);
	if (heap[index] < heap[parentIdx]){
		int temp = heap[index];
		heap[index] = heap[parentIdx];
		heap[parentIdx] = temp;
		
		upheapmin(parentIdx);
	}
}

void addData(int value) {
	count++;
	
	heap[count] = value;
	
	upheapmin(count);
	
	
}

void downheapmin( int index) {
	
	if ( index*2 > count ) return;
	
	int right = getRightChildParent(index);
	int left  = getLeftChildParent(index);
	
	int smallest = index;
	
	if ( left <= count && heap[left] < heap[smallest]) {
		smallest = left;
	}
	
	if ( right <= count && heap[right] < heap[smallest]) {
		smallest = right;
	}
	
	if ( smallest == index) return;
	
	int temp = heap[smallest];
	heap[smallest] = heap[index];
	heap[index] = temp;
	
	downheapmin(smallest);
}

void pop() {
	
	if ( count == 0) {
		return;
	}
	
	heap[1] = heap[count];
	count--;
	
	downheapmin(1);
	
}

void view() {
	for( int i = 1; i <= count; i++) {
		printf("%d ",heap[i]);
	}
	printf("\n");
}

void printMinimum () {
	int minimumNumber = heap[1];
	for ( int i = 1; i <= count; i++) {
		if ( heap[i] < minimumNumber) {
			minimumNumber = heap[i];
		}
	}
	
	printf("%d",minimumNumber);
}

void merge(int arr[], int left, int mid, int right)
{
	int i1;
	int i2;
	int temp[right];
	int i;
	
	for (i = left, i1 = left, i2 = mid+1; i1 <= mid && i2 <= right; ++i)
	{
		if (arr[i1] > arr[i2])
		{
			temp[i] = arr[i2++];
		}
		else
		{
			temp[i] = arr[i1++];
		}
	}
	
	for (int j = i1; j <= mid; ++j)
	{
		temp[i++] = arr[j];
	}
	
	for (int j = i2; j <= right; ++j)
	{
		temp[i++] = arr[j];
	}
	
	for (int j = left; j <= right; ++j)
	{
		arr[j] = temp[j];
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}


int main() {
	
	int jumlahCookies = 0;
	int cookie = 0;
	int targetManis = 0;
	
	scanf("%d %d",&jumlahCookies,&targetManis);
	
	for ( int i = 1; i <= jumlahCookies; i++) {
		scanf("%d",&cookie);
		addData(cookie);
	}	
	int hitung = 0;
	int countProsesManis = 0;

		while(heap[1] < targetManis) {
			
			if ( count == 1) {
				printf("-1\n");
				return 0;
			} 
			hitung = (heap[1]*1);
			pop(); 
			hitung+=heap[1]*2;
			pop();
			addData(hitung);
			countProsesManis++;
		//	printf("%d ",hitung);
		}
		printf("%d\n", countProsesManis); 
//	}
	
	return 0;
}

