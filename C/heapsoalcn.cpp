#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count=0;
struct node{
	char id[100];
	char nama[100];
	int priority[100];
}*heap[100];

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
	if(index<=1){
		return;
	}	
	int parentidx=getparent(index);
	
}

void insert(int value){
	count++;
	heap[100].priority[count]=value;
	upheap(count);
}

void menu(){
	printf("\n");
	printf("Menu\n");
	printf("1. Add Student to queue\n");
	printf("2. Call Student from queue\n");
	printf("3. Exit\n");
}

void view(){
	for (int i=1;i<=count;i++){
		printf("%s - %s - %d\n",heap[i].id,heap[i].nama,heap[i].priority);
	}
}

bool checkexistprior(int priority){
	for(int i=1;i<=count;i++){
		if(priority==heap[i].priority){
			return false;
		}
	}
	return true;
}
int main()
{
	int menu=0;
	do{
		view();
		menu();
		do{
			printf("Choose menu:");scanf("%d",&menu);
			switch(menu){
				case 1:
					do{
					printf("Input studentID: ");
					scanf("%[^\n]",node[count].id);
					fflush(stdin);
				}while(strlen(node[count].id) != 10);
				do{
					printf("Input student name: ");
					scanf("%[^\n]",node[count].nama);
					fflush(stdin);
				}while(strlen(node.nama) < 5 || strlen(node.nama) > 20);
				do{
					printf("Input priority: ");
					scanf("%d",&node.priority);
					fflush(stdin);
				}while(!checkexistprior(node.priority));
					break;
				case 2:
					break;
				case 3:
					break;
			}
		}while(menu<1||menu>3);
	}while(menu!=3);
	return 0;
}
