#pragma once
#include"Common.h"
//交换排序
//冒泡排序
void BubbleSort_1(int ar[], int left, int right)
{
	int n = right - left;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				Swap(&ar[j], &ar[j + 1]);
			}
		}
	}
}

void BubbleSort_2(int ar[], int left, int right)
{
	int n = right - left;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				int tmp = ar[j];
				while (j<right - 1 && tmp>ar[j + 1])
				{
					ar[j] = ar[j + 1];
					j++;
				}
				ar[j] = tmp;
			}
		}
	}
}

void BubbleSort_3(int ar[], int left, int right)
{
	int n = right - left;
	bool is_change = false;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				int tmp = ar[j];
				while (j<right - 1 && tmp>ar[j + 1])
				{
					ar[j] = ar[j + 1];
					j++;
				}
				ar[j] = tmp;
				is_change = true;
			}
		}

		if (!is_change)
			break;
		else
			is_change = false;
	}
}

//快速排序
int GetMidIndex(int ar[], int left, int right)
{
	int low = left, high = right - 1;
	int mid = (low + high) / 2;
	if (ar[low] < ar[mid] && ar[mid] < ar[high])
		return mid;
	if (ar[mid] < ar[low] && ar[low] < ar[high])
		return low;
	return high;
}

//hoare版本
int _Partition_1(int ar[], int left, int right)
{
	int low = left, high = right - 1;
	int key = ar[low];
	while (low < high)
	{
		while (low<high && ar[high]>key)
			high--;
		Swap(&ar[low], &ar[high]);

		while (low < high && ar[low] <= key)
			low++;
		Swap(&ar[low], &ar[high]);
	}
	return low;
}

// 挖坑法
int _Partition_2(int ar[], int left, int right)
{
	int low = left, high = right - 1;
	int key = ar[low];
	while (low < high)
	{
		while (low<high && ar[high]>key)
			high--;
		ar[low] = ar[high];

		while (low < high && ar[low] <= key)
			low++;
		ar[high] = ar[low];
	}
	ar[low] = key;
	return low;
}

//前后指针法
int _Partition_3(int ar[], int left, int right)
{
	//三者取中
	int index = GetMidIndex(ar, left, right);
	if (index != left)
		Swap(&ar[left], &ar[index]);
	/////////////////////////////////////////////////

	int key = ar[left];
	int pos = left;
	for (int i = left + 1; i < right; ++i)
	{
		if (ar[i] < key)
		{
			pos++;
			if (pos != i)
			{
				Swap(&ar[pos], &ar[i]);
			}
		}
	}
	Swap(&ar[left], &ar[pos]);
	return pos;
}

#define M 5
void QuickSort(int ar[], int left, int right)
{
	if (left >= right)
		return;

	if (right - left <= M)
	{
		InsertSort_3(ar, left, right);
	}
	else
	{
		int pos = _Partition_3(ar, left, right); //key
		QuickSort(ar, left, pos);
		QuickSort(ar, pos + 1, right);
	}
}

#include"Stack.h"
void QuickSort_Nor(int ar[], int left, int right)
{
	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, left);
	LinkStackPush(&st, right);

	while (!LinkStackEmpty(&st))
	{
		right = LinkStackTop(&st);
		LinkStackPop(&st);
		left = LinkStackTop(&st);
		LinkStackPop(&st);

		if (right - left <= 1)
			continue;

		int pos = _Partition_3(ar, left, right);
		LinkStackPush(&st, pos + 1); //
		LinkStackPush(&st, right);

		LinkStackPush(&st, left);
		LinkStackPush(&st, pos);
	}
}

//归并排序
void _MergeSort(int ar[], int left, int right, int* tmp)
{
	//分解
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid + 1, right, tmp);

	//归并
	int begin1, end1, begin2, end2;
	begin1 = left, end1 = mid;  //左数据
	begin2 = mid + 1, end2 = right; //右数据

	int k = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (ar[begin1] < ar[begin2])
			tmp[k++] = ar[begin1++];
		else
			tmp[k++] = ar[begin2++];
	}

	while (begin1 <= end1)
		tmp[k++] = ar[begin1++];
	while (begin2 <= end2)
		tmp[k++] = ar[begin2++];

	memcpy(ar + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int ar[], int left, int right)
{
	int n = right - left;
	int* tmp = (int*)malloc(sizeof(int) * n);

	_MergeSort(ar, left, right - 1, tmp);

	free(tmp);
}