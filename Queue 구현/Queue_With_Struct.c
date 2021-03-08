#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct
{
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}Queue;

void Error(char* m)
{
	fprintf(stderr, "%s\n", m);
	exit(1);
}

void Init_Queue(Queue* q)
{
	q->rear = -1;
	q->front = -1;
}

void Queue_Print(Queue* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i <= q->front || i > q->rear)
		{
			printf("	|	");
		}
		else
		{
			printf("%d	|	", q->data[i]);
		}
	}
	printf("\n");
}

int Is_Full(Queue* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Is_Empty(Queue* q)
{
	if (q->front == q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Enqueue(Queue* q, int data)
{
	if (Is_Full(q) != 1)
	{
		q->rear++;
		q->data[q->rear] = data;
	}
	else
	{
		Error("Queue가 포화 상태입니다.");
		return;
	}
}

int Dequeue(Queue* q)
{
	if (Is_Empty(q) != 1)
	{
		q->front++;
		return q->data[q->front];
	}
	else
	{
		Error("Queue가 공백 상태입니다.");
		return;
	}
}

void main()
{
	Queue q;
	
	Init_Queue(&q);

	Enqueue(&q, 10);
	Queue_Print(&q);

	Enqueue(&q, 20);
	Queue_Print(&q);

	Enqueue(&q, 30);
	Queue_Print(&q);

	Dequeue(&q);
	Queue_Print(&q);

	Dequeue(&q);
	Queue_Print(&q);

	Dequeue(&q);
	Queue_Print(&q);

	return 0;
}
