#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 7

typedef struct
{
	int key;
}element;

struct list
{
	element item;
	struct list* link;
};

struct list *hash_table[TABLE_SIZE];

//제산 함수를 통한 해싱 함수
int hash_function(int key)
{
	return key % TABLE_SIZE;
}

//체인법을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link)
	{
		if (node->item.key == item.key)
		{
			printf("이미 탐색키가 저장되어 있음\n");
			return;
		}
	}

	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;

	if (node_before)
	{
		node_before->link = ptr;
	}
	else
	{
		ht[hash_value] = ptr;
	}
}

//체인법을 이용하여 탐색
void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;

	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link)
	{
		if (node->item.key == item.key)
		{
			printf("탐색 %d 성공\n", item.key);
			return;
		}
	}

	printf("키를 찾지 못함\n");
}

//해싱 테이블 출력
void hash_chain_print(struct list * ht[])
{
	struct list* node;
	int i;
	printf("\n=====================================\n");
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%d] -> ", i);
		for (node = ht[i]; node; node = node->link)
		{
			printf("[%d] -> ", node->item.key);
		}
		printf("\n");
	}
	printf("\n=====================================\n");
}

int main()
{
	int data[5] = { 8,1,9,6,13 };
	element e;

	for (int i = 0; i < 5; i++)
	{
		e.key = data[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}

	for (int i = 0; i < 5; i++)
	{
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}

	return 0;
}