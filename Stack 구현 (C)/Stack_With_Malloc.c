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
	if (isFull(s) != 1) //push 가능한 경우
	{
		s->data[++(s->top)] = data;
	}
	else //stack이 꽉찬 경우
	{
		//스택의 용량을 2배로 늘려 재 할당해준다.
		s->capacity *= 2;
		s->data = (int*)realloc(s->data, s->capacity * sizeof(int));

		//push 진행
		s->data[++(s->top)] = data;
	}
}

int Pop(Stack *s)
{
	if (isEmpty(s) != 1) //pop 가능한 경우
	{
		return s->data[s->top--];
	}
	else //stack이 비어있는 경우
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