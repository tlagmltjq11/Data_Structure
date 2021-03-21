#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; //부모 노드

//초기화
void Set_Init(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1; //-1값을 가진 상태는 부모노드가 없는 것.
	}
}

//cur이 속하는 집합을 반환
int Set_Find(int cur)
{
	if (parent[cur] == -1)
	{
		return cur;
	}

	while (parent[cur] != -1)
	{
		cur = parent[cur];
	}

	return cur;
}

//두개의 원소가 속한 집합을 합친다.
void Set_Union(int a, int b)
{
	int root1 = Set_Find(a);
	int root2 = Set_Find(b);

	if (root1 != root2)
	{
		parent[root1] = root2; //한 집합의 부모노드를 다른 집합의 부모노드를 가리키게 함으로써 합집합을 구현.
	}
}

//간선
struct Edge
{
	int start, end, weight;
};

typedef struct Graph
{
	int n; //간선의 개수
	int v; //정점의 개수
	struct Edge edges[2 * MAX_VERTICES]; //간선을 정렬해야하기 때문에, 크루스칼을 위한 그래프는 간선배열을 갖는다.
}Graph;


//간선 그래프 초기화
void Graph_Init(Graph* g, int v)
{
	g->n = 0;
	g->v = v;

	for (int i = 0; i < 2 * MAX_VERTICES; i++)
	{
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void Insert_Edge(Graph* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

// qsort를 위한 비교함수
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;

	return (x->weight - y->weight);
}

void Kruskal(Graph* g)
{
	int edge_accepted = 0; //현재 선택된 간선의 수
	int uset, vset; //정점 u와 v의 집합 번호
	struct Edge e;

	Set_Init(g->v); //집합 초기화
	qsort(g->edges, g->n, sizeof(struct Edge), compare); //간선 정렬
	
	printf("크루스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;

	while(edge_accepted < (g->v - 1)) // 선택된 간선의 수가 n-1이 되면 종료
	{
		e = g->edges[i];
		uset = Set_Find(e.start);
		vset = Set_Find(e.end);

		if (uset != vset) //서로 속한 집합이 다르다면
		{
			printf("간선 (%d, %d) %d 선택 \n", e.start, e.end, e.weight);
			edge_accepted++;
			Set_Union(uset, vset);
		}

		i++;
	}
}

int main()
{
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));
	Graph_Init(g, 7);

	Insert_Edge(g, 0, 1, 29);
	Insert_Edge(g, 1, 2, 16);
	Insert_Edge(g, 2, 3, 12);
	Insert_Edge(g, 3, 4, 22);
	Insert_Edge(g, 4, 5, 27);
	Insert_Edge(g, 5, 0, 10);
	Insert_Edge(g, 6, 1, 15);
	Insert_Edge(g, 6, 3, 18);
	Insert_Edge(g, 6, 4, 25);

	Kruskal(g);
	free(g);
	return 0;
}