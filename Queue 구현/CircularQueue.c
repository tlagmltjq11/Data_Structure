#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
#define _CRT_SECURE_NO_WARNINGS

/*
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

void Queue_Print(Queue* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!Is_Empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d	|	", q->data[i]);

			if (i == q->rear)
			{
				break;
			}
		} while (i != q->front);
	}
	printf("\n");
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

int Peek(Queue* q)
{
	if (!Is_Empty(q))
	{
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	}
	else
	{
		Error("Queue�� ���� �����Դϴ�.");
		return;
	}
}

void main()
{
	Queue q;
	int data = 0;

	Init_Queue(&q);

	while (!Is_Full(&q))
	{
		printf("���� �Է� :");
		Enqueue(&q, data);
		data++;
		Queue_Print(&q);
	}
	printf("ť�� ��ȭ �����Դϴ�.\n");

	while (!Is_Empty(&q))
	{
		data = Dequeue(&q);
		printf("���� ������ : %d\n", data);
		Queue_Print(&q);
	}

	printf("ť�� ���� �����Դϴ�.\n");

}
*/