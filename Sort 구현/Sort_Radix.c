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
	//����ť�� ��ȯ�ϹǷ� -1���� �ƴ϶� 0���� �ʱ�ȭ�Ѵ�. 
	q->rear = 0;
	q->front = 0;
}

int Is_Full(Queue* q)
{
	//front�� rear���� ��ĭ �տ� �����Ѵٸ� ��ȭ����
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
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //������ ������ ���� �ִ� �ε����� �Ѿ�� 0���� ��ȯ��Ų��.
		q->data[q->rear] = data;
	}
	else
	{
		Error("Queue�� ��ȭ �����Դϴ�.");
		return;
	}
}

int Dequeue(Queue* q)
{
	if (Is_Empty(q) != 1)
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; //������ ������ ���� �ִ� �ε����� �Ѿ�� 0���� ��ȯ��Ų��.
		return q->data[q->front];
	}
	else
	{
		Error("Queue�� ���� �����Դϴ�.");
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