#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
#define _CRT_SECURE_NO_WARNINGS

/*
typedef struct
{
	int id;
	int arrival_time;
	int service_time;
}element;

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

void Enqueue(Queue* q, element data)
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

element Dequeue(Queue* q)
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

element Peek(Queue* q)
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
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	Queue q;
	Init_Queue(&q);

	srand(time(NULL));

	for (int clock = 0; clock < minutes; clock++)
	{
		printf("현재시각 = %d\n", clock);
		if ((rand() % 10) < 3)
		{
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			Enqueue(&q, customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간 = %d분\n", customer.id, customer.arrival_time, customer.service_time);
		}

		if (service_time > 0)
		{
			printf("고객 %d 업무처리중입니다.\n", service_customer);
			service_time--;
		}
		else
		{
			if (!Is_Empty(&q))
			{
				element customer = Dequeue(&q);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("전체 대기 시간 = %d분 \n", total_wait);

}
*/