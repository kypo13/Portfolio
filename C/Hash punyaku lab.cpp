#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//size pake ukuran 97
struct data{
	int key;
	char nama[100];
	data *next;
}*curr,*head[97],*tail[97];
//hash function yang digunakan adalah division
int hash(char nama[]){
	int len=strlen(nama);
	int hashkey=0;
	for(int i=0;i<len;i++){
		hashkey=hashkey+nama[i];
	}
	return hashkey%97;
}

void pushhast(char nama[],int idx){
	curr=(data*)malloc(sizeof(data));
	curr->next=NULL;
	strcpy(curr->nama,nama);
	curr->key=idx;
	if(head[idx]==NULL){
		head[idx]=tail[idx]=curr;
	}
	else{
		tail[idx]->next=curr;
		tail[idx]=curr;
	}
}

void view(){
	for(int i=0;i<97;i++){
		if(head[i]!=NULL){
			printf("[%d] : ",i);
			data *curr=head[i];
			while(curr!=NULL){
				if(curr->next==NULL){
					printf("%s\n",curr->nama);
				}
				else{
				printf("%s -> ",curr->nama);
				}
				curr=curr->next;
			}
		}
	}
}

void search(char nama[],int idx){
	if(head[idx]==NULL){
		printf("Data not found\n");
	}	
	else{
		curr=head[idx];
		while(curr!=NULL){
			if(strcmp(curr->nama,nama)==0){
				printf("Data found in index %d\n",idx);
			}
			else{
				printf("Data not found\n");
			}
			curr=curr->next;
		}
	}
}
int main(){
	int pil=0;
	int key=0;
	char nama[100]="";
	do{
		system("cls");
		printf("1. Insert\n");
		printf("2. View\n");
		printf("3. Searching\n");
		printf("4. Exit\n");
		printf("Input menu:\n");
		scanf("%d",&pil);fflush(stdin);
		switch(pil){
			case 1:
				printf("Input name :");
				scanf("%s",nama);fflush(stdin);
				key=hash(nama);
				pushhast(nama,key);
				break;
			case 2:
				view();
				break;
			case 3:
				printf("Input name :");
				scanf("%s",nama);fflush(stdin);
				key=hash(nama);
				search(nama,key);
				break;
			case 4:				
				printf("Thanks\n");
				break;
		}
		getchar();
	}while(pil!=4);
	return 0;
}
