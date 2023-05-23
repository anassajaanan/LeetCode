#include <stdlib.h>
#include <stdio.h>

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

typedef struct {
    int 	counter;
    queue	q;
} RecentCounter;

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
	p = q->front;
    q->front = q->front->next;
    data = p->data;
    free(p);
    return (data);
}


RecentCounter* recentCounterCreate() {
    RecentCounter *newRecentCounter;

	newRecentCounter = (RecentCounter *)malloc(sizeof(RecentCounter));
	newRecentCounter->counter = 0;
	createQueue(&newRecentCounter->q);
	return (newRecentCounter);
}

int recentCounterPing(RecentCounter* obj, int t) {
	int start = t - 3000;
	Enqueue(&obj->q, t);
	obj->counter++;
	while (obj->q.front != NULL && (obj->q.front->data < start || obj->q.front->data > t))
	{
		Dequeue(&obj->q);
		obj->counter--;
	}
	return (obj->counter);
}

void recentCounterFree(RecentCounter* obj) {
    obj->counter = 0;
    free(obj);
}



