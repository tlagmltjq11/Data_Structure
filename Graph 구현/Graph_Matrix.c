#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Graph
{
	int n; //정점의 개수
	int adj_Mat[MAX_VERTICES][MAX_VERTICES];
}Graph;

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
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}

	g->n++;
}

void Insert_Edge(Graph* g, int start, int end)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}

	g->adj_Mat[start][end] = 1;
	g->adj_Mat[end][start] = 1;
}

void PrintMat(Graph* g)
{
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			printf("%2d ", g->adj_Mat[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	Graph *g;
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
	
	PrintMat(g);

	free(g);
}