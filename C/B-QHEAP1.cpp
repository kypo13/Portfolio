#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//min heap
//inputnya dibuat pake String
int heap[100001];
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
	if (heap[index] <heap[parentIdx]){
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
		printf("%2d ",heap[i]);
	}
}



void printMinimum () {
	int minimumNumber = heap[1];
	for ( int i = 1; i <= count; i++) {
		if ( heap[i] < minimumNumber) {
			minimumNumber = heap[i];
		}
	}
	
	printf("%d ",minimumNumber);
}

int main() {
	
	int jumlahData = 0;
	char pilihanMenuHeap[5];
	int angka;
	
	
	scanf("%d",&jumlahData);
	getchar();
	for ( int i = 0; i < jumlahData; i++) {
		gets(pilihanMenuHeap);
		if ( pilihanMenuHeap[0] == '1') {
			strcpy(pilihanMenuHeap,&pilihanMenuHeap[2]);
			int inputAngka = atoi(pilihanMenuHeap);
			addData(inputAngka);
			
		} else if ( pilihanMenuHeap[0] == '2') {
			strcpy(pilihanMenuHeap,&pilihanMenuHeap[2]);
			pop();
			
		} else if ( pilihanMenuHeap[0] == '3') {
			printf("%d\n",heap[1]);
		}
	}

	return 0;
}

