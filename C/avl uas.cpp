#include<stdio.h>
#include<stdlib.h>

struct node{
	int height;
	int key;
	node *left,*right;
};

int max(int a,int b){
	if(a<b)return b;
	else return a;
}

int getheight(node *curr){
	if(curr==NULL){
		return NULL;
	}
	return curr->height;
}

int getbf(node *curr){
	if(curr==NULL){
		return NULL;
	}
	return getheight(curr->left)-getheight(curr->right);
}

node *rightrotate(node *x){
	node *y=x->left;
	node *B=y->right;
	
	y->right=x;
	x->left=B;
	
	x->height=max(getheight(x->left),getheight(x->right))+1;
	y->height=max(getheight(y->left),getheight(y->right))+1;
	
	return y;
}

node *leftrotate(node *x){
	node *y=x->right;
	node *B=y->left;
	
	y->left=x;
	x->right=B;
	
	x->height=max(getheight(x->left),getheight(x->right))+1;
	y->height=max(getheight(y->left),getheight(y->right))+1;
	
	return y;
}

node *newnode(int key){
	node *temp=(node*)malloc(sizeof(node));
	temp->height=1;
	temp->key=key;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

node *predecessor(node *curr){
	node *temp=curr->left;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}

node *insert(node *curr,int x){
	if(curr==NULL)return newnode(x);
	else if(x<curr->key){
		curr->left=insert(curr->left,x);
	}
	else if(x>curr->key){
		curr->right=insert(curr->right,x);
	}
	
	curr->height=max(getheight(curr->left),getheight(curr->right))+1;
	int bfactor=getbf(curr);
	
	if(bfactor>1 && x<curr->left->key){
		return rightrotate(curr);
	}
	else if(bfactor>1 && x>curr->left->key){
		curr->left=leftrotate(curr->left);
		return rightrotate(curr);
	}
	else if(bfactor<-1 && x>curr->right->key){
		return leftrotate(curr);
	}
	else if(bfactor<-1 && x<curr->right->key){
		curr->right=rightrotate(curr->right);
		return leftrotate(curr);
	}
	return curr;
}

node *deletevalue(node *curr,int x){
	if(curr==NULL){
		return NULL;
	}
	else if(x>curr->key){
		curr->right=deletevalue(curr->right,x);
	}
	else if(x<curr->key){
		curr->left=deletevalue(curr->left,x);
	}
	else{
		if(curr->left==NULL||curr->right==NULL){
			node *temp=NULL;
			if(curr->left!=NULL)temp=curr->left;
			else temp=curr->right;
			if(temp==NULL){
				temp=curr;
				curr=NULL;
			}
			else{
				*curr=*temp;
			}
			free(curr);
		}
		else{
			node *temp=predecessor(curr);
			curr->key=temp->key;
			curr->left=deletevalue(curr->left,temp->key);
		}
	}
	if(curr==NULL)return NULL;
	
	curr->height=max(getheight(curr->left),getheight(curr->right))+1;
	int bfactor=getbf(curr);
	
	if(bfactor>1 && bfactor>=0){
		return rightrotate(curr);
	}
	else if(bfactor>1 && bfactor<0){
		curr->left=leftrotate(curr->left);
		return rightrotate(curr);
	}
	else if(bfactor<-1 && bfactor<=0){
		return leftrotate(curr);
	}
	else if(bfactor<-1 && bfactor>0){
		curr->right=rightrotate(curr->right);
		return leftrotate(curr);
	}
	return curr;
}

void printall(node *root){
	if(root==NULL)return;
	printall(root);
	printf("%d ",root->key);
	printall(root);
}
void printminimum(node *root){
	if(root->left==NULL){
		printf("%d",root->key);
		return;
	}
	else{
		printminimum(root->left);
	}
}
node *freeall(node *root){
	if(root==NULL)return NULL;
	freeall(root->left);
	freeall(root->right);
	free(root);
	return NULL;
}

int main()
{
	node *root=NULL;
	root=insert(root,50);
	root=insert(root,60);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,130);
	root=insert(root,20);
	root=insert(root,90);
	printall(root);
	return 0;
}

