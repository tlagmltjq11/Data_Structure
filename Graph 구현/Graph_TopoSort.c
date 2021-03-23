#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphNode
{
	int vertex; //���� ������
	struct GraphNode* link;
}GraphNode;

typedef struct Graph
{
	int n; //������ ����
	GraphNode* adj_List[MAX_VERTICES];
}Graph;

void Init(Graph* g)
{
	g->n = 0;

	for (int i = 0; i < MAX_VERTICES; i++)
	{
		g->adj_List[i] = NULL;
	}
}

void insert_Vertex(Graph* g, int vertex)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "�׷��� : ���� ���� �ʰ�");
		return;
	}

	g->n++; //������ �߰������ʾұ� ������ n�� �÷��ش�.
}

void insert_Edge(Graph* g, int start, int end)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return;
	}

	GraphNode* node;

	node = (GraphNode*)malloc(sizeof(GraphNode));

	node->vertex = end;
	node->link = g->adj_List[start]; //start������ ����Ʈ�� ù��°�� ����ֱ� ���� ����� ����Ű�� ���� �־��ش�.
	g->adj_List[start] = node; //start������ ��������Ͱ� �ش� end ��带 ����Ű���� �Ѵ�.
}


// stack----------------------------------
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
	if (s->top == STACK_SIZE - 1)
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
// stack End------------------------------

int Topo_sort(Graph* g)
{
	int i;
	Stack s;
	GraphNode* node;

	//��� ������ ���� ���� ���
	int* in_degree = (int*)malloc(sizeof(int) * g->n);
	for (i = 0; i < g->n; i++)
	{
		in_degree[i] = 0;
	}
	for (i = 0; i < g->n; i++)
	{
		node = g->adj_List[i];
		while (node != NULL)
		{
			in_degree[node->vertex]++; //�������� ���
			node = node->link;
		}
	}

	Init_Stack(&s);
	//���� ������ 0�� ������ ���ÿ� ����
	for (i = 0; i < g->n; i++)
	{
		if (in_degree[i] == 0)
		{
			Push(&s, i);
		}
	}

	//���� ���� ����
	while (!isEmpty(&s))
	{
		int w;
		w = Pop(&s);
		printf("���� %d ->", w);
		node = g->adj_List[w];
		while (node != NULL)
		{
			int u = node->vertex;
			in_degree[u]--;
			if (in_degree[u] == 0)
			{
				Push(&s, u);
			}

			node = node->link;
		}
	}

	free(in_degree);
	printf("\n");
	return (i == g->n);
}

int main()
{
	Graph g;

	Init(&g);
	insert_Vertex(&g, 0);
	insert_Vertex(&g, 1);
	insert_Vertex(&g, 2);
	insert_Vertex(&g, 3);
	insert_Vertex(&g, 4);
	insert_Vertex(&g, 5);

	insert_Edge(&g, 0, 2);
	insert_Edge(&g, 0, 3);

	insert_Edge(&g, 1, 3);
	insert_Edge(&g, 1, 4);

	insert_Edge(&g, 2, 3);
	insert_Edge(&g, 2, 5);

	insert_Edge(&g, 3, 5);
	insert_Edge(&g, 4, 5);

	Topo_sort(&g);

	return 0;
}