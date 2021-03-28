#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 10
#define MAX_MEANING_SIZE 500
#define SIZE 5
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

typedef struct
{
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

element list[SIZE]; //구조체 배열

void bubble_sort(element list[], int n)
{
	element temp;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (strcmp(list[j].word, list[j + 1].word) > 0)
			{
				SWAP(list[j], list[j + 1], temp);
			}
		}
	}
}

int main()
{
	int i;
	element temp;

	printf("5개의 단어와 의미를 입력하세요\n");

	for (i = 0; i < SIZE; i++)
	{
		scanf("%s[^\n]", list[i].word); //엔터키 제외하고 입력받기
		scanf("%s[^\n]", list[i].meaning);
	}

	bubble_sort(list, SIZE);

	printf("정렬 후 사전 내용 : \n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%s : %s \n", list[i].word, list[i].meaning);
	}

	return 0;
}