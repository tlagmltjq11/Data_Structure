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

//�������
void error(char * m)
{
	fprintf(stderr, "%s\n", m);
	exit(1);
}

//�ʱ�ȭ
void init(ArrayList* list)
{
	list->size = 0;
}

//��̸���Ʈ�� ����ִ��� üũ
int isEmpty(ArrayList* list)
{
	return list->size == 0;
}

//��ȭ �������� üũ
int isFull(ArrayList* list)
{
	return list->size == MAX_SIZE;
}

//pos ��ġ�� �����͸� ��ȯ�Ѵ�.
element get(ArrayList* list, int pos)
{
	if (pos < 0 || pos >= list->size)
	{
		error("��ġ ����");
	}

	return list->arr[pos];
}

//��̸���Ʈ ���
void print(ArrayList* list)
{
	for (int i = 0; i < list->size; i++)
	{
		printf("%d->", list->arr[i]);
	}
	printf("\n");
}

//�ǵڿ� �׸� �߰�
void insert_Last(ArrayList* list, element data)
{
	if (list->size >= MAX_SIZE)
	{
		error("����Ʈ �����÷ο�");
	}

	list->arr[list->size++] = data;
}

//�߰��� �׸��� �߰��ϱ� ���ؼ� ���������� ���� �׸���� �̷��ش�.
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

//�߰� �׸��� �����ϱ� ���ؼ� �������� ���� �׸���� ����ش�.
element delete(ArrayList* list, int pos)
{
	element data;

	if (pos < 0 || pos >= list->size)
	{
		error("��ġ ����");
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