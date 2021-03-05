#include <stdio.h>
#include <stdlib.h>

//Tree를 순회하는 여러가지 방식을 구현해 봄.

typedef struct TreeNode
{
	int data;
	struct TreeNode* left, * right;
}TreeNode;


//스택을 이용한 반복문 순회
#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void Push(TreeNode* p)
{
	if (top < SIZE - 1)
	{
		stack[++top] = p;
	}
}

TreeNode* Pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
	{
		p = stack[top--];
	}

	return p;
}

void InOrder_Loop(TreeNode* root)
{
	while (1)
	{
		for (; root; root = root->left) //left로 내려가면서 계속 push
		{
			Push(root);
		}

		root = Pop(); //pop

		if (!root) //스택에 노드가 없을 시 종료
		{
			break;
		}

		printf("[%d] ", root->data); //pop된 노드의 데이터 출력
		root = root->right;
	}
}

#define MAX_QUEUE_SIZE 100
typedef TreeNode * element;
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
	q->rear = 0;
	q->front = 0;
}

void Queue_Print(Queue* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i <= q->front || i > q->rear)
		{
			printf("	|	");
		}
		else
		{
			printf("%d	|	", q->data[i]);
		}
	}
	printf("\n");
}

int Is_Full(Queue* q)
{
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
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

void Enqueue(Queue* q, element data)
{
	if (Is_Full(q) != 1)
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = data;
	}
	else
	{
		Error("Queue가 포화 상태입니다.");
		return;
	}
}

element Dequeue(Queue* q)
{
	if (Is_Empty(q) != 1)
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
	else
	{
		Error("Queue가 공백 상태입니다.");
		return;
	}
}

void Level_Order(TreeNode* ptr)
{
	Queue q;

	Init_Queue(&q);

	if (ptr == NULL) return;

	Enqueue(&q, ptr);

	while (!Is_Empty(&q))
	{
		ptr = Dequeue(&q);
		printf(" [%d] ", ptr->data);

		if (ptr->left)
		{
			Enqueue(&q, ptr->left);
		}

		if (ptr->right)
		{
			Enqueue(&q, ptr->right);
		}
	}
}

//일반적인 트리 순회
void PreOrder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(TreeNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		printf("[%d] ", root->data);
		InOrder(root->right);
	}
}

void PostOrder(TreeNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("[%d] ", root->data);
	}
}

int main()
{
	TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 1;
	n1->left = n1->right = NULL;

	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n2->data = 4;
	n2->left = n1;
	n2->right = NULL;

	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n3->data = 16;
	n3->left = n3->right = NULL;

	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n4->data = 25;
	n4->left = n4->right = NULL;

	TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n5->data = 20;
	n5->left = n3;
	n5->right = n4;

	TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));
	n6->data = 15;
	n6->left = n2;
	n6->right = n5;

	TreeNode* root = n6;
	
	//재귀를 이용한 일반적인 트리순회
	printf("전위 순회\n");
	PreOrder(root);
	printf("\n");

	printf("중위 순회\n");
	InOrder(root);
	printf("\n");

	printf("후위 순회\n");
	PostOrder(root);
	printf("\n");

	//반복문을 이용한 중위순회로 스택을 이용해야 한다.
	printf("반복문을 이용한 중위 순회\n");
	InOrder_Loop(root);
	printf("\n");

	//큐를 이용한 레벨 순회.
	printf("큐를 이용한 레벨 순회\n");
	Level_Order(root);
	printf("\n");

	return 0;
}