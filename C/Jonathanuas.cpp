#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int prior;
	char nama[100];
	char nim[100];
}*curr;

//int heapify(int arr[],int n,int i){
//	int largest=i;
//	int l=2*i+1;
//	int r=2*i+2;
//	
//	if(l<n && arr[l]>arr[largest]){
//		largest = l;
//	}
//	if(r<n && arr[r]>arr[largest]){
//		largest = r;
//	}
//	if(largest!=i){
//		swap(arr[i],arr[largest]);
//		heapify(arr,n,largest);
//	}
//	return largest;
//}

//void insertnode(int arr[],int &n,int key){
//	
//	heapify(arr,n,n-1);
//}
//
//void deletenode(int arr[],int &n){
//	
//	heapify(arr,n,0);
//}
//void swap(int arr1[],int arr2[],int i){
//	
//}

void viewqueue(data *curr){
	if(curr.nama!=NULL){
		printf("%s - %s- %d",data.nim,data.nama,data.prior);
	}
}

void viewnext(){
		
}
int main()
{
	int i=0;
	int menu;
	
	do{
		system("cls");
		printf("Queue List\n");
		printf("==========\n");
		viewqueue();
		printf("Next student:\n");
		printf("=============\n");
		viewnext();
		printf("Menu\n");
		printf("====\n");
		printf("1. Add student to queue\n");
		printf("2. Call student from queue\n");
		printf("3. Exit\n");
		printf("Input menu:");scanf("%d",&menu);
		switch(menu){
			case 1:
				do{
					printf("Input student ID [10 digit]:");scanf("%s",data.nim[i]);	
				}while(strlen(data.nim[i])==10);
				do{
					printf("Input student name [5..20]:");scanf("%s",data.nama[i]);
				}while(strlen(data.nama[i])<5&&strlen(data.nama[i]>20));
				do{
				printf("Input priority :");scanf("%d",&data.prior[i]);
				}while(find!=0);
				i++;
				break;
			case 2:
				
				break;
			case 3:
				break;
		}
	}while(menu!=3);
	return 0;
}
