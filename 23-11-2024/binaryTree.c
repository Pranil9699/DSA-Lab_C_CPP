#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}
void inOrderTraversal(struct Node* root){
	if(root != NULL){
		inOrderTraversal(root->left);
		printf("%d ",root->data);
		inOrderTraversal(root->right);
	}
}
void preOrderTraversal(struct Node* root){
	if(root != NULL){
		
		printf("%d ",root->data);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

void postOrderTraversal(struct Node* root){
	if(root != NULL){
		
		
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		printf("%d ",root->data);
	}
}
int main(){
	struct Node* root= createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	
	printf("Inorder Traversal:\n");
	inOrderTraversal(root);
	printf("\n");
	
	printf("Preorder Traversal:\n");
	preOrderTraversal(root);
	printf("\n");
	
	printf("Postorder Traversal:\n");
	postOrderTraversal(root);
	printf("\n");
	
	return 0;
}
