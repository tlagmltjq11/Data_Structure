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
		//Ž�� ��ġ�� ã���� �ϴ� Ű ���� �ִ� ���� �����ϰ� �ǵ��� ����ġ�� �ִ� ��������.
		j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;

		//���ϴ� ����Ž���� ���� �˰��� ���� �߰��� ���ϴ��� ������ ���� Ư�� ��ġ���� ���ϴ��� ���̴�.
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

	printf("����Ž�� ��� : %d\n", search_Interpolation(5, MAX_SIZE));
}
