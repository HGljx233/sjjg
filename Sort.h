#ifndef _SORT_H_
#define _SORT_H_

#include"Common.h"

void PrintArray(int ar[], int left, int right)
{
	for(int i=left; i<right; ++i)
		printf("%d ", ar[i]);
	printf("\n");
}

//直接插入排序--从前往后比较
void InsertSort_1(int ar[], int left, int right){
	for (int i = left + 1; i < right; ++i) {
		int k = left;
		while (ar[i] > ar[k])
			k++;
		int tmp = ar[i]; 
		for (int j = i; j > k; --j)
			ar[j] = ar[j - 1]; 
			ar[k] = tmp;
	
	}
}

//直接插入排序--从后往前比较
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

//直接插入排序--从后往前比较 --不调用交换函数
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

//直接插入排序--从后往前比较 --哨兵位
void InsertSort_4(int ar[], int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		ar[0] = ar[i]; //哨兵位
		int j = i;
		while(ar[0] < ar[j-1])
		{
			ar[j] = ar[j-1];
			j--;
		}
		ar[j] = ar[0];
	}
}

//折半插入
void BinInsertSort(int *ar, int left, int right)
{
	for(int i=left+1; i<right; ++i)
	{
		int tmp = ar[i];
		//二分查找插入位置
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

		//移动数据
		for(int j=i; j>low; --j)
			ar[j] = ar[j-1];
		ar[low] = tmp;
	}
}

void TwoWayInsertSort(int ar[], int left, int right)
{

}

void ShellSort(int ar[], int left, int right)
{

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
	for(int i=0; i<n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
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

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
}

#endif /* _SORT_H_ */