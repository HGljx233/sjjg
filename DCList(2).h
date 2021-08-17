#ifndef _DCLIST_H_
#define _DCLIST_H_

#include"Common.h"

typedef struct DCListNode
{
	ElemType data;
	struct DCListNode* next;
	struct DCListNode* prev;
}DCListNode;

typedef struct DCList
{
	DCListNode* head;
}DCList;

DCListNode* _Buynode(ElemType v);
void DCListInit(DCList* plist);

void DCListPushBack(DCList* plist, ElemType v);
void DCListPushFront(DCList* plist, ElemType v);
void DCListPopBack(DCList* plist);

void DCListInsertByVal(DCList* plist, ElemType v);

DCListNode* DCListFind(DCList* plist, ElemType key);
void DCListErase(DCList* plist, ElemType key);

void DCListShow(DCList* plist);
void DCListPopFront(DCList* plist);
void DCListDestroy(DCList* plist);
void DCListSort(DCList* plist);

size_t DCListLength(DCList* plist);
void DCListClear(DCList* plist);
DCListNode* _Buynode(ElemType v)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = v;
	s->next = s->prev = s;
	return s;
}

void DCListInit(DCList* plist)
{
	assert(plist);
	DCListNode* head = _Buynode(-1);
	plist->head = head;
	plist->head->next = plist->head;
	plist->head->prev = plist->head;

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
	DCListNode* p = plist->head->next;
	if (p == NULL)
		return ;
	p->next->prev = plist->head;
	p->prev->next = p->next;
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
void DCListClear(DCList* plist)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);

		p = plist->head->next;
	}
}
void DCListDestroy(DCList* plist)
{
	DCListClear(plist);
	free(plist->head);
	plist->head = NULL;
}
void DCListSort(DCList* plist) {
	size_t size = DCListLength(plist);
	if (size < 1)
		return;
	DCListNode* p = plist->head->next;
	DCListNode* q = p ->next;
	p->next = plist->head;
	plist->head->prev = p;
	while (q!=plist->head) {
		p = q;
		q = q->next;
		//寻找插入的位置
		DCListNode* pos = plist->head->next;
		while (pos != plist->head && p->data > pos->data)
			pos = pos->next;
		//插入节点
		p->next = pos;
		p->prev = pos->prev;
		p->next->prev = p;
		p->prev->next = p;
	}
}
size_t DCListLength(DCList* plist) {
	DCListNode* p = plist->head->next;
	int i = 0;
	while (p != plist->head) {
		i++;
		p = p->next;
	}
	return i;
}

#endif /* _DCLIST_H_ */