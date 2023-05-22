#include <stdlib.h>
#include <stdio.h>

struct ListNode {
	int				val;
	struct ListNode	*next;
};

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

void	addFirst(struct ListNode **head, int data)
{
	struct ListNode *new;

	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	new->val = data;
	new->next = *head;
	*head = new;
}

int* postorder(struct Node* root, int* returnSize) {
	stack			s;
	struct Node		*p;
	struct ListNode	*head;
	struct ListNode	*q;

	if (root == NULL)
	{
		*returnSize = 0;
		return (NULL);
	}
	createStack(&s);
	Push(&s, root);
	head = NULL;
	int count = 0;
	while (s.top != NULL)
	{
		p = (struct Node *)Pop(&s);
		addFirst(&head, p->val);
		count++;
		for (int i = 0; i < p->numChildren; i++)
			Push(&s, p->children[i]);
	}
	*returnSize = count;
	int *ans = (int *)malloc(sizeof(int) * count);
	q = head;
	count = 0;
	while (q)
	{
		ans[count++] = q->val;
		q = q->next;
	}
	return (ans);
}