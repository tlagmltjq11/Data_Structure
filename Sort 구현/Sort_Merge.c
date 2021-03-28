#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int sorted[MAX_SIZE]; // 합병정렬에는 추가적인 메모리 공간이 필요하다.
int n;

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; //정렬된 왼쪽 리스트
	j = mid + 1; //정렬된 오른쪽 리스트
	k = left; //정렬될 추가 메모리 리스트

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
		{
			sorted[k] = list[i];
			i++;
			k++;
		}
		else
		{
			sorted[k] = list[j];
			j++;
			k++;
		}
	}

	if (i > mid) //왼쪽 배열이 먼저 끝난 경우
	{
		for (l = j; l <= right; l++)
		{
			sorted[k] = list[l];
			k++;
		}
	}
	else //오른쪽 배열이 먼저 끝난 경우
	{
		for (l = i; l <= mid; l++)
		{
			sorted[k] = list[l];
			k++;
		}
	}

	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l]; //list 배열에 실제 정렬된 데이터 복사
	}

}

void merge_sort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
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

	merge_sort(list, 0, n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}
