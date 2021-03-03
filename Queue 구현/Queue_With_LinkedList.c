#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node
{
	element data;
	struct Node* link;
}Node;

typedef struct Queue_
{
	int curSIze;
	Node* front;
	Node* rear;
}Queue_;

void init(Queue_* q)
{
	q->curSIze = 0;
	q->front = NULL;
	q->rear = NULL;
}

int isEmpty(Queue_* q)
{
	if (q->curSIze == 0 || q->front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Enqueue(Queue_* q, element data)
{
	if (q != NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		if (isEmpty(q) == 1)
		{
			q->front = newNode;
			q->rear = newNode;
		}
		else
		{
			q->rear->link = newNode;
			q->rear = newNode;
		}
		q->curSIze++;

		return 1;
	}

	return 0;
}

int Dequeue(Queue_* q)
{
	if (q != NULL)
	{
		if (isEmpty(q) == 1)
		{
			exit(1); //empty error
		}
		else
		{
			Node* delNode = q->front;
			element result = delNode->data;
			q->front = delNode->link;

			if (q->front == NULL) //큐에 항목이 1개만 존재했던 경우 rear도 널처리
			{
				q->rear = NULL;
			}

			free(delNode);

			q->curSIze--;

			return result;
		}
	}

	//error
	exit(1);
}

void Print(Queue_* q)
{
	Node* iter = q->front;
	for (int i = 0; i < q->curSIze; i++)
	{
		printf("%d->", iter->data);
		iter = iter->link;
	}

	printf("\n");
}

int main()
{
	Queue_ q;
	init(&q);

	Enqueue(&q, 1);
	Print(&q);

	Enqueue(&q, 2);
	Print(&q);

	Enqueue(&q, 3);
	Print(&q);

	Enqueue(&q, 4);
	Print(&q);

	Dequeue(&q);
	Print(&q);

	Dequeue(&q);
	Print(&q);

	Dequeue(&q);
	Print(&q);

	Dequeue(&q);
	Print(&q);

	return 0;
}