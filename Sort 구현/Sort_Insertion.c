#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;
void insertion_sort(int list[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp;
		int card = list[i];

		int j = i - 1;

		while (list[j] > card && j >= 0)
		{
			list[j + 1] = list[j];
			j--;
		}

		list[j + 1] = card;
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

	insertion_sort(list, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}
