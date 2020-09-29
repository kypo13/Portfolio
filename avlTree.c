#include<stdio.h>
#include<stdlib.h>

struct node{
	int angka;
	int height;
	node *left,*right;	
};

int height(node *temp){
	if(temp==NULL){
		return 0;
	}
	else{
		return temp->height;
	}
}

int max(int a,int b){
	if(a>b)return a;
	else return b;
}

node *newnode(int angka){
	node *temp=(node*)malloc(sizeof(node));
	temp->angka=angka;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}
int getbalance(node *root){
	if(root==NULL){
		return 0;
	}	
	else{
		return height(root->left)-height(root->right);
	}
}

node *rightrotate(node *y){
	node *x=y->left;
	node *t2=x->right;
	
	x->right=y;
	y->left=t2;
	
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}
node *leftrotate(node *x){
	node *y=x->right;
	node *t2=y->left;
	
	y->left=x;
	x->right=t2;
	
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return y;
}

void preorder(node *root){
	if(root!=NULL){
		printf("%d-> ",root->angka);
		preorder(root->left);
		preorder(root->right);
	}
}
node *insertnode(node *root,int num){
	if(root==NULL){
		return newnode(num);
	}
	if(num<root->angka){
		//left
		root->left=insertnode(root->left,num);
	}
	else if(num>root->angka){
		//right
		root->right=insertnode(root->right,num);
	}
	
	root->height=1+max(height(root->left),height(root->right));
	
	int balance=getbalance(root);
	if(balance>1 && num<root->left->angka){
		return rightrotate(root); //LL dan bandingin nya yaitu num dengan setelah node yang bermasalah
	}
	if(balance<-1 && num>root->right->angka){
		return leftrotate(root);
	}
	if(balance>1 && num>root->left->angka){ //LR
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	if(balance<-1 && num<root->right->angka){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	
	return root;
}
node *maxvalue(node *root){
	node *temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}
node *deletenode(node *root,int num){
	if(root==NULL){
		return root;
	}
	else if(num<root->angka){
		root->left=deletenode(root->left,num);
	}
	else if(num>root->angka){
		root->right=deletenode(root->right,num);
	}
	else{
		if(root->left==NULL){
			node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){ //kondisi ga ada anak atau salah satu
			node *temp=root->left;
			free(root);
			return temp;
		}
		else{
			node *successor =maxvalue(root->left);
			root->angka=successor->angka;
			root->left=deletenode(root->left,successor->angka);//delete nya buat delete pengganti dibawahnya
		}
	}
	if(root==NULL){
		return root;	
	}
	root->height=1+max(height(root->left),height(root->right));
	int balance = getbalance(root);
	
	if(balance>1 && getbalance(root->left)>=0){
		return rightrotate(root);
	}
	if(balance >1 && getbalance(root->left)<0){
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	if(balance<-1 && getbalance(root->right)<=0){
		return leftrotate(root);
	}
	if(balance<-1 && getbalance(root->right)>0){
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
} 
int main()
{
	node *root=NULL;
	root=insertnode(root,10);
	root=insertnode(root,20);
	root=insertnode(root,30);
	root=insertnode(root,40);
	root=insertnode(root,50);
	root=insertnode(root,25);
	deletenode(root,25);
	preorder(root);
	
	return 0;
}
