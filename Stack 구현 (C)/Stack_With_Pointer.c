#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef struct
{
	int data[STACK_SIZE];
	int top;
}Stack;

Init_Stack(Stack *s)
{
	s->top = -1;
}

int isEmpty(Stack *s)
{
	if (s->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(Stack* s)
{
	if (s->top == STACK_SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Push(Stack *s, int data)
{
	if (isFull(s) != 1)
	{
		s->top++;
		s->data[s->top] = data;
	}
}

int Pop(Stack *s)
{
	if (isEmpty(s) != 1)
	{
		return s->data[s->top--];
	}
	else
	{
		exit(1);
	}
}

int Peek(Stack *s)
{
	if (isEmpty(s) != 1)
	{
		return s->data[s->top];
	}
	else
	{
		exit(1);
	}
}

int main()
{
	Stack *s = (Stack *)malloc(sizeof(Stack));
	Init_Stack(s);

	Push(s, 1);
	Push(s, 2);
	Push(s, 3);

	printf("%d \n", Pop(s));
	printf("%d \n", Pop(s));
	printf("%d \n", Pop(s));

	return 0;
}