#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

int main()
{
	ArrayList* pList = NULL;
	ArrayListNode* pValue = NULL;


	pList = createArrayList(5);

	if (pList != NULL)
	{
		ArrayListNode node;

		node.data = 1;
		addALElement(pList, 0, node);

		node.data = 2;
		addALElement(pList, 1, node);

		node.data = 3;
		addALElement(pList, 2, node);
		displayArrayList(pList);
		printf("\n");

		removeALElement(pList, 0);
		printf("ù��° ���� ����\n");
		displayArrayList(pList);
		printf("\n");

		for (int i = 0; i < getArrayListLength(pList); i++)
		{
			pValue = getALElement(pList, i);
			printf("��ġ[%d] : %d\n", i, pValue->data);
		}
	}

	return 0;
}

//�迭����Ʈ �����Լ�
ArrayList* createArrayList(int maxElementCount)
{
	ArrayList* list = NULL;

	if (maxElementCount > 0)
	{
		list = (ArrayList*)malloc(sizeof(ArrayList));

		if (list != NULL)
		{
			list->maxElementCount = maxElementCount;
			list->currentElementCount = 0;
			list->pElement = NULL;
		}
		else
		{
			printf("���� : �޸��Ҵ� ���� createArrayList()\n");
			return NULL;
		}
	}
	else
	{
		printf("���� : �ִ� ���� ������ 0 �̻��̾�� �մϴ�.\n");
		return NULL;
	}

	//��� �迭 ����
	list->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);

	if (list->pElement == NULL)
	{
		printf("���� : 2��° �޸��Ҵ� ���� createArrayList()\n");
		free(list);
		return NULL;
	}

	memset(list->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return list;
}

//�����߰� �Լ�
int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int ret = FALSE;
	
	if (pList != NULL)
	{
		//�ִ���Ұ����� ���� �� ä���� �ʾҴ��� �˻�
		if (isArrayListFull(pList) != TRUE)
		{
			//�˸��� �ε������� �˻�
			if (position >= 0 && position <= pList->currentElementCount)
			{
				for (int i = pList->currentElementCount - 1; i >= position; i--)
				{
					//��ĭ�� ���Ҹ� �ڷ� �о��ش�.
					pList->pElement[i + 1] = pList->pElement[i];
				}

				//�����߰�
				pList->pElement[position] = element;
				//���� ���Ұ��� ������Ʈ
				pList->currentElementCount++;

				ret = TRUE;
			}
			else
			{
				printf("���� : Out of Index addALElement()\n");
			}
		}
		else
		{
			rintf("���� : �뷮�ʰ� addALElement()\n");
		}
	}

	return ret;
}

//�������� �Լ�
int removeALElement(ArrayList* pList, int position)
{
	int ret = FALSE;

	if (pList != NULL)
	{
		//�ε����� �˸����� �˻�
		if (position >= 0 && position < pList->currentElementCount)
		{
			for (int i = position; i < pList->currentElementCount - 1; i++)
			{
				//��ĭ�� �մ���ش�.
				pList->pElement[i] = pList->pElement[i + 1];
			}
			//���� ���Ұ��� ������Ʈ
			pList->currentElementCount--;
			ret = TRUE;
		}
		else
		{
			rintf("���� : Out of Index removeALElement()\n");
		}
	}

	return ret;
}

//���ҹ�ȯ
ArrayListNode* getALElement(ArrayList* pList, int position)
{
	ArrayListNode* element = NULL;

	if (pList != NULL)
	{
		//�˸��� �ε������� �˻�
		if (position >= 0 && position < pList->currentElementCount)
		{
			//�ش� ������ �ּҸ� ����.
			element = &(pList->pElement[position]);
		}
		else
		{
			rintf("���� : Out of Index getALElement()\n");
		}
	}

	return element;
}


//�迭����Ʈ ���� ����Լ�
void displayArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		printf("�ִ� ���� ���� : %d\n", pList->maxElementCount);
		printf("���� ���� ���� : %d\n", pList->currentElementCount);

		for (int i = 0; i < pList->currentElementCount; i++)
		{
			printf("[%d] : %d\n", i, getALElement(pList, i)->data);
		}

		for (int i = pList->currentElementCount; i < pList->maxElementCount; i++)
		{
			printf("[%d] : Empty\n", i);
		}
	}
	else
	{
		printf("ArrayList is NULL");
	}
}


//�迭����Ʈ�� �� á���� �˻��ϴ� �Լ�
int isArrayListFull(ArrayList* pList)
{
	int ret = FALSE;

	if (pList != NULL)
	{
		if (pList->currentElementCount == pList->maxElementCount)
		{
			ret = TRUE;
		}
	}

	return ret;
}

//�迭����Ʈ�� ���̸� ��ȯ
int getArrayListLength(ArrayList* pList)
{
	int ret = 0;

	if (pList != NULL)
	{
		ret = pList->currentElementCount;
	}

	return ret;
}

//�迭����Ʈ ����
void deleteArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		free(pList->pElement);
		free(pList);
	}
}