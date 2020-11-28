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
		printf("첫번째 원소 제거\n");
		displayArrayList(pList);
		printf("\n");

		for (int i = 0; i < getArrayListLength(pList); i++)
		{
			pValue = getALElement(pList, i);
			printf("위치[%d] : %d\n", i, pValue->data);
		}
	}

	return 0;
}

//배열리스트 생성함수
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
			printf("오류 : 메모리할당 실패 createArrayList()\n");
			return NULL;
		}
	}
	else
	{
		printf("오류 : 최대 원소 개수는 0 이상이어야 합니다.\n");
		return NULL;
	}

	//노드 배열 생성
	list->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);

	if (list->pElement == NULL)
	{
		printf("오류 : 2번째 메모리할당 실패 createArrayList()\n");
		free(list);
		return NULL;
	}

	memset(list->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return list;
}

//원소추가 함수
int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int ret = FALSE;
	
	if (pList != NULL)
	{
		//최대원소개수를 아직 다 채우지 않았는지 검사
		if (isArrayListFull(pList) != TRUE)
		{
			//알맞은 인덱스인지 검사
			if (position >= 0 && position <= pList->currentElementCount)
			{
				for (int i = pList->currentElementCount - 1; i >= position; i--)
				{
					//한칸씩 원소를 뒤로 밀어준다.
					pList->pElement[i + 1] = pList->pElement[i];
				}

				//원소추가
				pList->pElement[position] = element;
				//현재 원소개수 업데이트
				pList->currentElementCount++;

				ret = TRUE;
			}
			else
			{
				printf("오류 : Out of Index addALElement()\n");
			}
		}
		else
		{
			rintf("오류 : 용량초과 addALElement()\n");
		}
	}

	return ret;
}

//원소제거 함수
int removeALElement(ArrayList* pList, int position)
{
	int ret = FALSE;

	if (pList != NULL)
	{
		//인덱스가 알맞은지 검사
		if (position >= 0 && position < pList->currentElementCount)
		{
			for (int i = position; i < pList->currentElementCount - 1; i++)
			{
				//한칸씩 앞당겨준다.
				pList->pElement[i] = pList->pElement[i + 1];
			}
			//현재 원소개수 업데이트
			pList->currentElementCount--;
			ret = TRUE;
		}
		else
		{
			rintf("오류 : Out of Index removeALElement()\n");
		}
	}

	return ret;
}

//원소반환
ArrayListNode* getALElement(ArrayList* pList, int position)
{
	ArrayListNode* element = NULL;

	if (pList != NULL)
	{
		//알맞은 인덱스인지 검사
		if (position >= 0 && position < pList->currentElementCount)
		{
			//해당 원소의 주소를 저장.
			element = &(pList->pElement[position]);
		}
		else
		{
			rintf("오류 : Out of Index getALElement()\n");
		}
	}

	return element;
}


//배열리스트 원소 출력함수
void displayArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		printf("최대 원소 개수 : %d\n", pList->maxElementCount);
		printf("현재 원소 개수 : %d\n", pList->currentElementCount);

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


//배열리스트가 꽉 찼는지 검사하는 함수
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

//배열리스트의 길이를 반환
int getArrayListLength(ArrayList* pList)
{
	int ret = 0;

	if (pList != NULL)
	{
		ret = pList->currentElementCount;
	}

	return ret;
}

//배열리스트 삭제
void deleteArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		free(pList->pElement);
		free(pList);
	}
}