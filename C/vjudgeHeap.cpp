#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int count=0;
int heap[100002];
int getparent(int index){
	return index/2;
}
int getleft(int index){
	return index*2;
}
int getright(int index){
	return index*2+1;
}
void downheap(int index){
	if(index*2>count)return;
	int leftidx=getleft(index);
	int rightidx=getright(index);
	int smallest=index;
	
	if(leftidx<=count && heap[leftidx]<heap[smallest]){
		smallest=leftidx;
	}
	if(rightidx<=count && heap[rightidx]<heap[smallest]){
		smallest=rightidx;
	}
	
	if(smallest==index)return;
	
	int temp=heap[index];
	heap[index]=heap[smallest];
	heap[smallest]=temp;
	downheap(smallest);
}
void upheap(int index){
	if(index<=1){
		return;
	}
	int parentidx=getparent(index);
	if(heap[index]<heap[parentidx]){
		int temp=heap[index];
		heap[index]=heap[parentidx];
		heap[parentidx]=temp;
		upheap(parentidx);
	}
}
void insert(int value){
	count++;
	heap[count]=value;
	upheap(count);
}

void pop(){
	if(count==0){
		return;
	}
	heap[1]=heap[count];
	count--;
	downheap(count);
}
void printall(){
	int i=1;
	printf("%d",heap[1]);
	printf("\n");
}

int main()
{
	int tcase=0;
	char pilih[100];
	scanf("%d",&tcase);fflush(stdin);
	for(int i=1;i<=tcase;i++){
		scanf("%[^\n]",pilih);fflush(stdin);
		if(pilih[0]=='1'){
			strcpy(pilih,&pilih[2]);
			int angka=atoi(pilih);
			insert(angka);
		}
		else if(pilih[0]=='2'){
			pop();
		}
		else if(pilih[0]=='3'){
			printall();
		}
	}
	return 0;
}
