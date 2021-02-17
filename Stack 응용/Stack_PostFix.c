#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

typedef struct
{
	int data[STACK_SIZE];
	int top;
}Stack;

Init_Stack(Stack* s)
{
	s->top = -1;
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
	if (s->top == STACK_SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Push(Stack* s, char data)
{
	if (isFull(s) != 1)
	{
		s->top++;
		s->data[s->top] = data;
	}
}

int Pop(Stack* s)
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

int Peek(Stack* s)
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

int Eval(char exp[])
{
	Stack s;
	Init_Stack(&s);
	int len = strlen(exp);
	char ch;
	int op1, op2, value;

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') //입력이 피연산자인 경우
		{
			value = ch - '0'; //int로 변환
			Push(&s, value);
		}
		else //입력이 연산자인 경우
		{
			op2 = Pop(&s); //피연산자 2개를 꺼낸다. -> 가장 맨위에 존재하는 2개의 숫자가 다음 계산해야할 숫자임.
			op1 = Pop(&s);

			switch (ch)
			{
				case '+' :
					Push(&s, op1 + op2);
					break;
				case '-' :
					Push(&s, op1 - op2);
					break;
				case '*' :
					Push(&s, op1 * op2);
					break;
				case '/' :
					Push(&s, op1 / op2);
					break;
				default:
					break;
			}
		}
	}

	return Pop(&s); //최종 계산값 리턴
}

int main()
{
	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = Eval("82/3-32*+");
	printf("result = %d\n", result);

	return 0;
}
