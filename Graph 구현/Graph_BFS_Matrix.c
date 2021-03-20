#include <stdio.h>
#include <stdlib.h>

//-------------------Queue 시작---------------------
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct
{
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}Queue;

void Error(char* m)
{
	fprintf(stderr, "%s\n", m);
	exit(1);
}

void Init_Queue(Queue* q)
{
	q->rear = -1;
	q->front = -1;
}

int Is_Full(Queue* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Is_Empty(Queue* q)
{
	if (q->front == q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Enqueue(Queue* q, int data)
{
	if (Is_Full(q) != 1)
	{
		q->rear++;
		q->data[q->rear] = data;
	}
	else
	{
		Error("Queue가 포화 상태입니다.");
		return;
	}
}

int Dequeue(Queue* q)
{
	if (Is_Empty(q) != 1)
	{
		q->front++;
		return q->data[q->front];
	}
	else
	{
		Error("Queue가 공백 상태입니다.");
		return;
	}
}
//-------------------Queue 끝---------------------


//-----------------배열 BFS 시작------------------
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct Graph
{
	int n; //정점의 개수
	int adj_Mat[MAX_VERTICES][MAX_VERTICES];
}Graph;

int visited[MAX_VERTICES]; //방문했는지 체크

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

void BFS(Graph* g, int v)
{
	Queue q;
	Init_Queue(&q);

	visited[v] = TRUE;
	printf("%d 방문 -> ", v);

	Enqueue(&q, v);

	while (!Is_Empty(&q))
	{
		v = Dequeue(&q);

		for (int w = 0; w < g->n; w++)
		{
			if (g->adj_Mat[v][w] && !visited[w])
			{
				visited[w] = TRUE;
				printf("%d 방문 -> ", w);
				Enqueue(&q, w);
			}
		}
	}
}
//-----------------배열 BFS 끝-------------------

int main()
{
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));
	Init(g);

	for (int i = 0; i < 6; i++)
	{
		Insert_Vertex(g, i);
	}

	Insert_Edge(g, 0, 2);
	Insert_Edge(g, 2, 1);
	Insert_Edge(g, 2, 3);
	Insert_Edge(g, 0, 4);
	Insert_Edge(g, 4, 5);
	Insert_Edge(g, 1, 5);
	printf("BFS\n");
	BFS(g, 0);
	printf("\n");
	free(g);

	return 0;
}