#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	char nama[100];
	data *next,*prev;
}*head[10],*tail[10],*curr;
int hash(char nama[]){
	int len=strlen(nama);
	int temp=0;
	for(int i=0;i<len;i++){
		temp+=nama[i];
	}
	return temp%10;
}
void pushhash(char nama[]){
	int key=hash(nama);
	curr=(data*)malloc(sizeof(data));
	curr->next=NULL;
	curr->prev=NULL;
	strcpy(curr->nama,nama);
	if(head[key]==NULL){
		head[key]=tail[key]=curr;
	}
	else{
		tail[key]->next=curr;
		curr->prev=tail[key];
		tail[key]=curr;
	}
}
void viewall(){
	for(int i=0;i<10;i++){
		printf("%d:",i);
		if(head[i]==NULL){
			printf("NULL\n");
		}
		else{
			curr=head[i];
			while(curr!=NULL){
				printf("%s->",curr->nama);
				curr=curr->next;
			}
			puts("");
		}
	}
}
int main(){
	int pilih;
	char nama[255];
	do{
		system("CLS");
		printf("====List Data====\n");
		viewall();
		printf("=================\n\n");
		printf("1. Push Hash\n");
		printf("2. Exit\n");
		printf("Choose : ");
		scanf("%d",&pilih);fflush(stdin);
		switch(pilih){
			case 1:
				printf("Masukkan nama: ");scanf("%[^\n]",nama);fflush(stdin);
				pushhash(nama);
				printf("Nama berhasil di input");
				getchar();
				break;
		}
	}while(pilih!=2);
	return 0;
}
