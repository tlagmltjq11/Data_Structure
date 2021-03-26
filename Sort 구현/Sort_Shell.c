#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

//부분리스트 삽입정렬
//간격이 띄워진 인덱스를 상대로 삽입정렬을 하는 것 뿐임.
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

		for (int i = 0; i < gap; i++) //부분 리스트의 개수는 gap 이므로 gap까지 반복
		{
			inc_insertion_sort(list, i, n - 1, gap); //각 부분리스트 삽입정렬
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