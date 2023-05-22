#include <stdlib.h>
#include <stdio.h>


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

void	Push(stack *s, int data) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = s->top;
	s->top = new_node;
}

int	Pop(stack *s) {
	struct node *p;
	int data;

	p = s->top;
	data = p->data;
	s->top = s->top->next;
	free(p);
	return (data);
}

int calPoints(char ** operations, int operationsSize){
	stack	s;
	int		sum;

	init_stack(&s);
	for (int i = 0; i < operationsSize; i++)
	{
		char *operation = operations[i];
		if (operation[0] == '+')
			Push(&s, s.top->data + s.top->next->data);
		else if (operation[0] == 'D')
			Push(&s, 2 * s.top->data);
		else if (operation[0] == 'C')
			Pop(&s);
		else
			Push(&s, atoi(operation));
	}
	sum = 0;
	while (s.top != NULL)
		sum += Pop(&s);
	return (sum);
}

int main(void)
{
	char *operations[] = {"5","-2","4","C","D","9","+","+"};
	int operationsSize = 8;
	printf("%d\n", calPoints(operations, operationsSize));
	return (0);	
}