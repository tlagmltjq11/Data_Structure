#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; //�θ� ���

//�ʱ�ȭ
void Set_Init(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1; //-1���� ���� ���´� �θ��尡 ���� ��.
	}
}

//cur�� ���ϴ� ������ ��ȯ
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

//�ΰ��� ���Ұ� ���� ������ ��ģ��.
void Set_Union(int a, int b)
{
	int root1 = Set_Find(a);
	int root2 = Set_Find(b);

	if (root1 != root2)
	{
		parent[root1] = root2; //�� ������ �θ��带 �ٸ� ������ �θ��带 ����Ű�� �����ν� �������� ����.
	}
}

//����
struct Edge
{
	int start, end, weight;
};

typedef struct Graph
{
	int n; //������ ����
	int v; //������ ����
	struct Edge edges[2 * MAX_VERTICES]; //������ �����ؾ��ϱ� ������, ũ�罺Į�� ���� �׷����� �����迭�� ���´�.
}Graph;


//���� �׷��� �ʱ�ȭ
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

// qsort�� ���� ���Լ�
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;

	return (x->weight - y->weight);
}

void Kruskal(Graph* g)
{
	int edge_accepted = 0; //���� ���õ� ������ ��
	int uset, vset; //���� u�� v�� ���� ��ȣ
	struct Edge e;

	Set_Init(g->v); //���� �ʱ�ȭ
	qsort(g->edges, g->n, sizeof(struct Edge), compare); //���� ����
	
	printf("ũ�罺Į �ּ� ���� Ʈ�� �˰��� \n");
	int i = 0;

	while(edge_accepted < (g->v - 1)) // ���õ� ������ ���� n-1�� �Ǹ� ����
	{
		e = g->edges[i];
		uset = Set_Find(e.start);
		vset = Set_Find(e.end);

		if (uset != vset) //���� ���� ������ �ٸ��ٸ�
		{
			printf("���� (%d, %d) %d ���� \n", e.start, e.end, e.weight);
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