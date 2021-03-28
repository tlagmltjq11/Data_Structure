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

element list[SIZE]; //����ü �迭

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

	printf("5���� �ܾ�� �ǹ̸� �Է��ϼ���\n");

	for (i = 0; i < SIZE; i++)
	{
		scanf("%s[^\n]", list[i].word); //����Ű �����ϰ� �Է¹ޱ�
		scanf("%s[^\n]", list[i].meaning);
	}

	bubble_sort(list, SIZE);

	printf("���� �� ���� ���� : \n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%s : %s \n", list[i].word, list[i].meaning);
	}

	return 0;
}