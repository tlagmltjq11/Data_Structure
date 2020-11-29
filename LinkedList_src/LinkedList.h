#ifndef _LINKEDLIST_
#define _LINKEDLIST_

struct ListNode
{
	int data;
	struct ListNode* pLink;
};

typedef struct LinkedListType
{
	int currentElementCount;
	struct ListNode headerNode;
}LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, struct ListNode element);
int removeLLElement(LinkedList* pList, int position);
struct ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
#endif

#ifndef  _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
