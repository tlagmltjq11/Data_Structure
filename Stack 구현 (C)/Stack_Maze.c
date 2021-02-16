#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

typedef struct
{
	short r;
	short c;
}element;

typedef struct
{
	element data[STACK_SIZE];
	int top;
}Stack;

element here = { 1, 0 }, entry = { 1, 0 };

char maze[6][6] = {
	{'1', '1', '1', '1', '1', '1' },
	{'e', '0', '1', '0', '0', '1' },
	{'1', '0', '0', '0', '1', '1' },
	{'1', '0', '1', '0', '1', '1' },
	{'1', '0', '1', '0', '0', 'x' },
	{'1', '1', '1', '1', '1', '1' }
};

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

void Push(Stack* s, element data)
{
	if (isFull(s) != 1)
	{
		s->top++;
		s->data[s->top] = data;
	}
}

void Push_loc(Stack* s, int r, int c)
{
	//막혀있지않고, 이미 방문한 좌표가 아닐 경우
	if (maze[r][c] != '1' && maze[r][c] != '.')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		Push(s, tmp);
	}
}

element Pop(Stack* s)
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

element Peek(Stack* s)
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

void Print_Maze()
{
	printf("\n");
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main()
{
	int r, c;
	Stack s;

	Init_Stack(&s);

	//현재위치를 입구로 초기화
	here = entry;

	//출구에 도착할때까지 반복
	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;

		maze[r][c] = '.'; //이미 방문한 좌표로 지정
		Print_Maze();

		Push_loc(&s, r - 1, c);
		Push_loc(&s, r + 1, c);
		Push_loc(&s, r, c - 1);
		Push_loc(&s, r, c + 1);

		//상하좌우 좌표에 대해서 모두 push_loc를 시도했지만 스택이 비어있는 경우 실패
		if (isEmpty(&s) == 1)
		{
			printf("실패\n");
			return;
		}
		else
		{
			here = Pop(&s); //스택에 가장 맨 위에 존재하는 좌표로 이동
		}
	}

	printf("성공\n");
	return 0;
}
