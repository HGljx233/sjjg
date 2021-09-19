#include<stdio.h>
#include<math.h>
#define N 1000
#if 0
//1.旋转数组
void rotate(int* arr, int arrsize,int k) {
	if (arrsize <= 1)
		return;
	k = k % arrsize;
	if (k == 0)
		return;
	for (int i = 0; i < k; i++) {
		int tmp = arr[arrsize - 1];
		for (int j = arrsize - 1; j > 0; j--) {
			arr[j] = arr[j - 1];
		}
		arr[0] = tmp;
	}
}
void reverse(int *nums, int start, int end) {
	while (start < end) {
		int tmp = nums[start];
		nums[start] = nums[end];
		nums[end] = tmp;
		start++;
		end--;
	}
}
void rotate_1(int* arr, int arrsize, int k) {
	if (arrsize <= 1)
		return;
	k = k % arrsize;
	if (k == 0)
		return;
	reverse(arr, 0, arrsize - 1);
	reverse(arr, 0, k - 1);
	reverse(arr, k , arrsize - 1);
}
int main() {
	int ar[] = {1,2,3,4,5 };
	int n = sizeof(ar) / sizeof(ar[0]);
	rotate_1(ar, n, 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", ar[i]);
	}
}

//2.数组形式的整形加法
void reverse(int* nums, int start, int end) {
	while (start < end) {
		int tmp = nums[start];
		nums[start] = nums[end];
		nums[end] = tmp;
		start++;
		end--;
	}
}
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {	
	int n = 10000;
	int* ret = malloc(sizeof(int) * n);
	*returnSize = 0;
	for (int i = numSize - 1; i >= 0 || k > 0; --i, k /= 10) {

		if (i >=0) {
			k += num[i];
		}
		ret[(*returnSize)++] = k % 10;
	}
	reverse(ret, 0, numSize);
//	for (int i = 0; i < (*returnSize) / 2; i++) {
//	int tmp = ret[i];
//	ret[i] = ret[(*returnSize - 1 - i)];
//	ret[(*returnSize - 1 - i)] = tmp;
//}
return ret;
}
int weishu(int num) {
	int i = 1;
	while (num > 0) {
		num /= 10;
		i++;
	}
	return i;
}
int main() {

	int arr[] = { 1,2,0,0 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int c[1024];
	int k =50000;
	int* d = addToArrayForm(arr, size, k, c);

	for (int i = 0; i < fmax(weishu(k)-1,size); i++) {

		printf("%d ", d[i]);

	}

}
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//	int n = 10001;
//	int* ret = (int*)malloc(sizeof(int) * n);
//	memset(ret, 0, sizeof(int) * n);
//	int i = numSize - 1;
//	int sum = 0;
//	int sign = 0;
//	int count = 0;
//	while (i >= 0 && k != 0) {
//		sum = num[i] + (k % 10) + sign;
//		if (sum >= 10) {
//			sum -= 10;
//			sign = 1;
//		}
//		else
//			sign = 0;
//		ret[count++] = sum;
//		i--;
//		k /= 10;
//	}
//	while (i >= 0) {
//		sum = num[i] + sign;
//		if (sum >= 10) {
//			sum -= 10;
//			sign = 1;
//		}
//		else
//			sign = 0;
//		ret[count++] = sum;
//		i--;
//	}
//	while (k != 0) {
//		sum = (k % 10) + sign;
//		if (sum >= 10) {
//			sum -= 10;
//			sign = 1;
//		}
//		else
//			sign = 0;
//		ret[count++] = sum;
//	}
//	if (sign > 0) {
//		ret[count++] = sign;
//	}
//}

//3.对链表进行插入排序
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* p = head->next;
	head->next = NULL;
	while (p != NULL) {
		struct ListNode* cur = head;
		struct ListNode* prev = NULL;
		struct ListNode* q = p->next;
		while (cur != NULL && p->val > cur->val) {
			prev = cur;
			cur = cur->next;
		}
		if (prev == NULL) {
			p->next = head;
			head = p;
		}
		else {
			p->next = prev->next;
			prev->next = p;

		}
		p = q;
	}
	return head;
}
#endif
//4.删除重复结点,重复结点不保留,返回链表头指针
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
ListNode* deleteDupLication(ListNode* pHead) {
	if (pHead == NULL || pHead->next == NULL);
	return pHead;
	ListNode* n0 = NULL;
	ListNode* n1 = pHead;
	ListNode* n2 = n1->next;
	while (n2 != NULL) {
		if (n1->val != n2->val) {
			n0 = n1;
			n1 = n2;
			n2 = n2->next;
		}
		else {
			while (n2 != NULL && n2->val == n1->val)
				n2 = n2->next;
				if (n0 == NULL)
					pHead = n2;
				else
					n0->next = n2;
				while (n1 != n2) {
					ListNode* p = n1;
					n1 = n1->next;
					free(p);
				}
				if (n2 != NULL)
					n2 = n2->next;
		}
	}
	return pHead;
}