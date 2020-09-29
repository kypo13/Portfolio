#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	int height;
	struct node *left,*right;
};

int max(int a,int b){
	if(a<b)return b;
	else return a;
}

int getheight(struct node *curr){
	if(curr==NULL){
		return 0;
	}
	return curr->height;
}

int getbf(struct node *curr){
	if(curr==NULL){
		return 0;
	}
	return getheight(curr->left)-getheight(curr->right);
}

struct node *newnode(int num){
	node *temp=(node*)malloc(sizeof(node));
	temp->key=num;
	temp->height=1;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node *rightrotate(struct node *x){
	node *y=x->left;
	node *B=y->right;
	
	y->right=x;
	x->left=B;
	
	x->height=max(getheight(x->left),getheight(x->right))+1;
	y->height=max(getheight(y->left),getheight(y->right))+1;
	
	return y;
}

struct node *leftrotate(struct node *x){
	node *y=x->right;
	node *B=y->left;
	
	y->left=x;
	x->right=B;
	
	x->height=max(getheight(x->left),getheight(x->right))+1;
	y->height=max(getheight(y->left),getheight(y->right))+1;
	
	return y;
}

//struct node *successor(struct node *root){
//	struct node *cur=root->right;
//	while(cur->left!=NULL){
//		cur=cur->left;
//	}
//	return cur;
//}

struct node *insert(struct node *curr,int value){
	if(curr==NULL){
		return newnode(value);
	}
	else if(value<curr->key){
		curr->left=insert(curr->left,value);
	}
	else if(value>curr->key){
		curr->right=insert(curr->right,value);
	}
	else {
		printf("Angka duplikat");
		return curr;
	}
	
	curr->height=max(getheight(curr->left),getheight(curr->right))+1;
	int bfactor=getbf(curr);
	
	if(bfactor>1 && value<curr->left->key){
		return rightrotate(curr);
	}
	else if(bfactor <-1 && value>curr->right->key){
		return leftrotate(curr);
	}
	else if(bfactor>1&&value>curr->left->key){
		curr->left=leftrotate(curr->left);
		return rightrotate(curr);
	}
	else if(bfactor<-1&&value<curr->left->key){
		curr->right=rightrotate(curr->right);
		return leftrotate(curr);
	}
	return curr;
}
void preorder(node *root){
	if(root!=NULL){
		printf("%d-> ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

node *maxvalue(node *root){
	node *temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}

struct node *deletevalue(struct node *curr,int value){
	if(curr==NULL){
		return NULL;
	}
	else if(value<curr->key){
		curr->left=deletevalue(curr->left,value);
	}
	else if(value>curr->key){
		curr->right=deletevalue(curr->right,value);
	}
	else{
		if(curr->left==NULL){
			node *temp=curr->right;
			free(curr);
			return temp;
		}
		else if(curr->right==NULL){
			node *temp=curr->left;
			free(curr);
			return temp;
		}
		else{
			node *successor=maxvalue(curr->left);
			curr->key=successor->key;
			curr->left=deletevalue(curr->left,successor->key);
		}
	}
	if(curr==NULL){
		return curr;
	}
	curr->height=max(getheight(curr->left),getheight(curr->right))+1;
	int balance=getbf(curr);
	
	if(balance > 1 && getbf(curr->left)>=0){
		return rightrotate(curr);
	}
	else if(balance > 1 && getbf(curr->left)<0){
		curr->left=leftrotate(curr->left);
		return rightrotate(curr);
	}
	else if(balance < -1 && getbf(curr->right)<=0){
		return leftrotate(curr);
	}
	else if(balance < -1 && getbf(curr->right)>0){
		curr->right=rightrotate(curr->right);
		return rightrotate(curr);
	}
}
int main(){
	node *root=NULL;
	root=insert(root,10);
	root=insert(root,65);
	root=insert(root,100);
	root=insert(root,70);
	root=insert(root,20);
	preorder(root);
	puts("");
	deletevalue(root,10);
	preorder(root);
	getchar();
	return 0;
}
