#pragma once
#include"Common.h"
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
void SListInit(SListNode** pplist);
// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
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
	SListNode* prev = NULL;//ǰ�����
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
// �������ڵ� i �����λ��֮�����x
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

// ������ɾ���� i �����λ��֮���ֵ

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

//�����������
void SListDestory(SListNode** pplist) {
	
	SListNode* p = NULL;
	while (*pplist != NULL) {
		p = *pplist;
	
	*pplist = p->next;
	free(p);
}
}
