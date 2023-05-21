#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct qnode
{
	int				data;
	struct qnode	*next;
};

typedef struct queue
{
	struct qnode	*front;
	struct qnode	*rear;
} queue;

void	createQueue(queue *q)
{
	q->front = NULL;
	q->rear = NULL;
}

void	Enqueue(queue *q, int data)
{
	struct qnode	*new;

	new = (struct qnode *)malloc(sizeof(struct qnode));
	new->data = data;
	new->next = NULL;
	if (q->front == NULL)
	{
		q->front = new;
		q->rear = new;
	}
	else
	{
		q->rear->next = new;
		q->rear = new;
	}
}

int	Dequeue(queue *q)
{
	struct qnode	*p;
	int				data;

	if (q->front == NULL)
		return (-1);
	else
	{
		p = q->front;
		q->front = q->front->next;
		data = p->data;
		free(p);
		return (data);
	}
}

int QueueFront(queue q)
{
	if (q.front != NULL)
		return (q.front->data);
}

int queueIsEmpty(queue q)
{
	if (q.front == NULL)
		return (1);
	return (0);
}

//    Implement Stack using 2 queues

typedef struct 
{
	queue	q1;
	queue	q2;
} MyStack;


MyStack	*myStackCreate(){
	MyStack	*stack;

	stack = (MyStack *)malloc(sizeof(MyStack));
	createQueue(&stack->q1);
	createQueue(&stack->q2);
	return (stack);
}

void	myStackPush(MyStack *stack, int data)
{
	Enqueue(&stack->q1, data);
}


int	myStackPop(MyStack *stack)
{
	queue	temp;
	int 	data;

	if (stack->q1.front == NULL)
		return (-1);
	while ((stack->q1).front != (stack->q1).rear)
	{
		Enqueue(&stack->q2, Dequeue(&stack->q1));
	}
	data = Dequeue(&stack->q1);
	temp = stack->q1;
	stack->q1 = stack->q2;
	stack->q2 = temp;
	return (data);
}

int	myStackTop(MyStack *stack)
{
	queue 	temp;
	int 	data;
	if (stack->q1.front == NULL)
		return (-1);
	while (stack->q1.front != stack->q1.rear)
		Enqueue(&stack->q2, Dequeue(&stack->q1));
	data = QueueFront(stack->q1);
	Enqueue(&stack->q2, Dequeue(&stack->q1));
	temp = stack->q1;
	stack->q1 = stack->q2;
	stack->q2 = temp;
	return (data);
}

bool myStackEmpty(MyStack *stack)
{
	return (queueIsEmpty(stack->q1));
}


void	myStackFree(MyStack *stack)
{
	free(stack);
}

int main(void)
{
	MyStack	*stack;

	stack = myStackCreate();
	myStackPush(stack, 1);
	myStackPush(stack, 2);
	myStackPush(stack, 3);
	myStackPush(stack, 4);
	myStackPush(stack, 5);
	

	printf("%d\n", myStackTop(stack));

	while (!myStackEmpty(stack))
		printf("%d\n", myStackPop(stack));
	myStackFree(stack);
}


