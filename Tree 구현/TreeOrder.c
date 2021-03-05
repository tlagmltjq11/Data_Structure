#include <stdio.h>
#include <stdlib.h>

//Tree�� ��ȸ�ϴ� �������� ����� ������ ��.

typedef struct TreeNode
{
	int data;
	struct TreeNode* left, * right;
}TreeNode;


//������ �̿��� �ݺ��� ��ȸ
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
		for (; root; root = root->left) //left�� �������鼭 ��� push
		{
			Push(root);
		}

		root = Pop(); //pop

		if (!root) //���ÿ� ��尡 ���� �� ����
		{
			break;
		}

		printf("[%d] ", root->data); //pop�� ����� ������ ���
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
		Error("Queue�� ��ȭ �����Դϴ�.");
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
		Error("Queue�� ���� �����Դϴ�.");
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

//�Ϲ����� Ʈ�� ��ȸ
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
	
	//��͸� �̿��� �Ϲ����� Ʈ����ȸ
	printf("���� ��ȸ\n");
	PreOrder(root);
	printf("\n");

	printf("���� ��ȸ\n");
	InOrder(root);
	printf("\n");

	printf("���� ��ȸ\n");
	PostOrder(root);
	printf("\n");

	//�ݺ����� �̿��� ������ȸ�� ������ �̿��ؾ� �Ѵ�.
	printf("�ݺ����� �̿��� ���� ��ȸ\n");
	InOrder_Loop(root);
	printf("\n");

	//ť�� �̿��� ���� ��ȸ.
	printf("ť�� �̿��� ���� ��ȸ\n");
	Level_Order(root);
	printf("\n");

	return 0;
}