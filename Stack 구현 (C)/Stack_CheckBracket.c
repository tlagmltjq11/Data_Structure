#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

typedef struct
{
	char data[STACK_SIZE]; //괄호를 넣을 배열
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

void Push(Stack *s, char data)
{
	if (isFull(s) != 1)
	{
		s->top++;
		s->data[s->top] = data;
	}
}

char Pop(Stack *s)
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

char Peek(Stack *s)
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

int Check_Bracket(char* in)
{
	Stack s;
	Init_Stack(&s);
	int len = strlen(in);
	char ch, open_ch;

	for (int i = 0; i < len; i++)
	{
		ch = in[i];

		switch (ch)
		{
			case '(':
			case '[':
			case '{' :
				Push(&s, ch); //열림괄호는 Stack에 차례대로 push 해준다. -> 가장 마지막에 발견된 열림괄호 부터 닫혀야 하므로 Stack에 넣었다 꺼내는 방식.
				break;

			case ')':
			case ']':
			case '}':
				if (isEmpty(&s) == 1) //스택에 열림괄호가 없다면 오류
				{
					return 0;
				}
				else
				{
					open_ch = Pop(&s); //스택에서 맨윗값을 pop
					//pop해온 값과 현재 닫힘괄호의 값이 같지 않다면 오류
					if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
					{
						return 0;
					}
				}

			break;
		}
	}

	if (isEmpty(&s) != 1)
	{
		return 0; //스택에 무엇인가 남아있다면 오류
	}

	return 1; //테스트 통과
}

int main()
{
	char* p = "{ A[(i+1)] = 0; }";
	if (Check_Bracket(p) == 1)
	{
		printf("%s 괄호검사 성공\n", p);
	}
	else
	{
		printf("%s 괄호검사 실패\n", p);
	}

	return 0;
}
