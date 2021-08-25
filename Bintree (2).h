#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"Common.h"
//#include"Queue.h"
typedef  char ElemType;
typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

typedef  BinTreeNode* BinTree;
void BinTreeInit(BinTree* t);

//二叉树的创建
void BinTreeCreate_1(BinTree* t);
BinTree BinTreeCreate_2();
BinTree BinTreeCreate_3(char* str, int* i);

//二叉树的遍历
void BinTreePreOrder(BinTree t);
void BinTreeInOrder(BinTree t);
void BinTreePostOrder(BinTree t);
void BinTreeLevelOrder(BinTree t);

//二叉树的功能
size_t Size(BinTree t);
size_t Height(BinTree t);
BinTreeNode* Find(BinTree t, ElemType key);
BinTreeNode* Parent(BinTree t, BinTreeNode* p);

BinTreeNode* Clone(BinTree t);
bool Equal(BinTree t1, BinTree t2);

void BinTreeInit(BinTree* t)
{
	*t = NULL;
}
void BinTreeCreate_1(BinTree* t)
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate_1(&(*t)->leftChild);
		BinTreeCreate_1(&(*t)->rightChild);
	}
}

BinTree BinTreeCreate_2()
{
	BinTreeNode* t;
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;

	t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = item;
	t->leftChild = BinTreeCreate_2();
	t->rightChild = BinTreeCreate_2();
	return t;
}

BinTree BinTreeCreate_3(char* str, int* i)
{
	BinTreeNode* t;
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = str[*i];
	(*i)++;
	t->leftChild = BinTreeCreate_3(str, i);
	(*i)++;
	t->rightChild = BinTreeCreate_3(str, i);
	return t;
}

size_t Size(BinTree t)
{
	if (t == NULL)
		return 0;

	return Size(t->leftChild) + Size(t->rightChild) + 1;
}

size_t Height(BinTree t)
{
	size_t left_h, right_h;
	if (t == NULL)
		return 0;

	left_h = Height(t->leftChild);
	right_h = Height(t->rightChild);
	return (left_h > right_h ? left_h : right_h) + 1;
}

BinTreeNode* Find(BinTree t, ElemType key)
{
	BinTreeNode* p;
	if (t == NULL || t->data == key)
		return t;
	p = Find(t->leftChild, key);
	if (p != NULL)
		return p;
	return Find(t->rightChild, key);
}

BinTreeNode* Parent(BinTree t, BinTreeNode* p)
{
	BinTreeNode* ret;
	if (t == NULL || t->leftChild == p || t->rightChild == p)
		return t;
	ret = Parent(t->leftChild, p);
	if (ret != NULL)
		return ret;
	return Parent(t->rightChild, p);
}

void BinTreePreOrder(BinTree t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		BinTreePreOrder(t->leftChild);
		BinTreePreOrder(t->rightChild);
	}
}

void BinTreeInOrder(BinTree t)
{
	if (t != NULL)
	{
		BinTreeInOrder(t->leftChild);
		printf("%c ", t->data);
		BinTreeInOrder(t->rightChild);
	}
}

void BinTreePostOrder(BinTree t)
{
	if (t != NULL)
	{
		BinTreePostOrder(t->leftChild);
		BinTreePostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}

//void BinTreeLevelOrder(BinTree t)
//{
//	if (t != NULL)
//	{
//		LinkQueue Q;
//		LinkQueueInit(&Q);
//		LinkQueuePush(&Q, t);
//		while (!LinkQueueEmpty(&Q))
//		{
//			BinTreeNode* node = LinkQueueFront(&Q);
//			LinkQueuePop(&Q);
//			printf("%c ", node->data);
//			if (node->leftChild != NULL)
//				LinkQueuePush(&Q, node->leftChild);
//			if (node->rightChild != NULL)
//				LinkQueuePush(&Q, node->rightChild);
//		}
//	}
//}
BinTreeNode* Clone(BinTree t) {
	BinTreeNode* p;
	if (t == NULL)
		return NULL;
	p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(p != NULL);
	p->data = t->data;
	p->leftChild = Clone(t->leftChild);
	p->rightChild = Clone(t->rightChild);
	return p;
}
bool Equal(BinTree t1, BinTree t2) {
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return ((t1->data == t2->data) 
		&& (t1->leftChild == t2->leftChild) 
		&& (t1->rightChild == t2->rightChild));
}
/*
BinTree BinTreeCreate_3(char *str)
{
	BinTreeNode *t;
	if(*str=='#' || *str=='\0')
		return NULL;
	t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = *str;
	t->leftChild = BinTreeCreate_3(++str);
	t->rightChild = BinTreeCreate_3(++str);
	return t;
}

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root; //树根
}BinTree;

void BinTreeInit(BinTree *t);
void _BinTreeCreate(BinTreeNode **t);
void BinTreeCreate(BinTree *t);

void BinTreeInit(BinTree *t)
{
	t->root = NULL;
}

void _BinTreeCreate(BinTreeNode **t)
{
	ElemType item;
	scanf("%c", &item);
	if(item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BinTreeCreate(&(*t)->leftChild);
		_BinTreeCreate(&(*t)->rightChild);
	}
}
void BinTreeCreate(BinTree *t)
{
	_BinTreeCreate(&(t->root));
}
*/

#endif /* _BINTREE_H_ */