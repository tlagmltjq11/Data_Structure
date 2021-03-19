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

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct Graph
{
	int n; //������ ����
	int adj_Mat[MAX_VERTICES][MAX_VERTICES];
}Graph;

int visited[MAX_VERTICES]; //�湮�ߴ��� üũ

void Init(Graph* g)
{
	int r, c;
	g->n = 0;

	for (r = 0; r < MAX_VERTICES; r++)
	{
		for (c = 0; c < MAX_VERTICES; c++)
		{
			g->adj_Mat[r][c] = 0;
		}
	}
}

void Insert_Vertex(Graph* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
		return;
	}

	g->n++;
}

void Insert_Edge(Graph* g, int start, int end)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return;
	}

	g->adj_Mat[start][end] = 1;
	g->adj_Mat[end][start] = 1;
}

void DFS(Graph* g, int v)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	Init_Stack(stack);

	Push(stack, v);

	while (!isEmpty(stack))
	{
		v = Pop(stack);

		if (!visited[v])
		{
			printf("���� %d -> ", v);
			visited[v] = TRUE;

			for (int w = 0; w < g->n; w++)
			{
				if (g->adj_Mat[v][w] && !visited[w]) //������ ��尡 �����ϸ� �ش� ��忡 �湮������ ���ٸ� �湮!
				{
					//���⼭ stack�� �̹� ����ִ� ��尪�� �ߺ��ؼ� ���� �ʵ��� ������ �޾��ָ�
					//�� �� ȿ������ �ڵ尡 �� ����.
					Push(stack, w);
				}
			}
		}
	}
}

int main()
{
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));

	Init(g);

	for (int i = 0; i < 4; i++)
	{
		Insert_Vertex(g, i);
	}

	Insert_Edge(g, 0, 1);
	Insert_Edge(g, 0, 2);
	Insert_Edge(g, 0, 3);
	Insert_Edge(g, 1, 2);
	Insert_Edge(g, 2, 3);
	printf("DFS\n");
	DFS(g, 0);
	printf("\n");
	free(g);

	return 0;
}