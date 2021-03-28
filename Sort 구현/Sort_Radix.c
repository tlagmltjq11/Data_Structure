#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

#define MAX_QUEUE_SIZE 100
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
	//원형큐는 순환하므로 -1값이 아니라 0으로 초기화한다. 
	q->rear = 0;
	q->front = 0;
}

int Is_Full(Queue* q)
{
	//front가 rear보다 한칸 앞에 존재한다면 포화상태
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
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
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //나누기 연산을 통해 최대 인덱스를 넘어가면 0으로 순환시킨다.
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
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; //나누기 연산을 통해 최대 인덱스를 넘어가면 0으로 순환시킨다.
		return q->data[q->front];
	}
	else
	{
		Error("Queue가 공백 상태입니다.");
		return;
	}
}

#define BUCKETS 10
#define DIGITS 4
void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	Queue q[BUCKETS];
	
	for (b = 0; b < BUCKETS; b++)
	{
		Init_Queue(&q[b]);
	}

	for (d = 0; d < DIGITS; d++)
	{
		for (i = 0; i < n; i++)
		{
			Enqueue(&q[(list[i] / factor) % 10], list[i]);
		}

		for (b = i = 0; b < BUCKETS; b++)
		{
			while (!Is_Empty(&q[b]))
			{
				list[i++] = Dequeue(&q[b]);
			}
		}

		factor *= 10;
	}
}

int main()
{
	n = MAX_SIZE;
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
	}

	radix_sort(list, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}