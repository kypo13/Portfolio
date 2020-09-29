#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	
	int key;
	struct node *left, *right;	
	int height;
};

int max ( int nodeA, int nodeB) {
	if (nodeA > nodeB) return nodeA;
	else return nodeB;
}

int getHeight ( struct node *root) {
	
	if ( root == NULL) return 0;
	else return root->height;
}

int getBalance ( struct node *root) {
	if ( root == NULL) return 0;
	else return getHeight(root->left)-getHeight(root->right);
}

struct node *rightRotate ( struct node *y) {
	
	struct node *x = y->left;
	struct node *B = x->right;
	
	x->right = y;
	y->left  = B;
	
	y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	
	return x; //karena x pada posisi rootnya
}

struct node *leftRotate ( struct node *y) {
	
	struct node *x = y->right;
	struct node *B = x->left;
	
	x->left = y;
	y->right = B;
	
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
	
	return x;
}


struct node *newNode(int key){
	
	struct node *currNewNode = 
	(struct node*)malloc(sizeof(node)); 
	
	currNewNode->height = 1; // AVL
	currNewNode->key = key;
	currNewNode->left = NULL;
	currNewNode->right = NULL;
	
	return currNewNode;
}

struct node *insertNode( struct node *root,int value){
	
	if ( root == NULL) return newNode(value);
	  else if ( value < root->key) {
		root->left = insertNode(root->left,value);
	} else if ( value > root->key) {
		root->right = insertNode(root->right,value);
	}
	
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
	
	int balance  = getBalance(root);
	
	// Left Left 
	if ( balance > 1 && value < root->left->key) {
		return rightRotate(root);
	}
	
	//Left Right 
	if ( balance > 1 && value > root->left->key) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	// Right Right
	if ( balance < -1  && value > root->right->key) {
		return leftRotate(root);
	}
	
	// Right Left 
	if ( balance < -1 && value < root->right->key) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

//
//void printAll( struct node *root) {
//
//	if ( root == NULL) {
//	
//	    return;	
//	    
//	}
//
//		printAll(root->left);
//		printf("%d ",root->key);
//		printAll(root->right);
//	
//	
//}

void printAllMinimum( struct node *root) {

	if ( root->left == NULL) {
		printf("%d\n",root->key);
	    return;	
	}
	printAllMinimum(root->left);	
		
}

struct node *freeAll(struct node *root) {
	
	if ( root == NULL) {
		
		return NULL;
	} else {
		root->left = freeAll(root->left);
		root->right = freeAll(root->right);
		free(root);
		return NULL;	
	}
	
}

struct node *predecessor ( struct node *root) {
	
	struct node *currPredecessor = root->left;
	
	while ( currPredecessor->right != NULL) {
		currPredecessor = currPredecessor->right;
	}
	
	return currPredecessor;
}

struct node *deleteNode( struct node *root, int valueDelete) {
	
	if ( root == NULL) return NULL;
	  else if ( valueDelete < root->key) {
		root->left = deleteNode(root->left,valueDelete);
	} else if ( valueDelete > root->key) {
		root->right = deleteNode(root->right,valueDelete);
	} else {
		//ketemu
		// case 1 : tidak punya anak
		// case 2 : hanya punya anak kanan
		// case 3 : hanya punya anak kiri
		// case 4 : punya cucu
		
		if ( root->left == NULL || root->right == NULL) {
			struct node *temp = NULL;
			
			if ( root->left != NULL) {
				temp = root->left;
			} else if ( root->right != NULL) {
				temp = root->right;
			}
			//case 1
			if ( temp == NULL) {
				temp = root;
				root = NULL;
			} else  {
			//case 2 dan 3
				*root = *temp;
			}
			free(temp);
		} else {
			//case 4 
			//cari predecessor
			struct node *temp = predecessor(root);
			root->key = temp->key;
			root->left = deleteNode(root->left,temp->key);
		}
	}
	
	if ( root == NULL) {
		return root;
	}
	
	root->height = max(getBalance(root->right),getHeight(root->right)) + 1;
	int balance = getBalance(root);
	
	//Left Left
	if ( balance > 1 && getBalance(root->left) >= 0) {
		return rightRotate(root);
	}
	
	// Left Right 
	if ( balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	//Right Right 
	if ( balance < -1 && getBalance(root->right) <= 0) {
		
		return leftRotate(root);
	}
	
	//Right Left 
	if ( balance < -1 && getBalance(root->right) > 0) {
		
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

int main() {
	struct node *root = NULL;
	
	int inputData = 0;
	char data[10];
	
	scanf("%d",&inputData);
	getchar();
	for ( int i = 0; i < inputData; i++) {
		
		gets(data);
		// 3
		// 1 4
		// 1 9
		// 3
		if ( data[0] == '1') {
			strcpy(data,&data[2]);
			int inputAngka = atoi(data);
			root = insertNode(root,inputAngka);
			
		} else if ( data[0] == '2') {
			strcpy(data,&data[2]);
			int deleteAngka = atoi(data);
			root = deleteNode(root,deleteAngka);
			
		} else if ( data[0] == '3') {
			printAllMinimum(root);
			//printf("%d\n",root->key);
		}
		
		
	}
	
	return 0;
}
