#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
	int				val;
	struct ListNode *next;
};

void	Append(struct ListNode **first, int n)
{
	struct ListNode *new;
	struct ListNode *current;

	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	new->val = n;
	new->next = NULL;
	if (*first == NULL)
		(*first) = new;
	else
	{
		current = (*first);
		while (current->next)
			current = current->next;
		current->next = new;
	}	
}

struct ListNode *getLastNode(struct ListNode *head)
{
	struct ListNode *p;

	p = head;
	while (p->next)
		p = p->next;
	return (p);
}

int Length(struct ListNode *list1)
{
	struct ListNode	*p;
	int				i;

	p = list1;
	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode	*p;
	struct ListNode	*q;
	struct ListNode	*intersect;
	int				lenA;
	int				lenB;

	if (!headA || !headB)
		return (NULL);
	lenA = Length(headA);
	lenB = Length(headB);
	p = headA;
	q = headB;
	intersect = NULL;
	while (lenA > lenB)
	{
		lenA--;
		p = p->next;
	}
	while (lenB > lenA)
	{
		lenB--;
		q = q->next;
	}
	while (p && q)
	{
		if (p == q)
		{
			intersect = p;
			break;
		}
		p = p->next;
		q = q->next;
	}
	return (intersect);
}

/*
int main(void)
{
	struct ListNode *list1;
	struct ListNode *list2;
	struct ListNode *intersect;

	list1 = NULL;
	list2 = NULL;
	Append(&list1, 4);
	Append(&list1, 1);
	Append(&list1, 8);
	struct ListNode *lastNode1 = getLastNode(list1);
	Append(&list2, 5);
	Append(&list2, 6);
	Append(&list2, 1);
	struct ListNode *lastNode2 = getLastNode(list2);
	lastNode2->next = lastNode1;
	Append(&list1, 4);
	Append(&list1, 5);

	intersect = getIntersectionNode(list1, list2);
	
	if (intersect == NULL)
		printf("No intersection\n");
	else
		printf("Intersection at %d\n", intersect->val);
}
*/