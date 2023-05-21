#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
	int 			val;
	struct ListNode	*next;
};

struct ListNode	*ReverseLinkedList(struct ListNode *head)
{
	struct ListNode	*p;
	struct ListNode	*q;
	struct ListNode	*r;
	
	if (head == NULL || head->next == NULL)
		return (head);
	p = head;
	q = NULL;
	r = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	return (q);
}

bool isPalindrome(struct ListNode* head)
{
	struct ListNode *p;
	struct ListNode *q;
	struct ListNode *mid;

	p = head;
	mid = head;
	if (head == NULL || head->next == NULL)
		return (true);
	if (p->next->next == NULL)
	{
		if (p->val != p->next->val)
			return (false);
		return (true);
	}
	while (p)
	{
		p = p->next;
		if (p == NULL)
			break;
		p = p->next;
		if (p == NULL)
			break;
		mid = mid->next;
	}
	p = head;
	q = ReverseLinkedList(mid->next);
	while (q)
	{
		if (p->val != q->val)
			return (false);
		p = p->next;
		q = q->next;
	}
	return (true);
}