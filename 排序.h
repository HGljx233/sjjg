#ifndef _SORT_H_
#define _SORT_H_

#include"Common.h"

void PrintArray(int ar[], int left, int right)
{
	for(int i=left; i<right; ++i)
		printf("%d ", ar[i]);
	printf("\n");
}

//ֱ�Ӳ�������--��ǰ����Ƚ�
void InsertSort_1(int ar[], int left, int right){
	for (int i = left + 1; i < right; ++i) {
		int k = left;
		while (ar[i] > ar[k])
			k++;
		int tmp = ar[i]; 
		for (int j = i; j > k; --j)
			ar[j] = ar[j-1];
			ar[k] = tmp;
	
	}
}

//ֱ�Ӳ�������--�Ӻ���ǰ�Ƚ�
void InsertSort_2(int ar[], int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		int j = i;
		while(j>left && ar[j]<ar[j-1])
		{
			Swap(&ar[j], &ar[j-1]);
			j--;
		}
	}
}

//ֱ�Ӳ�������--�Ӻ���ǰ�Ƚ� --�����ý�������
void InsertSort_3(int ar[], int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		int j = i;
		int tmp = ar[i];
		while(j>left && tmp<ar[j-1])
		{
			ar[j] = ar[j-1];
			j--;
		}
		ar[j] = tmp;
	}
}

//ֱ�Ӳ�������--�Ӻ���ǰ�Ƚ� --�ڱ�λ
void InsertSort_4(int ar[], int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		ar[0] = ar[i]; //�ڱ�λ
		int j = i;
		while(ar[0] < ar[j-1])
		{
			ar[j] = ar[j-1];
			j--;
		}
		ar[j] = ar[0];
	}
}

//�۰����
void BinInsertSort(int *ar, int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		int tmp = ar[i];
		//���ֲ��Ҳ���λ��
		int low = left;
		int high = i-1;
		while(low <= high)
		{
			int mid = (low + high) / 2;
			if(tmp > ar[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}

		//�ƶ�����
		for(int j=i; j>low; --j)
			ar[j] = ar[j-1];
		ar[low] = tmp;
	}
}

void TwoWayInsertSort(int ar[], int left, int right)
{
	int n = right - left; //Ԫ�ظ���
	int* tmp = (int*)malloc(sizeof(int) * n);
	tmp[0] = ar[left];
	int first, last;
	first = last = 0;

	for (int i = left + 1; i < right; ++i)
	{
		if (ar[i] < tmp[first])
		{
			first = (first - 1 + n) % n;
			tmp[first] = ar[i];
		}
		else if (ar[i] > tmp[last])
		{
			last++;
			tmp[last] = ar[i];
		}
		else
		{
			int end = last;
			while (ar[i] < tmp[end])
			{
				tmp[(end + 1) % n] = tmp[end];
				end = (end - 1 + n) % n;
			}
			tmp[(end + 1) % n] = ar[i];
			last++;
		}
	}

	int k = 0;
	for (int i = first; k < n; ++k)
	{
		ar[k] = tmp[i];
		i = (i + 1) % n;
	}

	free(tmp);
}

void ShellSort(int num[], int len)
{
	int i, j, temp, step;
	for (step = len / 2; step >= 1; step /= 2)//�������ÿ�μ���
		for (i = step; i < len; i += step)//��������������
		{
			//�����������
			if (num[i] < num[i - step])
			{
				temp = num[i];
				for (j = i - step; num[j] > temp; j -= step)
					num[j + step] = num[j];
				num[j + step] = temp;
			}
		}
}
int GetMinIndex(int ar[], int left, int right) {
	int min_value = ar[left];
	int index = left;
	for (int i = left + 1; i < right; ++i) {
		if (ar[i] < min_value) {
			min_value = ar[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int ar[], int left, int right) {
	for (int i = left; i < right - 1; ++i) {
		int index = GetMinIndex(ar, i, right);
		if (index != i) {
			int tmp = ar[i];
			ar[i] = ar[index];
			ar[index] = tmp;
		}
	}
}

//������
void _ShiftDown(int ar[], int left, int right, int start) {
	int n = right - left;
	int i = start;
	int j = 2 * i + 1;
	int tmp = ar[i];
	while (j < n) {
		if (j + 1 < n && ar[j] < ar[j + 1])
			j++;
		if (tmp < ar[j]) {
			ar[i] = ar[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	ar[i] = tmp;
}
void HeapSort(int ar[], int left, int right) {
	int n = right - left;
	int curpos = (n - 1) / 2 + left;
	while (curpos >= left) {
		_ShiftDown(ar, left, right, curpos);
		curpos--;
	}
	//����
	int end = right - 1;
	while (end > left) {
		int tmp = ar[end];
		ar[end] = ar[left];
		ar[left] = tmp;
		_ShiftDown(ar, left, end, left);
		end--;
	}
}

////////////////////////////////////////////////////////////////////////////
void TestSort(int ar[], int left, int right)
{
	PrintArray(ar, left, right);
	//InsertSort_1(ar, 0, n);
	//InsertSort_2(ar, left, right);
	//InsertSort_3(ar, left, right);
	//InsertSort_4(ar, left, right);
	BinInsertSort(ar, left, right);
	PrintArray(ar, left, right);
	SelectSort(ar, left, right);
}

void TestSortEfficiency()
{
	srand(time(0));
	int n = 10000;
	int *a1 = (int*)malloc(sizeof(int) * n);
	int *a2 = (int*)malloc(sizeof(int) * n);
	int *a3 = (int*)malloc(sizeof(int) * n);
	int *a4 = (int*)malloc(sizeof(int) * n);
	int *a5 = (int*)malloc(sizeof(int) * n);
	int* a6 = (int*)malloc(sizeof(int) * n);
	for(int i=0; i<n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	unsigned long start = clock();
	InsertSort_1(a1, 0, n);
	unsigned long end   = clock();
	printf("InsertSort_1 : %u\n", end-start);

	start = clock();
	InsertSort_2(a2, 0, n);
	end   = clock();
	printf("InsertSort_2 : %u\n", end-start);

	start = clock();
	InsertSort_3(a3, 0, n);
	end   = clock();
	printf("InsertSort_3 : %u\n", end-start);

	start = clock();
	InsertSort_4(a4, 0, n);
	end   = clock();
	printf("InsertSort_4 : %u\n", end-start);

	start = clock();
	BinInsertSort(a5, 0, n);
	end   = clock();
	printf("BinInsertSort : %u\n", end-start);

	start = clock();
	ShellSort(a6, n);
	end = clock();
	printf("ShellSort : %u\n", end - start);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
}

#endif /* _SORT_H_ */