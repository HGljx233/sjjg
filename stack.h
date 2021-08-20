#pragma once
#include"Common.h"
#define SEQ_STACK_DEFAULT_SIZE 8
//Ë³ĞòÕ»
#define INC_SIZE 5
typedef struct SeqStack {
	ElemType* base;//Õ»¿Õ¼ä
	size_t capacity;
	size_t top;//Õ»¶¥Ö¸Õë
}SeqStack;
bool isFull(SeqStack* pst);
bool isEmpty(SeqStack* pst);
bool _Inc(SeqStack* pst);
void SeqStackInit(SeqStack* pst, int size);
void SeqStackPush(SeqStack* pst, ElemType v);
void SeqStackPop(SeqStack* pst);
ElemType SeqStackTop(SeqStack* pst);
void SeqStackShow(SeqStack* pst);
void SeqStackDestroy(SeqStack* pst);
int SeqStackSize(SeqStack* pst);
bool isFull(SeqStack* pst) {
	return pst->top >= pst->capacity;
}
bool isEmpty(SeqStack* pst) {
	return pst->top == 0;
}
void SeqStackInit(SeqStack* pst, int sz) {
	pst->capacity = sz > SEQ_STACK_DEFAULT_SIZE ? sz : SEQ_STACK_DEFAULT_SIZE;
	pst->base = (ElemType*)malloc(sizeof(ElemType) * pst->capacity);
	assert(pst->base != NULL);
	pst->top = 0;
}
void SeqStackPush(SeqStack* pst, ElemType v)
{
	if (isFull(pst))
	{
		printf("Õ»ÒÑÂú,%d²»ÄÜÈëÕ».\n", v);
		return;
	}
	pst->base[pst->top++] = v;
}

void SeqStackPop(SeqStack* pst)
{
	if (isEmpty(pst))
	{
		printf("Õ»ÒÑ¿Õ£¬²»ÄÜ³öÕ».\n");
		return;
	}
	pst->top--;
}
ElemType SeqStackTop(SeqStack* pst)
//void SeqStackTop(SeqStack *pst, ElemType *v) //³ö²Î
{
	if (isEmpty(pst))
	{
		printf("Õ»ÒÑ¿Õ£¬Ã»ÓĞÕ»¶¥ÔªËØ.\n");
		return;
	}
	return pst->base[pst->top-1];
	//*v = pst->base[pst->top-1];
}

void SeqStackShow(SeqStack* pst) {
	for (int i = pst->top-1; i >= 0; --i) {
		printf("%d\n", pst->base[i]);
	}
}
void SeqStackDestroy(SeqStack* pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;

}

bool _Inc(SeqStack* pst)
{
	pst->base = (ElemType*)realloc(pst->base, sizeof(ElemType) * (pst->capacity + INC_SIZE));
	if (pst->base == NULL)
		return false;
	pst->capacity += INC_SIZE;
	return true;
}
int SeqStackSize(SeqStack* pst) {
	return pst->top;
}
//Á´Õ»
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode* next;
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode* head;
}LinkStack;

void LinkStackInit(LinkStack* pst);
void LinkStackPush(LinkStack* pst, ElemType v);
void LinkStackPop(LinkStack* pst);
ElemType LinkStackTop(LinkStack* pst);
void LinkStackShow(LinkStack* pst);
void LinkStackDestroy(LinkStack* pst);

void LinkStackInit(LinkStack* pst)
{
	pst->head = NULL;
}
void LinkStackPush(LinkStack* pst, ElemType v) {
	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(s != NULL);
	s->data = v;
	s->next = NULL;
	pst->head = s;
}
void LinkStackPop(LinkStack* pst) {
	LinkStackNode* p;
	if (pst->head == NULL)
		return;
	p = pst->head;
	pst->head = p->next;
	free(p);
}
ElemType LinkStackTop(LinkStack* pst) {
	assert(pst->head != NULL);
		return pst->head->data;
}
void LinkStackShow(LinkStack* pst) {
	LinkStackNode* p = pst->head;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
}
void LinkStackDestroy(LinkStack* pst)
{
	LinkStackNode* p = pst->head;
	while (p != NULL)
	{
		pst->head = p->next;
		free(p);
		p = pst->head;
	}
}



