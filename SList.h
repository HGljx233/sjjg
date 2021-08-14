#pragma once
#include"Common.h"
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
void SListInit(SListNode** pplist);
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SListNode* plist);
SListNode* BuySListNode(SLTDateType x) {
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
void SListPrint(SListNode* plist) {
	SListNode* p = plist;
	while(p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
void SListPushBack(SListNode** pplist, SLTDateType x) {
	SListNode* s = BuySListNode(x);
	SListNode* p = *pplist;

	if (p ==NULL) {
		*pplist = s;
		return;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}
void SListPushFront(SListNode** pplist, SLTDateType x) {
	SListNode* s = BuySListNode(x);
	s->next = *pplist;
	*pplist = s;
}
void SListPopBack(SListNode** pplist) {
	SListNode* p = *pplist;
	SListNode* prev = NULL;//前驱结点
	if (*pplist == NULL)
		return;
	while (p->next != NULL) {

		prev = p;
		p = p->next;
	}
	if (prev == NULL)
		*pplist = NULL;

	else prev->next = NULL;
	free(p);
}
void SListPopFront(SListNode** pplist) {
	SListNode* p = *pplist;
	if (*pplist == NULL)
		return;
	*pplist = p->next;
	free(p);
}
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	SListNode* p = plist;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	return p;
}
// 单链表在第 i 个结点位置之后插入x
void SListInsertAfter(SListNode** pplist, int i, SLTDateType x) {
	SListNode* p = *pplist;
	SListNode* s = BuySListNode(x);
	while (i) {
		p = p->next;
		i--;
	}
	s->next = p->next;
	p->next = s;
}

// 单链表删除第 i 个结点位置之后的值

void SListEraseAfter(SListNode* plist, int i) {
	SListNode* p = plist;
	SListNode* next;
	while (i) {
		p = p->next;
		i--;
	}
	next = p->next;
	p->next = next->next;
	free(next);
}
void SListInit(SListNode** pplist)
{
	*pplist = NULL;
}

//单链表的销毁
void SListDestory(SListNode** pplist) {
	
	SListNode* p = NULL;
	while (*pplist != NULL) {
		p = *pplist;
	
	*pplist = p->next;
	free(p);
}
}
