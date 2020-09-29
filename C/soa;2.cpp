#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct mahasiswa{
	char nama[255];
	int umur;
	mahasiswa *next;
}*tail,*head,*curr;
void push(char nama[],int umur){
	curr=(mahasiswa*)malloc(sizeof(mahasiswa));
	strcpy(curr->nama,nama);
	curr->umur=umur;
	curr->next=NULL;
	if(head==NULL){
		head=tail=curr;
	}
	else{
		curr->next=head;
		head=curr;
	}
}
void pop(){
	curr=tail;
	if(head==tail){
		free(head);
		head=NULL;
	}
	else{
		tail=head;
		while(tail->next!=curr){
			tail=tail->next;
		}
		free(curr);
		tail->next=NULL;
	}
}
void view()
{
	curr=head;
	if (head==NULL){
		printf("No data!\n");
	}
	else{
		while(curr!=NULL){
			printf("%s(%d)->",curr->nama,curr->umur);
			curr=curr->next;
		}
	}
}
int main()
{
	int pilih,umur;
	char nama[255];
	do{
		system("CLS");
		printf("========\n");
		printf("Queue List\n");
		printf("========\n\n");
		view();
		printf("\n\n1.Push queue\n");
		printf("2.Pop queue\n");
		printf("3.Exit\n");
		printf("Choose :");
		scanf("%d",&pilih);fflush(stdin);
		switch(pilih){
			case 1:
				printf("Masukkan nama: ");scanf("%[^\n]",nama);fflush(stdin);
				printf("Masukkan umur: ");scanf("%d",&umur);fflush(stdin);
				push(nama,umur);
				break;
			case 2:
				pop();
				break;
		}
	}while(pilih!=3);
	return 0;
}
