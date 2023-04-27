#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
	int				val;
	struct ListNode *next;
};

void	Display(struct ListNode *list1)
{
	while (list1)
	{
		printf("%d -> ", list1->val);
		list1 = list1->next;
	}
	printf("NULL\n");
}

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

struct ListNode	*deleteDuplicates(struct ListNode *head)
{
	struct ListNode	*p;
	struct ListNode	*q;

	p = head;
	while (p)
	{
		if (p->next == NULL)
			return (head);
		if (p->val == p->next->val)
		{
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else 
			p = p->next;
	}
	return (head);
}

int main(void)
{
	struct ListNode	*head;

	head = NULL;

	Append(&head, 1);
	Append(&head, 1);
	Append(&head, 2);
	// Append(&head, 2);
	// Append(&head, 2);
	Append(&head, 3);
	Append(&head, 3);
	// Append(&head, 4);
	// Append(&head, 4);

	deleteDuplicates(head);

	Display(head);
}