#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

/*
typedef int element;
typedef struct
{
	element arr[MAX_SIZE];
	int size;
}ArrayList;

//에러출력
void error(char * m)
{
	fprintf(stderr, "%s\n", m);
	exit(1);
}

//초기화
void init(ArrayList* list)
{
	list->size = 0;
}

//어레이리스트가 비어있는지 체크
int isEmpty(ArrayList* list)
{
	return list->size == 0;
}

//포화 상태인지 체크
int isFull(ArrayList* list)
{
	return list->size == MAX_SIZE;
}

//pos 위치의 데이터를 반환한다.
element get(ArrayList* list, int pos)
{
	if (pos < 0 || pos >= list->size)
	{
		error("위치 오류");
	}

	return list->arr[pos];
}

//어레이리스트 출력
void print(ArrayList* list)
{
	for (int i = 0; i < list->size; i++)
	{
		printf("%d->", list->arr[i]);
	}
	printf("\n");
}

//맨뒤에 항목 추가
void insert_Last(ArrayList* list, element data)
{
	if (list->size >= MAX_SIZE)
	{
		error("리스트 오버플로우");
	}

	list->arr[list->size++] = data;
}

//중간에 항목을 추가하기 위해서 오른쪽으로 기존 항목들을 미뤄준다.
void insert(ArrayList* list, element data, int pos)
{
	if (!isFull(list) && (pos >= 0) && (pos <= list->size))
	{
		for (int i = (list->size - 1); i >= pos; i--)
		{
			list->arr[i + 1] = list->arr[i];
		}

		list->arr[pos] = data;
		list->size++;
	}
}

//중간 항목을 삭제하기 위해서 왼쪽으로 기존 항목들을 당겨준다.
element delete(ArrayList* list, int pos)
{
	element data;

	if (pos < 0 || pos >= list->size)
	{
		error("위치 오류");
	}

	data = list->arr[pos];

	for (int i = pos; i < (list->size - 1); i++)
	{
		list->arr[i] = list->arr[i + 1];
	}

	list->size--;

	return data;
}

int main()
{
	ArrayList list;

	init(&list);
	insert(&list, 10, 0);
	print(&list);
	insert(&list, 20, 0);
	print(&list);
	insert(&list, 30, 0);
	print(&list);
	insert_Last(&list, 40);
	print(&list);
	delete(&list, 0);
	print(&list);

	return 0;
}
*/