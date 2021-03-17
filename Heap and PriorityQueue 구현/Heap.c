#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct
{
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
	while ((i != 1) && (item.key > heap->heap[i / 2].key))
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
		if ((child < heap->heap_size) && (heap->heap[child].key < heap->heap[child + 1].key))
		{
			child++;
		}

		//���� �ڽĺ��� temp�� ���� ũ�ٸ� ���̻� �������� �ʾƵ� �ǹǷ� break;
		if (heap->heap[child].key <= temp.key)
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

int main()
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	Heap* heap;

	heap = Create(); //�� ����
	Init(heap); //�ʱ�ȭ

	//����
	Insert(heap, e1);
	Insert(heap, e2);
	Insert(heap, e3);

	//����
	e4 = Delete(heap);
	printf("< %d > ", e4.key);
	e5 = Delete(heap);
	printf("< %d > ", e5.key);
	e6 = Delete(heap);
	printf("< %d > ", e6.key);

	free(heap);
	return 0;
}
