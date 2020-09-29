#include<stdio.h>
#include<stdlib.h>

struct node{
	int angka;
	node *next;
	node *prev;
}*head,*tail,*curr;

node *createnode(int angka){
	curr=(node*)malloc(sizeof(node));
	curr->angka=angka;
	curr->next=NULL;
	curr->prev=NULL;
	return curr;
}
void pushbelakang(int angka){
	curr=createnode(angka);
	if(head==NULL){
		head=tail=curr;
	}
	else{
		tail->next=curr;
		curr->prev=tail;
		tail=curr;
		tail->next=NULL;
	}
}

void pushdepan(int angka){
	curr=createnode(angka);
	if(head==NULL){
		head=tail=curr;
	}
	else{
		curr->next=head;
		head->prev=curr;
		head=curr;
	}
}

void popdepan(){
	if (head!=NULL){
		if(head->next==NULL){
			free(head);
			head=NULL;
		}
		else{
			curr=head;
			head=head->next;
			head->prev=NULL;
			free(curr);
			
		}
	}
}
void popbelakang(){
	if (head!=NULL){
		if(tail==head){
			free(head);
			head=NULL;
		}
		else{
			curr=tail;
			tail=tail->prev;
			free(curr);
			tail->next=NULL;
//			curr=head;
//			while(curr->next!=tail){
//				curr=curr->next;
//			}
//			curr=tail->prev
//			free(tail);
//			tail=curr;
//			tail->next=NULL;
		}
	}
}
void poptengah(int angka){
	if(head!=NULL){
		if(head->angka==angka){
			popdepan();
		}
		else if(tail->angka==angka){
			popbelakang();
		}
		else{
			node *temp=head;
			while(temp!=NULL && temp->angka!=angka){
				temp=temp->next;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
		}
	}
}
void push(int angka){ // sort descending bessar ke kecil
	curr=createnode(angka);
	if(head==NULL){
		pushdepan(angka);
	}
	else{
		if(head->angka<angka){
			pushdepan(angka);
		}
		else if (tail->angka>angka){
			pushbelakang(angka);
		}
		else{
			node *temp=head;
			while(temp->angka>angka){
				temp=temp->next;
			}
			curr->next=temp;
			curr->prev=temp->prev;
			temp->prev->next=curr;
			temp->prev=curr;
		}
	}
}

void viewall(){
	curr=head;
	while(curr!=NULL){
		printf("%d-> ",curr->angka);
		curr=curr->next;
	}
}
int main()
{
	push(1);
	push(2);
	push(10);
	push(9);
	poptengah(9);
//	pushdepan(5);
//	pushdepan(10);
//	pushdepan(15);
//	pushbelakang(20);
//	pushbelakang(25);
//	popdepan();
//	popbelakang();
	viewall();
	return 0;
}
