#include <stdio.h>

#define MAX_SIZE 10
int list[MAX_SIZE];

#define INDEX_SIZE 256
typedef struct
{
	int key;
	int index;
}itable;
itable index_list[INDEX_SIZE]; //�ε��� ���̺�

int seq_search(int key, int low, int high)
{
	for (int i = low; i < high; i++)
	{
		if (list[i] == key)
		{
			return i; //Ž���� �����ϸ� �ε��� ��ȯ
		}
	}

	return -1; //Ž���� �����ϸ� -1 ��ȯ
}

int search_index(int key, int n)
{
	int i, low, high;

	//key���� ����Ʈ���� �������� �ʴ� ���̸� ����
	if (key < list[0] || key > list[n - 1])
	{
		return -1;
	}
	
	for (i = 0; i < INDEX_SIZE; i++)
	{
		//key���� �ε��� ���̺��� �����ϴ� ������ ��� ������ ���ϴ��� ã�Ƴ���.
		if (index_list[i].key <= key && index_list[i + 1].key > key)
		{
			break;
		}
	}

	//�ε��� ���̺��� �� ������ ���
	if (i == INDEX_SIZE)
	{
		low = index_list[i-1].index;
		high = n;
	}
	else
	{
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}

	printf("low = %d, high = %d\n", low, high);

	return seq_search(key, low, high); //������ ���������� ����Ž�� ����
}

int main()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = i + 1;
	}

	int gap = 0;
	for (int i = 0; i < MAX_SIZE && gap < MAX_SIZE; i++)
	{
		index_list[i].key = list[gap];
		index_list[i].index = gap;
		gap = gap + 3;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d %d\n", index_list[i].key, index_list[i].index);
	}
	
	printf("���� ����Ž�� ��� : %d\n", search_index(5, MAX_SIZE));
}
