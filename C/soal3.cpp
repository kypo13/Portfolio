#include<stdio.h>
#include<stdlib.h>
struct data{
	int angka;
	data *left,*right,*next,*parent;
}*head,*tail,*curr,*root;
struct data *createnode(int angka){
	data *temp=(data*)malloc(sizeof(data));
	temp->angka=angka;
	temp->next=NULL;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void push(int angka,data *curr){
	int key;
	if(root==NULL){
		root=createnode(angka);
	}
	else{
		if(angka>curr->angka){
			if(curr->right==NULL){
				curr->right=createnode(angka);
				curr->right->parent=curr;
			}
			else{
				push(angka,curr->right);
			}
		}
		else if(angka<curr->angka){
			if(curr->left==NULL){
				curr->left=createnode(angka);
				curr->left->parent=curr;
			}
			else{
				push(angka,curr->left);
			}
		}
	}
}
int search(int angka){
	int key=0;
	if(root->angka==angka){
		key=1;
	}
	else{
		if(root->left->angka==angka){
			key=1;
		}
		else if(root->right->angka==angka){
			key=1;
		}
		else key=0;
	}
	return key;
}
void preorder(data *node){
	if(node!=NULL){
	printf("%d ",node->angka);
	preorder(node->left);
	preorder(node->right);
	}
}
void inorder(data *node){
	if(node!=NULL){
	inorder(node->left);
	printf("%d ",node->angka);
	inorder(node->right);
	}
}

void postorder(data *node){
	if(node!=NULL){
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->angka);
	}
}
int main()
{
	int pilih,angka;
	int key=1;
	do{
		system("CLS");
		printf("Binary Tree\n");
		printf("1. Push data\n");
		printf("2. View Preorder\n");
		printf("3. View Inorder\n");
		printf("4. View Postorder\n");
		printf("5. Exit\n");
		printf("Choose :");
		scanf("%d",&pilih);fflush(stdin);
		switch(pilih){
			case 1:
				printf("Masukkan angka : ");scanf("%d",&angka);fflush(stdin);
				push(angka,root);
				if(search(angka)==0)printf("Insert gagal, data sudah ada\n");
				else printf("Data berhasil di input\n");
			case 2:
				preorder(root);
				getchar();
				break;
			case 3:
				inorder(root);
				getchar();
				break;
			case 4:
				postorder(root);
				getchar();
				break;
		}
	}while(pilih!=5);
	return 0;
}
