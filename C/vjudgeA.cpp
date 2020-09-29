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

int insert(int value){
	int temp=-1;
	count++;
	heap[count]=value;
	for(int i=1;i<=count;i++){
		if(heap[count]==heap[i]){
			temp=1;
		}
		printf("%d\n",heap[i]);
	}
	
	upheap(count);
	return temp;	
}

void pop(){
	heap[1]=heap[count];
	count--;
	downheap(count);	
}

void printc(int angka){
	int temp=0;
	for(int i=1;i<=count;i++){
		if(angka>heap[i]){
			temp++;		
		}
	}
	printf("%d\n",temp);
}

void printk(int terkecilke){
	for(int i=1;i<=terkecilke;i++){
		if(i==terkecilke){
			printf("%d\n",heap[terkecilke]);
			break;
		}
		if(terkecilke>count) printf("invalid\n");
		pop();
	}
}


int main()
{
	int tcase=0;
	char pilih;
	int angka;
	scanf("%d",&tcase);fflush(stdin);
	for(int i=1;i<=tcase;i++){
		scanf("%c %d",&pilih,&angka);fflush(stdin);
		if(pilih=='I'){
			if(insert(angka)!=1){
				insert(angka);
			}
		}
		else if(pilih=='D'){
			pop();
		}
		else if(pilih=='C'){
			printc(angka);	
		}
		else if(pilih=='K'){
			printk(angka);
		}
	}
	return 0;
}
