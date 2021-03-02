#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node
{
	element data;
	struct Node* link;
}Node;

typedef struct
{
	int size;
	Node* header;
}LinkedList;

//링크드리스트 초기화
void init(LinkedList* list)
{
	list->size = 0;
	list->header = NULL;
}

//링크드리스트 맨앞에 데이터 추가
int insert_First(LinkedList* list, element data)
{
	if (list != NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->link = NULL;

		if (list->header == NULL)
		{
			list->header = newNode;
			list->size++;
		}
		else
		{
			newNode->link = list->header;
			list->header = newNode;
			list->size++;
		}

		return 1;
	}
	else
	{
		return 0;
	}
}

//원하는 포지션에 데이터 추가
int insert(LinkedList* list, element data, int pos)
{
	if (list != NULL)
	{
		if (pos == 0)
		{
			insert_First(list, data);
			return 1;
		}

		if (pos >= 1 && pos <= list->size)
		{
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = data;
			newNode->link = NULL;

			Node* iter = list->header;
			for (int i = 0; i < pos - 1; i++)
			{
				iter = iter->link;
			}

			newNode->link = iter->link;
			iter->link = newNode;
			list->size++;

			return 1;
		}
	}

	return 0;
}

//첫 데이터를 제거
int delete_First(LinkedList* list)
{
	if (list != NULL && list->size != 0)
	{
		Node* delNode = list->header;
		list->header = delNode->link;

		free(delNode);

		list->size--;

		return 1;
	}

	return 0;
}

//중간 데이터를 제거
int delete(LinkedList* list, int pos)
{
	if (list != NULL && list->size != 0)
	{
		if (pos == 0)
		{
			delete_First(list);
			return 1;
		}

		if (pos >= 1 && pos < list->size)
		{
			Node* preNode = list->header;
			for (int i = 0; i < pos-1; i++)
			{
				preNode = preNode->link;
			}

			Node* delNode = preNode->link;
			preNode->link = delNode->link;
			free(delNode);

			list->size--;

			return 1;
		}
	}

	return 0;
}

//리스트 출력
void print(LinkedList* list)
{
	Node* iter = list->header;

	for (int i = 0; i < list->size; i++)
	{
		printf("%d->", iter->data);


		iter = iter->link;
	}

	printf("\n");
}

int main()
{
	LinkedList list;

	init(&list);

	insert_First(&list, 1);
	print(&list);

	insert_First(&list, 2);
	print(&list);

	insert(&list, 3, 2);
	print(&list);

	insert(&list, 4, 3);
	print(&list);

	delete_First(&list);
	print(&list);

	delete_First(&list);
	print(&list);

	delete(&list, 1);
	print(&list);

	delete(&list, 0);
	print(&list);

	return 0;
}