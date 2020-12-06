#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int value;
	struct ListNode* Link;
}ListNode;

typedef struct List
{
	int currentElementCount;
	ListNode* header;
	ListNode* tali;
}List;

void Add_first(List* list, int data);
void Add(List* list, int pos, int data);
void Delete_first(List* list);
void Delete(List* list, int pos);
void List_init(List* list);
void Replace(List* list, int pos, int data);
void Find(List* list, int data);
void PrintAll(List* list);

int main()
{
	List* list = (List*)malloc(sizeof(List));
	list->currentElementCount = 0;

	List_init(list);
	Add_first(list, 1);
	Add(list, 1, 2);
	Add(list, 2, 3);
	Add(list, 3, 4);
	PrintAll(list);
	printf("\n");

	Delete_first(list);
	PrintAll(list);
	printf("\n");

	Delete(list, 1);
	PrintAll(list);
	printf("\n");

	Replace(list, 0, 5);
	PrintAll(list);
}

void Add_first(List* list, int data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->value = data;

	if (list->header == NULL)
	{
		list->header = node;
		list->tali = node;
		node->Link = list->tali; //원형이기때문에 하나의 노드도 순환이되어야함.
		list->currentElementCount++;
		return;
	}
	else
	{
		node->Link = list->header;
		list->header = node;
		list->tali->Link = list->header; //tail과의 연결을 방금 추가한 첫번째 노드로 체인지.
		list->currentElementCount++;
		return;
	}
}

void Add(List* list, int pos, int data)
{
	if (pos == 0) //첫번째 자리에 넣겠다고하면 Add_first를 호출
	{
		Add_first(list, data);
		return;
	}

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->value = data;

	ListNode* iter = list->header;
	for (int i = 0; i < pos-1; i++)
	{
		iter = iter->Link;
	}

	node->Link = iter->Link;
	iter->Link = node;
	list->currentElementCount++;
}

void Delete_first(List* list)
{
	ListNode* delNode;

	if (list->currentElementCount == 1)
	{
		delNode = list->header;
		free(delNode);

		list->header = NULL;
		list->tali = NULL;
		list->currentElementCount = 0;
		return;
	}
	else
	{
		delNode = list->header;
		list->tali->Link = delNode->Link;
		list->header = delNode->Link;
		free(delNode);
		list->currentElementCount--;

		return;
	}
}

void Delete(List* list, int pos)
{
	if (pos == 0)
	{
		Delete_first(list);
		return;
	}

	ListNode* iter = list->header;
	for (int i = 0; i < pos - 1; i++)
	{
		iter = iter->Link;
	}

	ListNode* delNode = iter->Link;
	iter->Link = delNode->Link;
	free(delNode);

	list->currentElementCount--;
	return;
}

void List_init(List* list)
{
	list->header = NULL;
	list->tali = NULL;
}

void Replace(List* list, int pos, int data)
{
	ListNode* iter = list->header;
	for (int i = 0; i < pos - 1; i++)
	{
		iter = iter->Link;
	}

	iter->value = data;
}

void Find(List* list, int data)
{
	ListNode* iter = list->header;
	for (int i = 0; i < list->currentElementCount; i++)
	{
		if (iter->value == data)
		{
			printf("%d번째 노드에 %d가 존재합니다.\n", i, data);
			break;
		}

		iter = iter->Link;
	}
}

void PrintAll(List* list)
{
	ListNode* iter = list->header;
	for (int i = 0; i < list->currentElementCount; i++)
	{
		printf("[%d] : %d\n", i, iter->value);

		iter = iter->Link;
	}
}