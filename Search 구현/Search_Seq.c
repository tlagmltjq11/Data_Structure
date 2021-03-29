#include <stdio.h>

#define MAX_SIZE 10
int list[MAX_SIZE];

int seq_search(int key, int low, int high)
{
	for (int i = low; i < high; i++)
	{
		if (list[i] == key)
		{
			return i; //탐색에 성공하면 인덱스 반환
		}
	}

	return -1; //탐색에 실패하면 -1 반환
}

//일반 순차탐색에서 loop의 매 단계마다 key와 비교하는 연산을 개선시킨 방식
//for문을 빠져나온 후 한번의 비교연산으로 결과를 나타낸다.
int adv_seq_search(int key, int low, int high)
{
	int i;
	list[high + 1] = key;
	for (i = low; list[i] != key; i++);

	if (i == high + 1) //탐색에 실패한 경우
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

	printf("일반 순차탐색 결과 : %d\n", seq_search(5, 0, MAX_SIZE - 1));
	printf("개선된 순차탐색 결과 : %d\n", adv_seq_search(5, 0, MAX_SIZE - 1));
}