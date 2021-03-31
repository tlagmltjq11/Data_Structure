#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10
#define TABLE_SIZE 13

typedef struct
{
	char key[KEY_SIZE];
}element;

element hash_table[TABLE_SIZE];

//테이블 초기화
void init_table(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
	{
		ht[i].key[0] = NULL;
	}
}

//문자로 된 키를 숫자로 변환
//문자열의 각 아스키 코드를 전부 합하는 방식을 사용.
int transform(char* key)
{
	int number = 0;

	while (*key)
	{
		number = number + (*key++);
	}

	return number;
}

//제산 함수를 사용한 해싱 함수
int hash_function(char* key)
{
	return transform(key) % TABLE_SIZE;
}

#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

//선형 조사법을 이용하여 테이블에 키를 삽입하고, 테이블이 가득 찬 경우 종료
void hash_lp_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);

	while (!empty(ht[i]))
	{
		if (equal(item, ht[i]))
		{
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}

		i = (i + 1) % TABLE_SIZE; //다시 1로 순환가능

		if (i == hash_value)
		{
			fprintf(stderr, "테이블이 가득찼습니다.\n");
			exit(1);
		}
	}

	ht[i] = item;
}

void hash_lp_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);

	while (!empty(ht[i]))
	{
		if (equal(item, ht[i]))
		{
			printf("탐색 %s : 위치 = %d\n", item.key, i);
			return;
		}

		i = (i + 1) % TABLE_SIZE; //다시 1로 순환가능

		if (i == hash_value)
		{
			printf("찾는 값이 테이블이 없음\n");
			return;
		}
	}

	printf("찾는 값이 테이블이 없음\n");
}

//해싱 테이블 출력
void hash_lp_print(element ht[])
{
	int i;
	printf("\n=====================================\n");
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%d] %s\n", i, ht[i].key);
	}
	printf("\n=====================================\n");
}

//예제
int main()
{
	char* s[7] = { "do", "for", "if", "case", "else", "return", "function" };
	element e;

	for (int i = 0; i < 7; i++)
	{
		strcpy(e.key, s[i]);
		hash_lp_add(e, hash_table);
		hash_lp_print(hash_table);
	}

	for (int i = 0; i < 7; i++)
	{
		strcpy(e.key, s[i]);
		hash_lp_search(e, hash_table);
	}

	return 0;
}