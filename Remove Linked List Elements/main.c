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

void	Display(struct ListNode *list1)
{
	while (list1)
	{
		printf("%d -> ", list1->val);
		list1 = list1->next;
	}
	printf("NULL\n");
}

struct ListNode *removeElements(struct ListNode *head, int val)
{
	struct ListNode *p;
	struct ListNode *delNode;

	if (head == NULL) 
		return (NULL);
	p = head;
	while (p->val == val)
	{
		head = head->next;
		free(p);
		p = head;
		if (p == NULL)
			return (NULL);
	}
	while (p->next)
	{
		if (p->next->val == val)
		{
			delNode = p->next;
			p->next = delNode->next;
			free(delNode);
		}
		else
			p = p->next;
	}
	return (head);
}




int main(void)
{
	struct ListNode *list1 = NULL;

	Append(&list1, 6);
	Append(&list1, 6);
	Append(&list1, 6);
	Append(&list1, 1);
	Append(&list1, 2);
	Append(&list1, 6);
	Append(&list1, 3);
	Append(&list1, 4);
	Append(&list1, 5);
	Append(&list1, 6);
	Append(&list1, 6);
	Append(&list1, 6);
	Append(&list1, 6);
	Display(list1);
	list1 = removeElements(list1, 6);
	Display(list1);
	return (0);
}