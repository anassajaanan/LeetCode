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


int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
	int	top = 0, count = 0;
	queue	q;

	createQueue(&q);
	for (int i = 0; i < studentsSize; i++)
		Enqueue(&q, students[i]);
	while (q.front != NULL)
	{
		if (count == studentsSize)
			break;
		if (q.front->data == sandwiches[top])
		{
			Dequeue(&q);
			top++;
			studentsSize--;
			count = 0;
		}
		else
		{
			int tmp = Dequeue(&q);
			Enqueue(&q, tmp);
			count++;
		}
	}
	return (studentsSize);
}

int main()
{
	int	students[] = {1,1,1,0,0,1};
	int	sandwiches[] = {1,0,0,0,1,1};
	int	studentsSize = 6;
	int	sandwichesSize = 6;

	printf("%d\n", countStudents(students, studentsSize, sandwiches, sandwichesSize));
	return (0);
}

