#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int temp;
		int min = i; //인덱스로 최소값 초기화
		for (int j = i + 1; j < n; j++)
		{
			if (list[min] > list[j])
			{
				min = j;
			}
		}

		if (i != min) //동일한 것 끼리 불필요하게 연산하지 않도록함. -> 비교보다 swap 연산이 더 비용이 큼.
		{
			SWAP(list[i], list[min], temp);
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

	selection_sort(list, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}