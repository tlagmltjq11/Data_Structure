#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct
{
	int key;
}element;

typedef struct
{
	element heap[MAX_ELEMENT]; //배열로 구현
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
	int i = ++(heap->heap_size); //배열의 마지막 인덱스를 기본 위치로 설정

	//만약 부모노드의 key값보다 삽입될 값이 크고, 위치가 최상위가 아니라면 계속해서 트리를 타고 올라간다.
	while ((i != 1) && (item.key > heap->heap[i / 2].key))
	{
		heap->heap[i] = heap->heap[i / 2]; //현재 삽입된 값이 더 큰 값이므로 부모노드를 밑으로 끌어내린다.
		i /= 2; //삽입될 인덱스를 부모위치로 옮겨줌.
	}

	heap->heap[i] = item; //새로운 노드 삽입 완료.
}

element Delete(Heap* heap)
{
	int parent = 1; //말단노드가 루트에서부터 내려오는 과정 중 위치를 기억할 변수
	int child = 2; //비교할 자식은 2번 인덱스 부터 시작이므로 초기화.
	element item, temp;

	item = heap->heap[1];
	temp = heap->heap[(heap->heap_size)--];

	while (child <= heap->heap_size)
	{
		//두 자식 중 더 큰 key를 가진 자식의 인덱스를 구한다. -> child에 해당 인덱스가 저장됨.
		if ((child < heap->heap_size) && (heap->heap[child].key < heap->heap[child + 1].key))
		{
			child++;
		}

		//만약 자식보다 temp의 값이 크다면 더이상 내려오지 않아도 되므로 break;
		if (heap->heap[child].key <= temp.key)
		{
			break;
		}

		//내려와야 할 경우
		heap->heap[parent] = heap->heap[child]; //자식노드와 위치를 변경
		parent = child; //현재 내려온 위치로 인덱스를 초기화
		child *= 2; //내려온 위치에서의 왼쪽 자식노드 인덱스로 초기화
	}

	heap->heap[parent] = temp; //최종적으로 결정된 위치에 temp를 저장해준다.
	return item; //item 반환
}

void Heap_Sort(element a[], int n)
{
	Heap* h;

	h = Create();

	Init(h);

	for (int i = 0; i < n; i++)
	{
		Insert(h, a[i]); //힙에 원소 삽입
	}

	for (int i = n-1; i >= 0; i--)
	{
		a[i] = Delete(h); //힙에서 최대원소를 꺼내어 맨뒤부터 차례대로 채워넣는다.
	}

	free(h);
}

#define SIZE 8
int main()
{
	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	Heap_Sort(list, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", list[i].key);
	}

	printf("\n");

	return 0;
}
