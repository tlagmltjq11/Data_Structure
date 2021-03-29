#include <stdio.h>

#define MAX_SIZE 10
int list[MAX_SIZE];

#define INDEX_SIZE 256
typedef struct
{
	int key;
	int index;
}itable;
itable index_list[INDEX_SIZE]; //인덱스 테이블

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

int search_index(int key, int n)
{
	int i, low, high;

	//key값이 리스트내에 존재하지 않는 값이면 종료
	if (key < list[0] || key > list[n - 1])
	{
		return -1;
	}
	
	for (i = 0; i < INDEX_SIZE; i++)
	{
		//key값이 인덱스 테이블내에 존재하는 값들중 어느 범위에 속하는지 찾아낸다.
		if (index_list[i].key <= key && index_list[i + 1].key > key)
		{
			break;
		}
	}

	//인덱스 테이블의 끝 범위일 경우
	if (i == INDEX_SIZE)
	{
		low = index_list[i-1].index;
		high = n;
	}
	else
	{
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}

	printf("low = %d, high = %d\n", low, high);

	return seq_search(key, low, high); //정해진 범위내에서 순차탐색 진행
}

int main()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = i + 1;
	}

	int gap = 0;
	for (int i = 0; i < MAX_SIZE && gap < MAX_SIZE; i++)
	{
		index_list[i].key = list[gap];
		index_list[i].index = gap;
		gap = gap + 3;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d %d\n", index_list[i].key, index_list[i].index);
	}
	
	printf("색인 순차탐색 결과 : %d\n", search_index(5, MAX_SIZE));
}
