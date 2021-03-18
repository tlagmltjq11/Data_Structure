#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

//�ּ����� ���
typedef struct
{
	int id;
	int avail; //��谡 ��밡�������� �ð�
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
	while ((i != 1) && (item.avail < heap->heap[i / 2].avail))
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
		if ((child < heap->heap_size) && (heap->heap[child].avail > heap->heap[child + 1].avail))
		{
			child++;
		}

		//���� �ڽĺ��� temp�� ���� ũ�ٸ� ���̻� �������� �ʾƵ� �ǹǷ� break;
		if (heap->heap[child].avail > temp.avail)
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

#define JOBS 7
#define MACHINES 3

int main()
{
	int jobs[JOBS] = { 8,7,6,5,3,2,1 };
	element m = { 0,0 };
	Heap* h;
	h = Create();
	Init(h);

	//���� �ʱ�ȭ �� ���� ����
	for (int i = 0; i < MACHINES; i++)
	{
		m.id = i + 1;
		m.avail = 0;
		Insert(h, m);
	}

	//�ּ��������� ��踦 ���� �۾��� �Ҵ��ϰ�, ��밡�� �ð��� �������� ���� �ٽ� ����
	for (int i = 0; i < JOBS; i++)
	{
		m = Delete(h);
		printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ��Ѵ�. \n", i, m.avail, m.avail + jobs[i] - 1, m.id);
		m.avail += jobs[i];
		Insert(h, m);
	}

	return 0;
}