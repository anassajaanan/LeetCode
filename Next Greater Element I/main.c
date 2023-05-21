#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};

typedef struct stack {
	struct node *top;
} stack;

void init_stack(stack *s) {
	s->top = NULL;
}

bool is_empty(stack *s) {
	return (s->top == NULL);
}

void	Push(stack *s, int data) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = s->top;
	s->top = new_node;
}

int	Pop(stack *s) {
	struct node *p;
	int data;

	if (is_empty(s)) {
		return (-1);
	}
	p = s->top;
	data = p->data;
	s->top = s->top->next;
	free(p);
	return (data);
}

void	freeStack(stack *s)
{
	struct node	*p;

	while (s->top)
	{
		p = s->top;
		s->top = s->top->next;
		free(p);
	}
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	stack	s;
	int		*ans;
	int		HT[10001];

	*returnSize = nums1Size;
	ans = (int *)malloc(sizeof(int) * nums1Size);
	init_stack(&s);
	for (int i = 0; i < nums2Size; i++)
	{
		while (s.top != NULL && nums2[i] > s.top->data)
			HT[Pop(&s)] = nums2[i];
		Push(&s, nums2[i]);
	}
	while (s.top != NULL)
		HT[Pop(&s)] = -1;
	for (int i = 0; i < nums1Size; i++)
		ans[i] = HT[nums1[i]] > 0 ? HT[nums1[i]] : -1;
	freeStack(&s);
	return (ans);
}

int main(void)
{
	int nums1[] = {4,1,2};
	int nums2[] = {4, 2, 3, 1};
	int nums1Size = 3;
	int nums2Size = 4;
	int returnSize;
	int *ans;
	int i;

	ans = nextGreaterElement(nums1, nums1Size, nums2, nums2Size, &returnSize);
	for (i = 0; i < returnSize; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return (0);
}