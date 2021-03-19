#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode
{
	int vertex; //���� ������
	struct GraphNode* link;
}GraphNode;

typedef struct Graph
{
	int n; //������ ����
	GraphNode* adj_Mat[MAX_VERTICES];
}Graph;

void Init(Graph* g)
{
	g->n = 0;

	for (int i = 0; i < MAX_VERTICES; i++)
	{
		g->adj_Mat[i] = NULL;
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
	node->link = g->adj_Mat[start]; //start������ ����Ʈ�� ù��°�� ����ֱ� ���� ����� ����Ű�� ���� �־��ش�.
	g->adj_Mat[start] = node; //start������ ��������Ͱ� �ش� end ��带 ����Ű���� �Ѵ�.
}

void PrintMat(Graph* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->adj_Mat[i];
		printf("���� %d�� ���� ����Ʈ ", i);

		while (p != NULL)
		{
			printf("-> %d ", p->vertex);
			p = p->link;
		}

		printf("\n");
	}
}

int main()
{
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));

	Init(g);

	for (int i = 0; i < 4; i++)
	{
		insert_Vertex(g, i);
	}

	insert_Edge(g, 0, 1);
	insert_Edge(g, 1, 0);
	insert_Edge(g, 0, 2);
	insert_Edge(g, 2, 0);
	insert_Edge(g, 0, 3);
	insert_Edge(g, 3, 0);
	insert_Edge(g, 1, 2);
	insert_Edge(g, 2, 1);
	insert_Edge(g, 2, 3);
	insert_Edge(g, 3, 2);
	PrintMat(g);

	free(g);

	return 0;
}