#include<stdio.h>
int heap[100]; //max 99 element, root starts with index 1
int count = 0;

int getParentIdx(int index){
	return index/2;
}

int getLeftChildIdx(int index){
	return index*2;
}

int getRightChildIdx(int index){
	return index*2+1;
}

void upheapmin(int index){
	if(index <=1) return;
	int parentIdx = getParentIdx(index);
	if(heap[index] < heap[parentIdx]){
		int temp = heap[index];
		heap[index] = heap[parentIdx];
		heap[parentIdx] = temp;
		upheapmin(parentIdx);
	}
}

void push(int value){
	count++;
	heap[count] = value;
	upheapmin(count);
}

void view(){
	int i;
	for(i=1;i<=count;i++){
		printf("%2d ", heap[i]);
	}
	printf("\n");
}

//    1
//  2   3
// 4 5  
// count = 5
void downheapmin(int index){
	if(index*2 > count) return;
	int left = getLeftChildIdx(index);
	int right = getRightChildIdx(index);
	
	int smallest = index;
	if(left <=count && heap[left] < heap[smallest]){
		smallest = left;
	}
	if(right <= count && heap[right] < heap[smallest]){
		smallest = right;
	}
	
	if(smallest == index) return;
	
	int temp = heap[index];
	heap[index] = heap[smallest];
	heap[smallest] = temp;
	
	downheapmin(smallest);
}

void pop(){
	if(count == 0){
		return;
	}
	heap[1] = heap[count];
	count--;
	downheapmin(1);
}

int main()
{
	int banyak;
	int data[100];
	scanf("%d",&banyak);
	float total=0;
	for(int i=1;i<=banyak;i++){
		scanf("%d",&data[i]);
		push(data[i]);
		if(i==1){
			printf("%d.0\n",data[i]);
			continue;		
		}
		else if(i%2==1){
			printf("%d.0\n",data[i/2+1]);
		}
		else if(i%2==0){
			float temp=(float)(data[i/2]+data[i/2+1])/2;
			printf("%.1f\n",temp);
		}
		
	}
	return 0;
}
