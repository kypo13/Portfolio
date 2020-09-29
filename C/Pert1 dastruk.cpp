#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	node *next;
}*head=NULL,*tail=NULL,*curr;

void pushdepan(int num){
	node *curr=(node*)malloc (sizeof(node));
	curr->num=num;
	curr->next=NULL;
	if (head==NULL){
		head=tail=curr;
	}
	else {
		curr->next=head;
		head=curr;
	}	
}
void pushbelakang(int num){
	node *curr=(node*)malloc(sizeof(node));
	curr->num=num;
	curr->next=NULL;
	if (head==NULL){
		head=tail=curr;
	}
	else{
		tail->next=curr;
		tail=curr;
	}
}
void popdepan(){
	if (head!=NULL){
		if (head==tail){
			free(head);
			head=tail=NULL;
		}	
		else{
			curr=head;
			head=head->next;
			free(curr);
		}
	}

}
void popbelakang(){
	if (head!=NULL){
		if(head==tail){
			free(head);
			head=tail=NULL;
		}
		else{
			curr=tail;
			tail=head;
			while(tail->next!=curr){
				tail=tail->next;
			}
			tail->next=NULL;
			free(curr);
		}
	}
}
void pushmidsorting(int num){
	node *curr=(node*)malloc (sizeof(node));
	curr->num=num;
	curr->next=NULL;
	if (head==NULL){
		head=tail=curr;
	}
	else{
		if(curr->num<head->num){
			pushdepan(num);
		}
		else if(curr->num>tail->num){
			pushbelakang(num);
		}
		else{
			node *temp=head;
			while(temp->next->num<curr->num){
				temp=temp->next;
			}
			curr->next=temp->next;
			temp->next=curr;
		}
	}
}
void popangka(int key){
	node *temp=head;
	while(temp!=NULL){
		if(head->num==key){
			popdepan();break;
		}
		else if(tail->num==key){
			popbelakang();break;
		}
		else{
			curr=temp->next;
			temp->next=curr->next;
			free(curr);
			break;
		}
		temp=temp->next;
	}
}
void viewall(){
	curr=head;
	while(curr!=NULL){
		printf("%d ->",curr->num);
		curr=curr->next;
	}
}
int main()
{
	pushdepan(5);
	pushdepan(10);
	pushbelakang(100);
	//popdepan();
	popangka(5);
	viewall();
	return 0;
}
