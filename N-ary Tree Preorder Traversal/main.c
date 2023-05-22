#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

typedef struct node
{
    void *data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

void createStack(stack *s)
{
    s->top = NULL;
}

void Push(stack *s, void *data)
{
    node *new_node;

    new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

void *Pop(stack *s)
{
    node *stack_top;
    void *x;

    stack_top = s->top;
    s->top = s->top->next;
    x = stack_top->data;
    free(stack_top);
    return x;
}

int* preorder(struct Node* root, int* returnSize) {
	stack		s;
	struct Node	*p;
	int			i;
	int			*ans;

	if (root == NULL)
	{
		*returnSize = 0;
		return (NULL);
	}
	createStack(&s);
	Push(&s, root);
	i = 0;
	ans = (int *)malloc(sizeof(int) * 10000);
	while (s.top != NULL)
	{
		p = (struct Node *)Pop(&s);
		ans[i++] = p->val;
		for (int j = p->numChildren - 1; j >= 0; j--)
			Push(&s, p->children[j]);
	}
	*returnSize = i;
	return (ans);
}

