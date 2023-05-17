#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
	struct ListNode	*next;
	int 			val;
};

int pairSum(struct ListNode* head){
	int 			i;
	int 			size;
	struct ListNode	*p;

	size = 0;
	p = head;
	while (p)
	{
		size++;
		p = p->next;
	}
	int array[size];
	int HT[size / 2];
	i = 0;
	p = head;
	while (p)
	{
		array[i++] = p->val;
		p = p->next;
	}
	for (i = 0; i < size / 2; i++)
		HT[i] = array[i] + array[size - 1 - i];
	int max = HT[0];
	for (i = 1; i < size / 2; i++)
	{
		if (HT[i] > max)
			max = HT[i];
	}
	return (max);
}
