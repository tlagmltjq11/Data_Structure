#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int* data;
	int capacity;
	int top;
}Stack;

void Init_Stack(Stack* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (int*)malloc(s->capacity * sizeof(int));
}

void Delete_Stack(Stack* s)
{
	free(s);
}

int isEmpty(Stack* s)
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
	if (s->top == (s->capacity - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Push(Stack* s, int data)
{
	if (isFull(s) != 1) //push ������ ���
	{
		s->data[++(s->top)] = data;
	}
	else //stack�� ���� ���
	{
		//������ �뷮�� 2��� �÷� �� �Ҵ����ش�.
		s->capacity *= 2;
		s->data = (int*)realloc(s->data, s->capacity * sizeof(int));

		//push ����
		s->data[++(s->top)] = data;
	}
}

int Pop(Stack *s)
{
	if (isEmpty(s) != 1) //pop ������ ���
	{
		return s->data[s->top--];
	}
	else //stack�� ����ִ� ���
	{
		exit(1);
	}
}

int main()
{
	Stack* s = (Stack *)malloc(sizeof(Stack));

	Init_Stack(s);

	Push(s, 1);
	Push(s, 2);
	Push(s, 3);

	printf("%d \n", Pop(s));
	printf("%d \n", Pop(s));
	printf("%d \n", Pop(s));

	Delete_Stack(s);

	return 0;
}