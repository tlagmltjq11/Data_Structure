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
	//원형큐는 순환하므로 -1값이 아니라 0으로 초기화한다. 
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

int Peek(Queue* q)
{
	if (!Is_Empty(q))
	{
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
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
	int data = 0;

	Init_Queue(&q);

	while (!Is_Full(&q))
	{
		printf("정수 입력 :");
		Enqueue(&q, data);
		data++;
		Queue_Print(&q);
	}
	printf("큐는 포화 상태입니다.\n");

	while (!Is_Empty(&q))
	{
		data = Dequeue(&q);
		printf("꺼낸 데이터 : %d\n", data);
		Queue_Print(&q);
	}

	printf("큐는 공백 상태입니다.\n");

}
*/