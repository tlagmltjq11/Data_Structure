#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

typedef struct
{
	char data[STACK_SIZE]; //��ȣ�� ���� �迭
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
				Push(&s, ch); //������ȣ�� Stack�� ���ʴ�� push ���ش�. -> ���� �������� �߰ߵ� ������ȣ ���� ������ �ϹǷ� Stack�� �־��� ������ ���.
				break;

			case ')':
			case ']':
			case '}':
				if (isEmpty(&s) == 1) //���ÿ� ������ȣ�� ���ٸ� ����
				{
					return 0;
				}
				else
				{
					open_ch = Pop(&s); //���ÿ��� �������� pop
					//pop�ؿ� ���� ���� ������ȣ�� ���� ���� �ʴٸ� ����
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
		return 0; //���ÿ� �����ΰ� �����ִٸ� ����
	}

	return 1; //�׽�Ʈ ���
}

int main()
{
	char* p = "{ A[(i+1)] = 0; }";
	if (Check_Bracket(p) == 1)
	{
		printf("%s ��ȣ�˻� ����\n", p);
	}
	else
	{
		printf("%s ��ȣ�˻� ����\n", p);
	}

	return 0;
}
