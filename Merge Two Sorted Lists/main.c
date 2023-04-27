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


struct ListNode	*mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
	struct ListNode *first;
	struct ListNode *last;

	if (!list1 && !list2)
		return (NULL);
	if (!list1)
		return (list2);
	if (!list2)
		return (list1);
	if (list1->val > list2->val)
	{
		first = list2;
		last = list2;
		list2 = list2->next;
	}
	else
	{
		first = list1;
		last = list1;
		list1 = list1->next;
	}
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			last->next = list1;
			last = list1;
			list1 = list1->next;
		}
		else
		{
			last->next = list2;
			last = list2;
			list2 = list2->next;
		}
	}
	while (list1)
	{
		last->next = list1;
		last = list1;
		list1 = list1->next;
	}
	while (list2)
	{
		last->next = list2;
		last = list2;
		list2 = list2->next;
	}
	return (first);
}


int main(void)
{
	struct ListNode *list1;
	struct ListNode *list2;
	struct ListNode *list3;

	list1 = NULL;
	list2 = NULL;

	Append(&list1, 1);
	Append(&list1, 2);
	Append(&list1, 4);

	Append(&list2, 0);
	Append(&list2, 3);
	Append(&list2, 4);

	list3 = mergeTwoLists(list1, list2);


	Display(list1);
	Display(list2);
	Display(list3);

}