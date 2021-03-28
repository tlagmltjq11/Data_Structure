#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	int temp;
	int low = left;
	int high = right + 1;
	int pivot = list[left];

	do
	{
		do
		{
			low++;
		} while (list[low] < pivot);

		do
		{
			high--;
		} while (list[high] > pivot);

		if (low < high)
		{
			SWAP(list[low], list[high], temp);
		}

	} while (low < high);

	SWAP(list[left], list[high], temp);

	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int p = partition(list, left, right);
		quick_sort(list, left, p - 1);
		quick_sort(list, p + 1, right);
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

	quick_sort(list, 0, n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}
