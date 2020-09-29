#include<stdio.h>
#include<stdlib.h>
#define MAXN 1000000

bool ada [MAXN+1]={0};
long long count=0;
long long banyakData=0;
long long smallerThanX=0;

struct node {
	int height;
	long long key;
	struct node *left;
	struct node *right;
};

struct node *predecessor(node *root)
{
	struct node *temp = root->left;
	while(temp->right !=NULL)
	{
		temp = temp->right;
	}
	return temp;
}

long long max (long long a,long long b)
{
	if(a > b ) return a;
	else return b;
}
int getHeight(struct node* root)
{
	if(root==NULL) return 0;
	else return root->height;
}

int getBalance(struct node *root)
{
	if(root==NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}
struct node *newNode(long long value)
{
	struct node *currNewNode = (struct node*) malloc(sizeof(node));
	currNewNode->height=1;
	currNewNode->key=value;
	currNewNode->left=NULL;
	currNewNode->right=NULL;
	ada[value] = true;
	banyakData++;
	return currNewNode;
}
struct node *leftRotate(struct node *root)
{
	struct node *x = root->right;
	struct node *B = x->left;
	
	x->left = root;
	root->right = B;
	
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
	x->height = max(getHeight(x->left),getHeight(x->right))+1;
	
	return x;
}
struct node *rightRotate(struct node *root)
{
	struct node *x = root->left;
	struct node *B = x->right;
	
	x->right = root;
	root->left = B;
	
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
	x->height = max(getHeight(root->left),getHeight(root->right))+1;
	
	return x;
}
struct node *insert(node *root,long long value){
	if(root== NULL) return newNode(value);
	else if(value > root->key)
	{
		root->right = insert(root->right,value);	
	}
	else if(value < root->key)
	{
		root->left = insert(root->left,value);
	}
	
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
	
	int balance = getBalance(root);
	
	if(balance > 1 && value > root->left->key)
	{
		//LR
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	else if(balance > 1 && value < root->left->key)
	{
		//LL
		return rightRotate(root);
	}
	else if(balance < -1 && value > root->right->key)
	{
		//RR
		return leftRotate(root);
	}
	else if(balance < -1 && value < root->right->key)
	{
		//RL
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
struct node *deleteNode(node *root,long long value)
{
	if (root==NULL) return NULL;
	if(value < root->key)
	{
		root->left = deleteNode(root->left,value);
	}
	else if(value > root->key)
	{
		root->right = deleteNode(root->right,value);
	}
	else
	{
		ada[value]=false;
		banyakData--;
		if(root->right == NULL || root->left ==NULL)
		{
			struct node *temp =NULL;
			if(root->right != NULL) temp = root->right;
			else temp = root->left;
			
			if(temp==NULL)
			{//tidak punya anak
				temp= root;
				root=NULL;
			}
			else
			{
				*root = *temp;//punya anak kiri
								//punya anak kanan
			}
		}
		//punya anak kanan dan kiri
		else
		{
			struct node *temp = predecessor(root);
			root->key = temp->key;
			
			root->left = deleteNode(root->left,temp->key);
		}
	}
	if(root==NULL) return NULL;
	
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
	
	int balance = getBalance(root);
	
	if(balance > 1 && getBalance(root->left)>=0)
	{
		//LL
		return rightRotate(root);
	}
	else if(balance > 1 && getBalance(root->left)<0)
	{
		//LR
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	else if(balance <-1 && getBalance(root->right)<=0)
	{
		//RR
		return leftRotate(root);
	}
	else if(balance < -1 && getBalance(root->right)>0)
	{
		//RL
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
long long show(node *root,long long x)
{
	if (root==NULL) return NULL;
	show(root->left,x);
	count++;
	if(count==x) return root->key;
}
void countt(node *root,long long value)
{
	if(root==NULL) return;
	countt(root->left,value);
	if(root->key<value) smallerThanX++;
	countt(root->right,value);
}
int main()
{
	struct node *root = NULL;
	long long n;
	scanf("%lld",&n);
	getchar();
	for(long long i=0;i<n;i++)
	{
		char karakter;
		long long temp;
		scanf("%c %lld",&karakter,&temp);
		getchar();
		if(karakter=='I')
		{
			if(!ada[temp])
			root = insert(root,temp);
		}
		else if (karakter=='D')
		{
			if(ada[temp])
			root = deleteNode(root,temp);
		}
		else if(karakter=='K')
		{
			count =0;
			if(banyakData<temp)
			{
				printf("invalid\n");
			}
			else
			{
				long long kth = show(root,temp);
				printf("%lld\n",kth);
			}
		}
		else if(karakter=='C')
		{
			smallerThanX=0;
			countt(root,temp);
			printf("%lld\n",smallerThanX);
		}
	}
}
