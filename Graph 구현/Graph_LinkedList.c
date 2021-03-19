#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode
{
	int vertex; //정점 구분자
	struct GraphNode* link;
}GraphNode;

typedef struct Graph
{
	int n; //정점의 개수
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
		fprintf(stderr, "그래프 : 정점 개수 초과");
		return;
	}

	g->n++; //간선이 추가되지않았기 때문에 n만 늘려준다.
}

void insert_Edge(Graph* g, int start, int end)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}

	GraphNode* node;
	
	node = (GraphNode*)malloc(sizeof(GraphNode));

	node->vertex = end;
	node->link = g->adj_Mat[start]; //start정점의 리스트의 첫번째에 집어넣기 위해 헤더가 가리키던 값을 넣어준다.
	g->adj_Mat[start] = node; //start정점의 헤더포인터가 해당 end 노드를 가리키도록 한다.
}

void PrintMat(Graph* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->adj_Mat[i];
		printf("정점 %d의 인접 리스트 ", i);

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