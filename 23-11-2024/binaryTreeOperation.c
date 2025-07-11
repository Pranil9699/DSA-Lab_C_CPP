#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node * right;
};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

struct Node* insert(struct Node* root,int data){
	if(root==NULL){
		return createNode(data);
	}
	
	if(data < root->data){
		root->left = insert(root->left,data);
	}else if(data > root->data){
		root->right = insert(root->right , data);
	}
	return root;
}

struct Node* findMin(struct Node* root){
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

struct Node* delete(struct Node* root,int data){
	if(root==NULL){
		return root;
	}
	
	if(data < root->data){
		root->left = delete(root->left,data);
		
	}else if(data > root->data){
		root->right = delete(root->right,data);
	}
	else{
		
		if(root->left== NULL){
			struct Node *temp= root->right;
			free(root);
			return temp;
		}else if(root->right == NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		
		struct Node* temp = findMin(root->right);
		root->data = temp->data;
		root->right = delete(root->right,temp->data);
	}
	
	return root;
}

struct Node* search(struct Node* root,int key){
	if(root == NULL){
		return root;
	}
	
	if(key < root->data){
		return search(root->left,key);
	}
	return search(root->right,key);
}

void inOrderTraversal(struct Node* root){
	if(root != NULL){
		inOrderTraversal(root->left);
		printf("%d ",root->data);
		inOrderTraversal(root->right);
	}
}


int main(){
	struct Node* root = NULL;
	
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,80);
	
	printf("\n Inorder traversal of the BST:\n");
	inOrderTraversal(root);
	printf("\n");
	
	//deletin
	
	printf("Deleting 20 ... \n");
	root = delete(root,20);
	printf("Inorder traversal after deletion\n");
	inOrderTraversal(root);
	printf("\n");
	
	// Searching ....
	int key = 40;
	if(search(root,key) != NULL){
		printf(" Key %d found in the BST.\n",key);
	}else{
		printf("key %d not found in the BST.\n",key);
	}
	
	return 0;
}
