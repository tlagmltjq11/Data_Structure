#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode
{
	int weight;
	char ch;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct
{
	TreeNode* ptree;
	char ch;
	int key;
}element;

typedef struct
{
	element heap[MAX_ELEMENT]; //�迭�� ����
	int heap_size;
}Heap;

Heap* Create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void Init(Heap* heap)
{
	heap->heap_size = 0;
}

void Insert(Heap* heap, element item)
{
	int i = ++(heap->heap_size); //�迭�� ������ �ε����� �⺻ ��ġ�� ����

	//���� �θ����� key������ ���Ե� ���� ũ��, ��ġ�� �ֻ����� �ƴ϶�� ����ؼ� Ʈ���� Ÿ�� �ö󰣴�.
	while ((i != 1) && (item.key < heap->heap[i / 2].key))
	{
		heap->heap[i] = heap->heap[i / 2]; //���� ���Ե� ���� �� ū ���̹Ƿ� �θ��带 ������ �������.
		i /= 2; //���Ե� �ε����� �θ���ġ�� �Ű���.
	}

	heap->heap[i] = item; //���ο� ��� ���� �Ϸ�.
}

element Delete(Heap* heap)
{
	int parent = 1; //���ܳ�尡 ��Ʈ�������� �������� ���� �� ��ġ�� ����� ����
	int child = 2; //���� �ڽ��� 2�� �ε��� ���� �����̹Ƿ� �ʱ�ȭ.
	element item, temp;

	item = heap->heap[1];
	temp = heap->heap[(heap->heap_size)--];

	while (child <= heap->heap_size)
	{
		//�� �ڽ� �� �� ū key�� ���� �ڽ��� �ε����� ���Ѵ�. -> child�� �ش� �ε����� �����.
		if ((child < heap->heap_size) && (heap->heap[child].key > heap->heap[child + 1].key))
		{
			child++;
		}

		//���� �ڽĺ��� temp�� ���� ũ�ٸ� ���̻� �������� �ʾƵ� �ǹǷ� break;
		if (heap->heap[child].key > temp.key)
		{
			break;
		}

		//�����;� �� ���
		heap->heap[parent] = heap->heap[child]; //�ڽĳ��� ��ġ�� ����
		parent = child; //���� ������ ��ġ�� �ε����� �ʱ�ȭ
		child *= 2; //������ ��ġ������ ���� �ڽĳ�� �ε����� �ʱ�ȭ
	}

	heap->heap[parent] = temp; //���������� ������ ��ġ�� temp�� �������ش�.
	return item; //item ��ȯ
}

TreeNode* MakeTree(TreeNode* left, TreeNode* right)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->left = left;
	node->right = right;
	return node;
}

void DestroyTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
}

int IsLeaf(TreeNode* root)
{
	return !(root->left) && !(root->right);
}

void PrintArr(int codes[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", codes[i]);
	}

	printf("\n");
}

void PrintCodes(TreeNode* root, int codes[], int top)
{
	if (root->left)
	{
		codes[top] = 1;
		PrintCodes(root->left, codes, top + 1);
	}

	if (root->right)
	{
		codes[top] = 0;
		PrintCodes(root->right, codes, top + 1);
	}

	if (IsLeaf(root))
	{
		printf("%c : ", root->ch);
		PrintArr(codes, top);
	}
}

void HuffmanTree(int freq[], char ch_list[], int n)
{
	int i;
	TreeNode* node, * x;
	Heap* heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = Create();
	Init(heap);

	for (i = 0; i < n; i++)
	{
		node = MakeTree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		Insert(heap, e);
	}

	for (i = 1; i < n; i++)
	{
		e1 = Delete(heap);
		e2 = Delete(heap);

		x = MakeTree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d+%d->%d \n", e1.key, e2.key, e.key);
		Insert(heap, e);
	}

	e = Delete(heap);
	PrintCodes(e.ptree, codes, top);
	DestroyTree(e.ptree);
	free(heap);
}

int main()
{
	char ch_list[] = { 's', 'i', 'n', 't', 'e' };
	int freq[] = { 4,6,8,12,15 };
	HuffmanTree(freq, ch_list, 5);
	return 0;
}