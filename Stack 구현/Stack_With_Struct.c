#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef struct
{
	int std_no;
	char name[20];
	char address[100];
}element;

//전역변수로 사용하기 때문에 여러개의 스택을 동시에 사용하기 어려움. -> 포인터를 이용해야함.
element stack[STACK_SIZE];
int top = -1; //-1일 경우 스택이 비어있는 것.

int isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull()
{
	if (top == STACK_SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Push(element student)
{
	if (isFull() != 1)
	{
		top++;
		stack[top] = student;
	}
}

element Pop()
{
	if (isEmpty() != 1)
	{
		return stack[top--];
	}
	else
	{
		exit(1);
	}
}

element Peek()
{
	if (isEmpty() != 1)
	{
		return stack[top];
	}
	else
	{
		exit(1);
	}
}

int main()
{
	element student1 = { 60142297, "sim", "yangju" };
	element student2 = { 12345678, "hee", "yangju" };
	element student3 = { 87766421, "sup", "yangju" };

	Push(student1);
	Push(student2);
	Push(student3);

	element output1 = Pop();
	element output2 = Pop();
	element output3 = Pop();

	printf("%d, %s, %s\n", output1.std_no, output1.name, output1.address);
	printf("%d, %s, %s\n", output2.std_no, output2.name, output2.address);
	printf("%d, %s, %s\n", output3.std_no, output3.name, output3.address);

	return 0;
}
