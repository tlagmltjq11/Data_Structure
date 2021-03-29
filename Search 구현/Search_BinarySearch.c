#include <stdio.h>

#define MAX_SIZE 10
int list[MAX_SIZE];

int Recur_search_Binary(int key, int low, int high)
{
	int mid;

	if (low > high)
	{
		return -1;
	}

	mid = (low + high) / 2;

	if (list[mid] == key)
	{
		return mid;
	}
	else if (list[mid] > key)
	{
		Recur_search_Binary(key, low, mid - 1);
	}
	else
	{
		Recur_search_Binary(key, mid + 1, high);
	}
}

int Loop_search_Binary(int key, int low, int high)
{
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (list[mid] == key)
		{
			return mid;
		}
		else if (list[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;
}

int main()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = i + 1;
	}

	printf("순환 이진탐색 결과 : %d\n", Recur_search_Binary(5, 0, MAX_SIZE));
	printf("반복 이진탐색 결과 : %d\n", Loop_search_Binary(5, 0, MAX_SIZE));
}
