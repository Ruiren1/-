#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int BTDatatype;
typedef struct BinaryTreeNoDe
{
	BTDatatype data;
	struct BinaryTreeNoDe* left;
	struct BinaryTreeNoDe* right;
}BTNode;
BTNode* BuyNode(BTDatatype a)
{
	BTNode* node = (BTNode*)malloc(sizeof(struct BinaryTreeNoDe));
	assert(node);
	node->data = a;
	assert(node);
	return node;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return ;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return ;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);

}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return ;
	}
	InOrder(root->left);
	InOrder(root->right);
	printf("%d ", root->data);
}
BTNode* BinaryFind(BTNode* root, BTDatatype x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode*left=BinaryFind(root->left,x);
	if (left)
	{
		return left;
	}
	BTNode* right = BinaryFind(root->right, x);
	if (right)
	{
		return right;
	}
	return 	NULL;
}
int SizeTree(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return SizeTree(root->left) + SizeTree(root->right) + 1;
}
int HeightTree(BTNode* root)
{
	if (root == NULL)
	return 0;
	int leftheight = HeightTree(root->left);
	int rightheight = HeightTree(root->right);
	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}
int LevelTree(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	/*int leftk = LevelTree(root->left, k - 1);
	int right = LevelTree(root->right, k - 1);*/
	return LevelTree(root->left, k - 1)+ LevelTree(root->right, k - 1);
}
//void LevelOrder(BTNode* root)
//{
//	Queue tree;
//	Queue* pt = &tree;
//	QueueInit(pt);
//	QueuePush(pt,root);
//	while (!QueueEmpty(pt))
//	{
//		BTNode* front = QueueFront(pt);
//		printf("%d", front->data);
//		QueuePop(pt);
//		if (front->left)
//		{
//			QueuePush(pt, front->left);
//		}
//		if (front->right)
//		{
//			QueuePush(pt, front->right);
//		}
//	}
//	QueueDestroy(pt);
//}
//BTNode* CreatBinaryTree(BTDatatype* arr, int* i)
//{
//	if (arr[*i]==NULL)
//	{
//		(*i)++;
//		return NULL;
//	}
//
//	BTNode* root = BuyNode(arr[(*i)++]);
//	root->left = CreatBinaryTree(arr, i);
//	root->right = CreatBinaryTree(arr, i);
//
//	return root;
//
//}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node2->right = NULL;
	node3->left = NULL;
	node3->right = NULL;
	node5->left = NULL;
	node5->right = NULL;
	node6->left = NULL;
	node6->right = NULL;
	return node1;
}
int main()
{
	BTNode* node1 = CreatBinaryTree();
	PreOrder(node1);
	printf("\n");
	InOrder(node1);
	printf("\n");
	PostOrder(node1);
	printf("\n");
	printf("%d", HeightTree(node1));
	printf("\n");
	printf("%d", SizeTree(node1));
	printf("\n");
	printf("%d", LevelTree(node1,4));
	printf("\n");
	//LevelOrder(node1);
}