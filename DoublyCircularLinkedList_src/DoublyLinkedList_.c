//���� ���� ���Ḯ��Ʈ
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node
{
	element data;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct DoublyLinkedList
{
	int size;
	Node* head;
	Node* tail;
}DoublyLinkedList;

void init(DoublyLinkedList* list)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

//�� ó���� �׸��� ������ ���
int add_First(DoublyLinkedList* list, element data)
{
	if (list != NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		if (list->head == NULL)//����Ʈ�� ����ִ� ���
		{
			list->head = newNode;
			list->tail = newNode;
			//�ڱ��ڽ��� ��ȯ
			newNode->left = list->tail;
			newNode->right = list->tail;
			
			list->size++;

			return 1;
		}
		else //����Ʈ�� ������� ������ �� ó���� �����ϴ� ���
		{
			newNode->left = list->head->left;
			list->head->left = newNode;
			newNode->right = list->head;
			list->head = newNode;
			list->tail->right = list->head;

			list->size++;

			return 1;
		}

		return 0;
	}

	return 0;
}

// �������� �߰��ϴ� ���
int add_Last(DoublyLinkedList* list, element data)
{
	if (list != NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		if (list->head == NULL)
		{
			add_First(list, data);
			return 1;
		}
		else
		{
			newNode->right = list->tail->right;
			list->tail->right = newNode;
			newNode->left = list->tail;
			list->tail = newNode;
			list->head->left = list->tail;

			list->size++;

			return 1;
		}

		return 0;
	}

	return 0;
}

int add(DoublyLinkedList* list, element data, int pos)
{
	if (list != NULL)
	{
		if (pos == 0 || list->size == 0) //�� ó���� �׸��� ������ ���
		{
			add_First(list, data);
			return 1;
		}
		else if (pos == list->size) //�� �������� �׸��� ������ ���
		{
			add_Last(list, data);
			return 1;
		}
		else if(pos >=1 && pos < list->size) //�߰��� �����ϴ� ���
		{
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = data;

			Node* iter = list->head; //tail ���� �������� ���� �� ���� ��쵵 ���� �� ����. ���� ó��
			for (int i = 0; i < pos - 1; i++)
			{
				iter = iter->right;
			}

			//�յ� �׸� ����
			newNode->right = iter->right;
			newNode->left = iter;
			iter->right->left = newNode;
			iter->right = newNode;

			list->size++;

			return 1;
		}

		return 0;
	}

	return 0;
}

int delete_First(DoublyLinkedList* list)
{
	if (list != NULL && list->size != 0)
	{
		if (list->size == 1) //����Ʈ�� �׸��� 1�� ���̶� �����ϸ� Empty �ϰ� �Ǵ� ���
		{
			Node* delNode = list->head;
			free(delNode);

			list->head = NULL;
			list->tail = NULL;
			list->size = 0;

			return 1;
		}
		else
		{
			Node* delNode = list->head;
			delNode->right->left = delNode->left;
			list->tail->right = delNode->right;
			list->head = delNode->right;
			free(delNode);

			list->size--;

			return 1;
		}
	}
}

//������ �׸��� �����ϴ� ���
int delete_Last(DoublyLinkedList* list)
{
	if (list != NULL && list->size != 0)
	{
		if (list->size == 1)
		{
			delete_First(list);
			return 1;
		}
		else
		{
			Node* delNode = list->tail;
			delNode->left->right = delNode->right;
			list->head->left = delNode->left;
			list->tail = delNode->left;
			free(delNode);

			list->size--;

			return 1;
		}
	}
}

int delete(DoublyLinkedList* list, int pos)
{
	if (list != NULL && list->size != 0)
	{
		if (pos == 0)
		{
			delete_First(list);
			return 1;
		}
		else if (pos == list->size - 1)
		{
			delete_Last(list);
			return 1;
		}
		else if(pos >= 1 && pos < list->size-1)
		{
			Node* delNode;
			
			Node* iter = list->head;
			for (int i = 0; i < pos - 1; i++)
			{
				iter = iter->right;
			}

			delNode = iter->right;
			iter->right = delNode->right;
			delNode->right->left = delNode->left;

			free(delNode);

			list->size--;

			return 1;
		}

		return 0;
	}

	return 0;
}

void print(DoublyLinkedList* list)
{
	if (list != NULL)
	{
		Node* iter = list->head;

		for (int i = 0; i < list->size; i++)
		{
			printf("<-|%d|->  ", iter->data);
			iter = iter->right;
		}

		printf("\n");
	}
}

void reverse_Print(DoublyLinkedList* list)
{
	if (list != NULL)
	{
		Node* iter = list->tail;

		for (int i = 0; i < list->size; i++)
		{
			printf("<-|%d|->  ", iter->data);
			iter = iter->left;
		}

		printf("\n");
	}
}

int main()
{
	DoublyLinkedList list;
	init(&list);

	add_First(&list, 1);
	print(&list);

	add_First(&list, 0);
	print(&list);

	add(&list, 2, 2);
	print(&list);

	add(&list, 3, 3);
	print(&list);

	add(&list, -5, 1);
	print(&list);

	add_Last(&list, 100);
	print(&list);

	delete_First(&list);
	print(&list);

	delete_Last(&list);
	print(&list);

	delete(&list, 2);
	print(&list);

	printf("reverse : ");
	reverse_Print(&list);

	return 0;
}