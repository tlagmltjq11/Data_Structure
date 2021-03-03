#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node
{
	element data;
	struct Node* link;
}Node;

typedef struct CircularLinkedList
{
	int size;
	Node* header;
	Node* tail;
}CircularLinkedList;

void init(CircularLinkedList* list)
{
	list->size = 0;
	list->header = NULL;
	list->tail = NULL;
}

int add_First(CircularLinkedList* list, element data)
{
	if (list != NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		if (list->header == NULL)
		{
			list->header = newNode;
			list->tail = newNode;
			newNode->link = list->tail; //자기 자신을 가르키도록 하여 순환시킨다.
			
			list->size++;

			return 1;
		}
		else
		{
			newNode->link = list->header;
			list->header = newNode;
			list->tail->link = list->header;

			list->size++;

			return 1;
		}
	}

	return 0;
}

int add_Last(CircularLinkedList* list, element data)
{
	if (list != NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		if (list->header == NULL)
		{
			add_First(list, data);
			return 1;
		}
		else
		{
			newNode->link = list->tail->link;
			list->tail->link = newNode;
			list->tail = newNode;

			list->size++;

			return 1;
		}
	}

	return 0;
}

int add(CircularLinkedList* list, element data, int pos)
{
	if (list != NULL)
	{
		if (pos == 0) //맨 처음에 항목을 삽입할 경우
		{
			add_First(list, data);
			return 1;
		}
		else if (pos == list->size) //맨 마지막에 항목을 삽입할 경우
		{
			add_Last(list, data);
			return 1;
		}
		else if (pos >= 1 && pos < list->size) //중간에 항목을 삽입할 경우
		{
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = data;

			Node* iter = list->header;
			for(int i=0; i<pos-1; i++)
			{
				iter = iter->link;
			}

			newNode->link = iter->link;
			iter->link = newNode;

			list->size++;

			return 1;
		}

		return 0;
	}

	return 0;
}

int delete_First(CircularLinkedList* list)
{
	if (list != NULL)
	{
		if (list->size == 1)
		{
			Node* delNode = list->header;
			free(delNode);

			list->header = NULL;
			list->tail = NULL;
			list->size = 0;

			return 1;
		}
		else
		{
			Node* delNode = list->header;
			list->tail->link = delNode->link;
			list->header = delNode->link;
			
			free(delNode);

			list->size--;

			return 1;
		}

		return 0;
	}

	return 0;
}

int delete(CircularLinkedList* list, int pos)
{
	if (list != NULL)
	{
		if (pos == 0) //맨 처음 항목을 제거할 경우
		{
			delete_First(list);
			return 1;
		}

		if (pos >= 1 && pos < list->size) //중간 항목을 삭제할 경우
		{
			Node* iter = list->header;
			for (int i = 0; i < pos - 1; i++)
			{
				iter = iter->link;
			}

			if (pos == list->size - 1)
			{
				list->tail = iter;
			}

			Node* delNode = iter->link;
			iter->link = delNode->link;

			free(delNode);

			list->size--;

			return 1;
		}

		return 0;
	}

	return 0;
}

void print(CircularLinkedList* list)
{
	Node* iter = list->header;

	for (int i = 0; i < list->size; i++)
	{
		printf("%d->", iter->data);
		iter = iter->link;
	}
	printf("	tail link value : %d \n", list->tail->link->data);
}

int main()
{
	CircularLinkedList list;

	init(&list);

	add_First(&list, 3);
	print(&list);

	add(&list, 4, 0);
	print(&list);

	add(&list, 5, 2);
	print(&list);

	add_First(&list, 2);
	print(&list);

	delete_First(&list);
	print(&list);

	delete(&list, 1);
	print(&list);

	add(&list, 10, 2);
	print(&list);

	add(&list, -3, 0);
	print(&list);

	delete_First(&list);
	print(&list);

	delete(&list, 2);
	print(&list);

	return 0;
}