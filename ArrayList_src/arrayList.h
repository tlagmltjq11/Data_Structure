#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
}ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount; //���� ������ �ִ� ����
	int currentElementCount; //���� ����� ����
	ArrayListNode* pElement; //���� ������ ���� �迭
}ArrayList;

ArrayList* createArrayList(int maxElementCount); //�ִ� ������ŭ�� �迭����Ʈ�� ����
void deleteArrayList(ArrayList* pList); //�迭����Ʈ ����
int isArrayListFull(ArrayList* pList); //�迭����Ʈ�� �ڸ����ִ���
int addALElement(ArrayList* pList, int position, ArrayListNode element); //�迭����Ʈ�� �����߰�
int removeALElement(ArrayList* pList, int position); //��������
ArrayListNode* getALElement(ArrayList* pList, int position); //�迭����Ʈ�� Ư�� ���� ��ȯ
void displayArrayList(ArrayList* pList); //���
void clearArrayList(ArrayList* pList); //�ʱ�ȭ
int getArrayListLength(ArrayList* pList); //�迭����Ʈ�� Length ��ȯ
#endif

#ifndef  _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif


