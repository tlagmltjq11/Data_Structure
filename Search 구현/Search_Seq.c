#include <stdio.h>

#define MAX_SIZE 10
int list[MAX_SIZE];

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

//�Ϲ� ����Ž������ loop�� �� �ܰ踶�� key�� ���ϴ� ������ ������Ų ���
//for���� �������� �� �ѹ��� �񱳿������� ����� ��Ÿ����.
int adv_seq_search(int key, int low, int high)
{
	int i;
	list[high + 1] = key;
	for (i = low; list[i] != key; i++);

	if (i == high + 1) //Ž���� ������ ���
	{
		return -1;
	}
	else
	{
		return i;
	}
}

int main()
{
	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		list[i] = i + 1;
	}

	printf("�Ϲ� ����Ž�� ��� : %d\n", seq_search(5, 0, MAX_SIZE - 1));
	printf("������ ����Ž�� ��� : %d\n", adv_seq_search(5, 0, MAX_SIZE - 1));
}