#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int value)
{
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));
	node->value=value;
	node->left=NULL;
	node->right=NULL;
	return(node);
}

int addNodes(struct Node* iter)
{
	int Sum;
	if(iter==NULL)
		return 0;
	Sum=iter->value+addNodes(iter->left)+addNodes(iter->right);
	return Sum;
}

int maxSum(struct Node* root){

	if(root==NULL)
		return 0;

	if(maxSum(root->left)>maxSum(root->right))
		return maxSum(root->left)+root->value;

	else
		return maxSum(root->right)+root->value;
		
}

int main()
{
	struct Node* root=newNode(1);
	root->left=newNode(5);
	root->right=newNode(10);
	root->left->left=newNode(20);
	root->left->left->left=newNode(999);
	root->right->left=newNode(21);
	root->right->right=newNode(20);
	root->right->right->right=newNode(15);
	root->right->left->left=newNode(13);
	root->left->right=newNode(4);

	printf("max sum of tree nodes: %d\n",maxSum(root));
	return 0;
}
