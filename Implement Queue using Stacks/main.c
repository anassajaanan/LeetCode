#include <stdlib.h>
#include <stdio.h>
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

typedef	struct 
{
	stack	s1;
	stack	s2;
}MyQueue;

MyQueue	*myQueueCreate()
{
	MyQueue	*queue;

	queue = (MyQueue *)malloc(sizeof(MyQueue));
	init_stack(&queue->s1);
	init_stack(&queue->s2);
	return (queue);
}

void	myQueuePush(MyQueue *queue, int data)
{
	Push(&queue->s1, data);
}

int	myQueuePop(MyQueue *queue)
{
	if (!is_empty(&queue->s2))
		return (Pop(&queue->s2));
	else
	{
		if (is_empty(&queue->s1))
			return (-1);
		while (!is_empty(&queue->s1))
			Push(&queue->s2, Pop(&queue->s1));
		myQueuePop(queue);
	}
}

int myQueuePeek(MyQueue *queue)
{
	if (!is_empty(&queue->s2))
		return (queue->s2.top->data);
	else
	{
		if (is_empty(&queue->s1))
			return (-1);
		while (!is_empty(&queue->s1))
			Push(&queue->s2, Pop(&queue->s1));
		myQueuePeek(queue);
	}
}

bool	myQueueEmpty(MyQueue *queue)
{
	if (is_empty(&queue->s1) && is_empty(&queue->s2))
		return (true);
	return (false);
}

void myQueueFree(MyQueue *queue)
{
	while (!is_empty(&queue->s1))
		Pop(&queue->s1);
	while (!is_empty(&queue->s2))
		Pop(&queue->s2);
	free(queue);
}


int main(void)
{
	MyQueue	*queue;

	queue = myQueueCreate();
	myQueuePush(queue, 1);
	myQueuePush(queue, 2);
	myQueuePush(queue, 3);
	myQueuePush(queue, 4);
	myQueuePush(queue, 5);
	
	while (!myQueueEmpty(queue))
		printf("%d\n", myQueuePop(queue));

	myQueuePush(queue, 10);
	myQueuePush(queue, 11);
	myQueuePush(queue, 15);

	while (!myQueueEmpty(queue))
		printf("%d\n", myQueuePop(queue));

	myQueueFree(queue);
	
}


