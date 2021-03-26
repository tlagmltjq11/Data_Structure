#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

//�κи���Ʈ ��������
//������ ����� �ε����� ���� ���������� �ϴ� �� ����.
void inc_insertion_sort(int list[], int first, int last, int gap)
{
	for (int i = first + gap; i <= last; i += gap)
	{
		int card = list[i];
		int j = i - gap;

		while (list[j] > card && j >= first)
		{
			list[j + gap] = list[j];
			j -= gap;
		}

		list[j + gap] = card;
	}
}

void shell_sort(int list[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0)
		{
			gap++;
		}

		for (int i = 0; i < gap; i++) //�κ� ����Ʈ�� ������ gap �̹Ƿ� gap���� �ݺ�
		{
			inc_insertion_sort(list, i, n - 1, gap); //�� �κи���Ʈ ��������
		}
	}
}

int main()
{
	n = MAX_SIZE;
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
	}

	shell_sort(list, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}