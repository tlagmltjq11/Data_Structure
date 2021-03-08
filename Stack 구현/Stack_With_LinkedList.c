#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node
{
	element data;
	struct Node* link;
}Node;

typedef struct Stack_
{
	int curSize;
	Node* top;
}Stack_;

void init(Stack_* stack)
{
	stack->curSize = 0;
	stack->top = NULL;
}

int isEmpty(Stack_* stack)
{
	if (stack->curSize == 0 || stack->top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Push(Stack_* stack, element data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //null 체크 추가해주면 좋다.
	newNode->data = data;
	newNode->link = stack->top;
	stack->top = newNode;

	stack->curSize++;
}

int Pop(Stack_* stack)
{
	if (isEmpty(stack) == 1)
	{
		fprintf(stderr, "스택이 비어있습니다.\n");
		exit(1);
	}
	else
	{
		Node* delNode = stack->top;
		int result = delNode->data;

		stack->top = delNode->link;

		free(delNode);

		stack->curSize--;

		return result;
	}
}

int Peek(Stack_* stack)
{
	if (isEmpty(stack) == 1)
	{
		fprintf(stderr, "스택이 비어있습니다.\n");
		exit(1);
	}
	else
	{
		Node* peekNode = stack->top;
		return peekNode->data;
	}
}

void Print(Stack_* stack)
{
	Node* iter = stack->top;

	for (int i = 0; i < stack->curSize; i++)
	{
		printf("%d->", iter->data);
		iter = iter->link;
	}

	printf("\n");
}

int main()
{
	Stack_ s;
	init(&s);

	Push(&s, 1);
	Print(&s);

	Push(&s, 2);
	Print(&s);

	Push(&s, 3);
	Print(&s);

	Push(&s, 4);
	Print(&s);

	Pop(&s);
	Print(&s);

	Pop(&s);
	Print(&s);

	Pop(&s);
	Print(&s);

	Peek(&s);
	Print(&s);

	return 0;
}
