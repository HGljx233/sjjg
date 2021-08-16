#include<stdio.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
//逆置链表
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
//给一个链表,且结点的值只有1和0.求他的十进制数
int getDecimalValue(struct ListNode* head) {
	struct ListNode* p = head;
	int num = 0;
	while (p != NULL) {
		num = 2 * num + p->val;
		p = p->next;
	}
	return num;
}
//链表升序合并
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
//移除链表元素,设置一个虚拟结点
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
//给定一个头结点为 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//快指针比慢指针快一倍,刚好是中间

//编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
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