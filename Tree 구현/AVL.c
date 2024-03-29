#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

//AVL 트리 노드 정의
typedef struct AVLNode
{
	int key;
	struct AVLNode* left;
	struct AVLNode* right;
}AVLNode;

//트리의 높이를 반환
int get_height(AVLNode* node)
{
	int height = 0;
	if (node != NULL)
	{
		height = 1 + max(get_height(node->left), get_height(node->right));
	}

	return height;
}

//노드의 균형인수를 반환
int get_balance(AVLNode* node)
{
	if (node == NULL)
	{
		return 0;
	}

	return get_height(node->left) - get_height(node->right);
}

//노드를 동적으로 생성
AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//오른쪽으로 회전시키는 함수
AVLNode* rotate_right(AVLNode* parent)
{
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	//새로운 루트 반환
	return child;
}

//왼쪽으로 회전시키는 함수
AVLNode* rotate_left(AVLNode* parent)
{
	AVLNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	//새로운 루트 반환
	return child;
}

//AVL 트리에 새로운 노드 추가 함수
AVLNode* insert(AVLNode* node, int key)
{
	if (node == NULL)
	{
		return create_node(key);
	}
	
	if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
	}
	else //동일한 키는 허용하지 않음
	{
		return node;
	}

	int balance = get_balance(node); //균형인수 재계산
	
	//LL 처리
	if (balance > 1 && key < node->left->key)
	{
		return rotate_right(node);
	}

	//RR 처리
	if (balance < -1 && key > node->right->key)
	{
		return rotate_left(node);
	}

	//LR 처리
	if (balance > 1 && key > node->left->key)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	//RL 처리
	if (balance < -1 && key < node->right->key)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}

	return node;
}

//전위 순회
void preorder(AVLNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	AVLNode* root = NULL;

	//예제 트리 구축
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 29);

	printf("전위 순회 결과\n");
	preorder(root);

	return 0;
}