#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int angka;
	node *left,*right;
}*root=NULL;

void push(node *curr,int angka){
	if (root==NULL){
		node *curr=(node*)malloc(sizeof(node));
		curr->angka=angka;
		curr->right=NULL;
		curr->left=NULL;
	}
	else{
		if(angka<curr->angka){
			push(curr->left,angka);
		}
		else{
			push(curr->right,angka);
		}
	}
}


void inorder(node *curr){
	if(curr!=NULL){
		inorder(curr->left);
		printf("%d ",curr->angka);
		inorder(curr->right);
	}
}
int main(){
	root=NULL;
	push(root,5);
	push(root,3);
	push(root,10);
	inorder(root);
}
