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

		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') //�Է��� �ǿ������� ���
		{
			value = ch - '0'; //int�� ��ȯ
			Push(&s, value);
		}
		else //�Է��� �������� ���
		{
			op2 = Pop(&s); //�ǿ����� 2���� ������. -> ���� ������ �����ϴ� 2���� ���ڰ� ���� ����ؾ��� ������.
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

	return Pop(&s); //���� ��갪 ����
}

int main()
{
	int result;
	printf("����ǥ����� 82/3-32*+\n");
	result = Eval("82/3-32*+");
	printf("result = %d\n", result);

	return 0;
}
