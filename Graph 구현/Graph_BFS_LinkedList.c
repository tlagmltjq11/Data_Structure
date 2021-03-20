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


//-----------------연결리스트 BFS 시작------------------
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphNode
{
	int vertex; //정점 구분자
	struct GraphNode* link;
}GraphNode;

typedef struct Graph
{
	int n; //정점의 개수
	GraphNode* adj_List[MAX_VERTICES];
}Graph;

int visited[MAX_QUEUE_SIZE];

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
	node->link = g->adj_List[start]; //start정점의 리스트의 첫번째에 집어넣기 위해 헤더가 가리키던 값을 넣어준다.
	g->adj_List[start] = node; //start정점의 헤더포인터가 해당 end 노드를 가리키도록 한다.
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

		GraphNode* node = g->adj_List[v];

		while (node != NULL)
		{
			if (!visited[node->vertex])
			{
				printf("%d 방문 -> ", node->vertex);
				visited[node->vertex] = TRUE;
				Enqueue(&q, node->vertex);
			}

			node = node->link;
		}
	}
}
//-----------------연결리스트 BFS 끝-------------------

int main()
{
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));
	Init(g);

	for (int i = 0; i < 6; i++)
	{
		insert_Vertex(g, i);
	}

	insert_Edge(g, 0, 2);
	insert_Edge(g, 2, 0);
	insert_Edge(g, 2, 1);
	insert_Edge(g, 1, 2);
	insert_Edge(g, 2, 3);
	insert_Edge(g, 3, 2);
	insert_Edge(g, 0, 4);
	insert_Edge(g, 4, 0);
	insert_Edge(g, 4, 5);
	insert_Edge(g, 5, 4);
	insert_Edge(g, 1, 5);
	insert_Edge(g, 5, 1);
	printf("BFS\n");
	BFS(g, 0);
	printf("\n");
	free(g);

	return 0;
}
