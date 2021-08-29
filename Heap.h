#pragma once

//二叉树的顺序存储->完全二叉树;
#include"Common.h"
#define HeapElemType int//默认情况 大堆
typedef struct Heap
{
	HeapElemType* heap;
	size_t        capacity;
	size_t        size;
}Heap;
//函数定义
bool HeapIsFull(Heap* php);
bool HeapIsEmpty(Heap* php);
void HeapInit(Heap* php, int sz);
void HeapCreate(Heap* php, HeapElemType ar[], int n);
HeapElemType HeapTop(Heap* php);
void HeapInsert(Heap* php, HeapElemType v);
void HeapRemove(Heap* php);
void HeapShow(Heap* php);
void _AdjustUp(Heap* php, int start);
void _AdjustDown(Heap* php, int start);
void HeapDestroy(Heap* php);
//函数实现
bool HeapIsFull(Heap* php) {
	return php->size >= php->capacity;
}
bool HeapIsEmpty(Heap* php) {
	return php->size == 0;
}
void HeapInit(Heap* php, int size) {
	php->capacity = size;
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * php->capacity);
	assert(php->heap != NULL);
	php->size = 0;
}
void HeapInsert(Heap* php, HeapElemType v) {
	if (HeapIsFull(php)) {
		printf("堆空间已满,%d不能插入\n", v);
		return;
	}
	php->heap[php->size] = v;
	_AdjustUp(php, php->size);
	php->size++;
}
HeapElemType HeapTop(Heap* php)
{
	if (HeapIsEmpty(php))
	{
		printf("堆已空，不能取堆顶元素.\n");
		return;
	}
	return php->heap[0];
}
void HeapRemove(Heap* php)
{
	if (HeapIsEmpty(php))
	{
		printf("堆已空，不能删除数据.\n");
		return;
	}
	//删除数据
	HeapElemType tmp = php->heap[0];
	php->heap[0] = php->heap[php->size - 1];
	php->heap[php->size - 1] = tmp;
	php->size--;
	//从根开始调整堆
	_AdjustDown(php, 0);
}
void HeapShow(Heap* php) {
	for (int i = 0; i < php->size; i++) {
		printf("%d ", php->heap[i]);
	}printf("\n");

}
void _AdjustUp(Heap* php, int start)
{
	int j = start;
	int i = (j - 1) / 2;

	while (j > 0) //说明没有调整到根节点
	{
		if (php->heap[j] > php->heap[i])
		{
			//交换数据
			HeapElemType tmp = php->heap[j];
			php->heap[j] = php->heap[i];
			php->heap[i] = tmp;

			//向上回溯
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
}
void _AdjustDown(Heap* php, int start)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < php->size)
	{
		if (j + 1 < php->size && php->heap[j + 1] > php->heap[j])
			j++;

		if (php->heap[j] > php->heap[i])
		{
			HeapElemType tmp = php->heap[j];
			php->heap[j] = php->heap[i];
			php->heap[i] = tmp;

			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void HeapDestroy(Heap* php) {
	free(php->heap);
	php->heap = NULL;
	php->heap = php->size = 0;
}
void HeapCreate(Heap* php, HeapElemType ar[], int n) {
	php->capacity = n;
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * php->capacity);
	assert(php->heap != NULL);
	for (int i = 0; i < n; i++) {
		php->heap[i] = ar[i];
		php->size = n;
	}
	int CurPos = (n - 1) / 2;
	while (CurPos >= 0) {
		_AdjustDown(php, CurPos);
		CurPos--;
	}
}
