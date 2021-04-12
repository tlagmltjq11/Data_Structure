#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

int distance[MAX_VERTICES];

typedef struct GraphNode
{
	int vertex; //���� ������
	int weight;
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

void insert_Edge(Graph* g, int start, int end, int weight)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return;
	}

	GraphNode* node;

	node = (GraphNode*)malloc(sizeof(GraphNode));

	node->vertex = end;
	node->weight = weight;
	node->link = g->adj_List[start]; //start������ ����Ʈ�� ù��°�� ����ֱ� ���� ����� ����Ű�� ���� �־��ش�.
	g->adj_List[start] = node; //start������ ��������Ͱ� �ش� end ��带 ����Ű���� �Ѵ�.
}

void BellmanFord(Graph* g, int start)
{
	int v = g->n;

	for (int i = 0; i < v; i++)
	{
		distance[i] = INF; //�ʱ�ȭ
	}
	distance[start] = 0;

	for (int i = 0; i < v; i++) //���� ���� ��ŭ
	{
		for (int j = 0; j < v; j++) //���� 2�� ������ ��� ������ ��������Ʈ ������� ��ȸ�ϱ� ����.
		{
			GraphNode * node = g->adj_List[j];
			while (node != NULL)
			{
				if (distance[j] == INF)
				{
					//�������� ���Ѵ��� ���� ������ ����� ���Ѵ��̹Ƿ� �Ѿ.
					continue;
				}

				distance[node->vertex] = distance[node->vertex] > distance[j] + node->weight ? distance[j] + node->weight : distance[node->vertex];

				node = node->link;
			}
		}
	}

	//���� ����Ŭ�� �����ϴ��� Ȯ���ϱ� ���� �ѹ��� ����Ŭ�� �� ��������.
	for (int j = 0; j < v; j++)
	{
		GraphNode* node = g->adj_List[j];
		while (node != NULL)
		{
			if (distance[j] == INF)
			{
				//�������� ���Ѵ��� ���� ������ ����� ���Ѵ��̹Ƿ� �Ѿ.
				continue;
			}

			if (distance[node->vertex] > distance[j] + node->weight)
			{
				//�ִܰŸ��� ����Ǿ��ٴ� ���� ���� ����Ŭ�� �ִٴ� ��!!
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
			printf("-1\n"); //��ΰ� ���� ���
		}
		else
		{
			printf("%d\n", distance[i]);
		}
	}

	return 0;
}