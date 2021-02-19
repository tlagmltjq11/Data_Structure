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
}Deque;

void Error(char* m)
{
	fprintf(stderr, "%s\n", m);
	exit(1);
}

void Init_Deque(Deque* q)
{
	//����ť�� ��ȯ�ϹǷ� -1���� �ƴ϶� 0���� �ʱ�ȭ�Ѵ�.
	q->rear = 0;
	q->front = 0;
}

void Deque_Print(Deque* q)
{
	printf("Deque(front=%d rear=%d) = ", q->front, q->rear);
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

int Is_Full(Deque* q)
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

int Is_Empty(Deque* q)
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

void Add_Front(Deque* q, int data)
{
	if (Is_Full(q) != 1)
	{
		q->data[q->front] = data;
		q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	}
	else
	{
		Error("Queue�� ��ȭ �����Դϴ�.");
		return;
	}
}

int Delete_Front(Deque* q)
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

void Add_Rear(Deque* q, int data)
{
	if (Is_Full(q) != 1)
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = data;
	}
	else
	{
		Error("Queue�� ��ȭ �����Դϴ�.");
		return;
	}
}

int Delete_Rear(Deque* q)
{
	int prev = q->rear; //������ ����Ű�� ���� ����

	if (Is_Empty(q) != 1)
	{
		q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //������ ������ ���� �ִ� �ε����� �Ѿ�� 0���� ��ȯ��Ų��.
		return q->data[prev];
	}
	else
	{
		Error("Queue�� ���� �����Դϴ�.");
		return;
	}
}

int main()
{
	Deque dq;

	Init_Deque(&dq);

	for (int i = 0; i < 3; i++)
	{
		Add_Front(&dq, i);
		Deque_Print(&dq);
	}

	for (int i = 0; i < 3; i++)
	{
		Delete_Rear(&dq);
		Deque_Print(&dq);
	}

	return 0;
}*/