#pragma once
#include"Common.h"
typedef struct DCListNode {
	ElemType data;
	struct DCListNode* next;
	struct DCListNode* prev;
}DCListNode;
typedef struct DCList {
	DCListNode* head;
}DCList;
DCListNode* _Buynode(ElemType v);
void DCListInit(DCList* plist);

void DCListPushBack(DCList* plist, ElemType v);
void DCListPushFront(DCList* plist, ElemType v);
void DCListPopBack(DCList* plist);
void DCListPopFront(DCList* plist);
void DCListInsertByVal(DCList* plist, ElemType v);
DCListNode* DCListFind(DCList* plist, ElemType key);
void DCListErase(DCList* plist, ElemType key);

void DCListShow(DCList* plist);

DCListNode* _Buynode(ElemType v)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = v;
	s->prev = s->next = s;
	return s;
}
void DCListInit(DCList* plist)
{
	plist->head = _Buynode(0);
}
void DCListPushBack(DCList* plist, ElemType v)
{
	DCListNode* s = _Buynode(v);
	s->next = plist->head;
	s->prev = plist->head->prev;
	s->next->prev = s;
	s->prev->next = s;
}

void DCListPushFront(DCList* plist, ElemType v)
{
	DCListNode* s = _Buynode(v);
	s->next = plist->head->next;
	s->prev = plist->head;
	s->next->prev = s;
	s->prev->next = s;
}

void DCListPopBack(DCList* plist)
{
	DCListNode* p;
	if (plist->head->next == plist->head)
		return;

	//查找最后一个节点
	p = plist->head->prev;

	//删除节点
	p->next->prev = p->prev;
	p->prev->next = p->next;

	free(p);
}
void DCListPopFront(DCList* plist) {
	DCListNode* p;
	p = plist->head->next;
	p->next->prev = plist->head;
	p->prev->next = plist->next;
	free(p);
}
void DCListInsertByVal(DCList* plist, ElemType v)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head && v > p->data)
		p = p->next;
	DCListNode* s = _Buynode(v);
	s->next = p;
	s->prev = p->prev;
	s->next->prev = s;
	s->prev->next = s;
}

DCListNode* DCListFind(DCList* plist, ElemType key)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head && key != p->data)
		p = p->next;
	if (p == plist->head)
		return NULL;
	return p;
}

void DCListErase(DCList* plist, ElemType key)
{
	DCListNode* p = DCListFind(plist, key);
	if (p == NULL)
		return;

	p->next->prev = p->prev;
	p->prev->next = p->next;

	free(p);
}

void DCListShow(DCList* plist)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}