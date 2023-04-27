#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
	int				val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	struct ListNode	*p;
	struct ListNode	*q;

	p = head;
	q = head;
	while (q && q->next)
	{
		p = p->next;
		q = q->next->next;
		if (p == q)
			return (true);
	}
	return (false);
}
