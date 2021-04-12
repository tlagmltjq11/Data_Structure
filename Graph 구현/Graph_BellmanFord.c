#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

int distance[MAX_VERTICES];

typedef struct GraphNode
{
	int vertex; //정점 구분자
	int weight;
	struct GraphNode* link;
}GraphNode;

typedef struct Graph
{
	int n; //정점의 개수
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
		fprintf(stderr, "그래프 : 정점 개수 초과");
		return;
	}

	g->n++; //간선이 추가되지않았기 때문에 n만 늘려준다.
}

void insert_Edge(Graph* g, int start, int end, int weight)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}

	GraphNode* node;

	node = (GraphNode*)malloc(sizeof(GraphNode));

	node->vertex = end;
	node->weight = weight;
	node->link = g->adj_List[start]; //start정점의 리스트의 첫번째에 집어넣기 위해 헤더가 가리키던 값을 넣어준다.
	g->adj_List[start] = node; //start정점의 헤더포인터가 해당 end 노드를 가리키도록 한다.
}

void BellmanFord(Graph* g, int start)
{
	int v = g->n;

	for (int i = 0; i < v; i++)
	{
		distance[i] = INF; //초기화
	}
	distance[start] = 0;

	for (int i = 0; i < v; i++) //정점 갯수 만큼
	{
		for (int j = 0; j < v; j++) //이하 2중 루프는 모든 간선을 인접리스트 방식으로 순회하기 위함.
		{
			GraphNode * node = g->adj_List[j];
			while (node != NULL)
			{
				if (distance[j] == INF)
				{
					//시작점이 무한대인 경우는 어차피 결과가 무한대이므로 넘어감.
					continue;
				}

				distance[node->vertex] = distance[node->vertex] > distance[j] + node->weight ? distance[j] + node->weight : distance[node->vertex];

				node = node->link;
			}
		}
	}

	//음의 사이클이 존재하는지 확인하기 위해 한번의 사이클을 더 돌려본다.
	for (int j = 0; j < v; j++)
	{
		GraphNode* node = g->adj_List[j];
		while (node != NULL)
		{
			if (distance[j] == INF)
			{
				//시작점이 무한대인 경우는 어차피 결과가 무한대이므로 넘어감.
				continue;
			}

			if (distance[node->vertex] > distance[j] + node->weight)
			{
				//최단거리가 변경되었다는 것은 음의 사이클이 있다는 것!!
				printf("-1");
				exit(0);
			}

			node = node->link;
		}
	}
}

int main()
{
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));

	Init(g);

	for (int i = 0; i < 3; i++)
	{
		insert_Vertex(g, i);
	}

	insert_Edge(g, 0, 1, 4);
	insert_Edge(g, 0, 1, 3);

	BellmanFord(g, 0);

	for (int i = 1; i < 3; i++)
	{
		if (distance[i] == INF)
		{
			printf("-1\n"); //경로가 없는 경우
		}
		else
		{
			printf("%d\n", distance[i]);
		}
	}

	return 0;
}