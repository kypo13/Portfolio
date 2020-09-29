#include<stdio.h>

int heap[1002];
int count=0;

int getparent(int index){
	return index*2;
}

int getleft(int index){
	return index/2;
}

int getright(int index){
	return index/2+1;
}

void upheap(int index){
	if(index<=1)return;
	int parent=getparent(index);
	if(heap[index]<heap[parent]){
		int temp=heap[index];
		heap[index]=heap[parent];
		heap[parent]=temp;
		upheap(parent);
	}	
}

void downheap(int index){
	if(index*2>count){
		return;
	}
	int left=getleft(index);
	int right=getright(index);
	int smallest=index;
	if(left<=count && heap[left]<heap[smallest]){
		smallest=left;
	}
	if(right<=count && heap[right]<heap[smallest]){
		smallest=right;
	}
	if(smallest==index)return;
	int temp=heap[index];
	heap[index]=heap[smallest];
	heap[smallest]=temp;
	downheap(smallest);
}
void pop(){
	if(count==0){
		return;
	}
	heap[1]=heap[count];
	count--;
	downheap(count);
}
void insert(int value){
	count++;
	heap[count]=value;
	upheap(count);
}

int main(){
	int banyak=0;
	int target=0;
	int data;
	scanf("%d %d",&banyak,&target);
	for(int i=1;i<=banyak;i++){
		scanf("%d",&data);
		insert(data);
	}
	int hitung=0;
	int proses=0;
	while(heap[1]<target){
		if ( count == 1) {
			printf("-1\n");
			return 0;
		}
		hitung=heap[1]*1;
		pop();
		hitung+=heap[1]*2;
		pop();
		insert(hitung);
		proses++;	
	}
	printf("%d\n",proses);
}
