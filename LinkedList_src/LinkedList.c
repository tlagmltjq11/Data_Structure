#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
	LinkedList* pList = createLinkedList();
	struct ListNode* pNode = NULL;
	struct ListNode node;

	if (pList != NULL)
	{
		node.data = 1;
		addLLElement(pList, 0, node);

		node.data = 3;
		addLLElement(pList, 1, node);

		node.data = 5;
		addLLElement(pList, 2, node);

		pNode = &(pList->headerNode);
		for (int i = 0; i < pList->currentElementCount; i++)
		{
			pNode = pNode->pLink;
			printf("%d : [%d]\n", i, pNode->data);
		}
	}

	return 0;
}

LinkedList* createLinkedList()
{
	LinkedList* pList = NULL;

	pList = (LinkedList*)malloc(sizeof(LinkedList));

	if (pList != NULL)
	{
		memset(pList, 0, sizeof(LinkedList));
	}
	else
	{
		printf("���� : �޸��Ҵ� createLinkedList()\n");
		return NULL;
	}

	return pList;
}

int addLLElement(LinkedList* pList, int position, struct ListNode element)
{
	int ret = FALSE;

	struct ListNode *pPreNode = NULL;
	struct ListNode *pNewNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pNewNode = (struct ListNode*)malloc(sizeof(struct ListNode));

			if (pNewNode != NULL)
			{
				*pNewNode = element;
				pNewNode->pLink = NULL;

				//������ ������� �ΰ�
				pPreNode = &(pList->headerNode);
				for (int i = 0; i < position; i++)
				{
					//��������ġ��ŭ ��ũ��Ÿ�� �Ѿ�°�.
					pPreNode = pPreNode->pLink;
				}

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;

				pList->currentElementCount++;
				ret = TRUE;
			}
			else
			{
				printf("���� : �޸��Ҵ� addLLElement()\n");
				return ret;
			}
		}
		else
		{
			printf("���� : �ε������� addLLElement()\n");
		}
	}
}

int removeLLElement(LinkedList* pList, int position)
{
	int ret = FALSE;

	struct ListNode* pPreNode = NULL;
	struct ListNode* pDelNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position < getLinkedListLength(pList))
		{
			pPreNode = &(pList->headerNode);
			for (int i = 0; i < position; i++)
			{
				pPreNode = pPreNode->pLink;
			}

			pDelNode = pPreNode->pLink;
			pPreNode->pLink = pDelNode->pLink;
			free(pDelNode);

			pList->currentElementCount--;
			ret = TRUE;
		}
		else
		{
			printf("���� : �ε������� removeLLElement()\n");
		}
	}

	return ret;
}

struct ListNode* getLLElement(LinkedList* pList, int position)
{
	struct ListNode* pNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position < pList->currentElementCount)
		{
			pNode = &(pList->headerNode);
			for (int i = 0; i < position; i++)
			{
				pNode = pNode->pLink;
			}

			return pNode;
		}
	}

	return pNode;
}

void clearLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		if (pList->currentElementCount > 0)
		{
			removeLLElement(pList, 0);
		}
	}
}

int getLinkedListLength(LinkedList* pList)
{
	if (pList != NULL)
	{
		return pList->currentElementCount;
	}

	return 0;
}

void deleteLinkedList(LinkedList* pList)
{

}