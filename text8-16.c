#include<stdio.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
//��������
struct ListNode* reverseList( ListNode* head) {
	 ListNode* cur = head;
	 ListNode* prev = NULL;
	while (cur) {
		struct ListNode* tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	return prev;
}
//��һ������,�ҽ���ֵֻ��1��0.������ʮ������
int getDecimalValue(struct ListNode* head) {
	struct ListNode* p = head;
	int num = 0;
	while (p != NULL) {
		num = 2 * num + p->val;
		p = p->next;
	}
	return num;
}
//��������ϲ�
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	}
	else if (l2 == NULL)
		return l1;
	else if (l1->val <= l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}
//�Ƴ�����Ԫ��,����һ��������
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* virtualHead = malloc(sizeof(struct ListNode));
	virtualHead->next = head;
	struct ListNode* prev = virtualHead;
	while (prev->next != NULL) {
		if (prev->next->val == val) {
			prev->next = prev->next->next;
		}
		else {
			prev = prev->next;
		}
	}
	return virtualHead->next;
}
//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м��㡣
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//��ָ�����ָ���һ��,�պ����м�

//��д���룬�Ƴ�δ���������е��ظ��ڵ㡣�����ʼ���ֵĽڵ㡣
struct ListNode* removeDuplicateNodes(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	struct ListNode* p = head;
	struct ListNode* prev = NULL;
	struct ListNode* tmp = NULL;
	while (p != NULL) {
		prev = p;
		tmp = p->next;
		while (tmp != NULL) {
			if (p->val != tmp->val) {
				tmp = tmp->next;
				prev = prev->next;
			}
			else {
				prev->next = tmp->next;
				tmp = prev->next;
			}
		}
		p = p->next;
	}
	return head;
}