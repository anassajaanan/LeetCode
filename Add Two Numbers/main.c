#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};


void	append(struct ListNode **head, int val)
{
	struct ListNode *new;

	new = malloc(sizeof(struct ListNode));
	new->val = val;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		struct ListNode *tmp;

		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	int carry, total;
	struct ListNode *p;
	struct ListNode *q;
	struct ListNode *head;

	p = l1;
	q = l2;
	carry = 0;
	head = NULL;

	while (p && q)
	{
		total = p->val + q->val + carry;
		if (total < 10)
		{
			carry = 0;
			append(&head, total);
		}
		else
		{
			carry = total / 10;
			append(&head, total % 10);
		}
		p = p->next;
		q = q->next;
	}
	while (p)
	{
		total = p->val + carry;
		if (total < 10)
		{
			carry = 0;
			append(&head, total);
		}
		else
		{
			carry = total / 10;
			append(&head, total % 10);
		}
		p = p->next;
	}
	while (q)
	{
		total = q->val + carry;
		if (total < 10)
		{
			carry = 0;
			append(&head, total);
		}
		else
		{
			carry = total / 10;
			append(&head, total % 10);
		}
		q = q->next;
	}
	if (carry > 0)
		append(&head, carry);

	return (head);
}




int main(void)
{
	struct ListNode *head1 = NULL;
	struct ListNode *head2 = NULL;

	// l1 = [2,4,9] l2 = [5,6,4,9]
	append(&head1, 2);
	append(&head1, 4);
	append(&head1, 9);

	append(&head2, 5);
	append(&head2, 6);
	append(&head2, 4);
	append(&head2, 9);



	

	

	struct ListNode *head = addTwoNumbers(head1, head2);
	struct ListNode *tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->val);
		tmp = tmp->next;
	}






	
	return (0);
}