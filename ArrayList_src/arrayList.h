#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
}ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount; //저장 가능한 최대 개수
	int currentElementCount; //현재 저장된 개수
	ArrayListNode* pElement; //원소 저장을 위한 배열
}ArrayList;

ArrayList* createArrayList(int maxElementCount); //최대 개수만큼의 배열리스트를 생성
void deleteArrayList(ArrayList* pList); //배열리스트 삭제
int isArrayListFull(ArrayList* pList); //배열리스트에 자리가있는지
int addALElement(ArrayList* pList, int position, ArrayListNode element); //배열리스트에 원소추가
int removeALElement(ArrayList* pList, int position); //원소제거
ArrayListNode* getALElement(ArrayList* pList, int position); //배열리스트의 특정 원소 반환
void displayArrayList(ArrayList* pList); //출력
void clearArrayList(ArrayList* pList); //초기화
int getArrayListLength(ArrayList* pList); //배열리스트의 Length 반환
#endif

#ifndef  _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif


