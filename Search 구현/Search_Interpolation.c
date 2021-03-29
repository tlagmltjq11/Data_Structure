#include <stdio.h>

#define MAX_SIZE 10
int list[MAX_SIZE];

int search_Interpolation(int key, int n)
{
	int low, high, j;
	low = 0;
	high = n - 1;


	while ((list[high] >= key) && (key > list[low]))
	{
		//탐색 위치를 찾고자 하는 키 값이 있는 곳에 근접하게 되도록 가중치를 주는 보간공식.
		j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;

		//이하는 이진탐색과 같은 알고리즘 그저 중간을 비교하느냐 보간을 통해 특정 위치에서 비교하느냐 차이다.
		if (key > list[j])
		{
			low = j + 1;
		}
		else if(key < list[j])
		{
			high = j - 1;
		}
		else
		{
			low = j;
		}
	}

	if (list[low] == key)
	{
		return low;
	}
	else
	{
		return -1;
	}
}

int main()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = i + 1;
	}

	printf("보간탐색 결과 : %d\n", search_Interpolation(5, MAX_SIZE));
}
