#include <stdio.h>
#include <stdlib.h>

/*
typedef int element;
typedef struct TreeNode
{
	element key;
	struct TreeNode* left, * right;
}TreeNode;

//반복적인 탐색
TreeNode* Search_Loop(TreeNode* root, element key)
{
	while (root != NULL)
	{
		if (root->key > key)
		{
			root = root->left;
		}
		else if (root->key < key)
		{
			root = root->right;
		}
		else
		{
			return root;
		}
	}

	return NULL;
}

//순환(재귀)적인 탐색
TreeNode* Search_Recur(TreeNode* root, element key)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (key == root->key)
	{
		return root;
	}
	else if (key > root->key)
	{
		return Search_Recur(root->right, key);
	}
	else
	{
		return Search_Recur(root->left, key);
	}
}

TreeNode* NewNode(element key)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = key;
	temp->left = temp->right = NULL;

	return temp;
}

//반복적인 삽입
TreeNode* Insert_Loop(TreeNode* root, element key)
{
	TreeNode* newNode;

	while (1)
	{
		if (key < root->key)
		{
			if (root->left == NULL)
			{
				newNode = NewNode(key);
				root->left = newNode;

				break;
			}
			else
			{
				root = root->left;
			}
		}
		else if (key > root->key)
		{
			if (root->right == NULL)
			{
				newNode = NewNode(key);
				root->right = newNode;

				break;
			}
			else
			{
				root = root->right;
			}
		}
	}

	return newNode;
}

//순환적인 삽입
TreeNode* Insert_Recur(TreeNode * root, element key)
{
	if (root == NULL)
	{
		return NewNode(key); //삽입 할 위치를 찾았으니 해당 노드를 생성 후 반환
	}

	if (key < root->key)
	{
		root->left = Insert_Recur(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = Insert_Recur(root->right, key);
	}

	return root;
}

//2개의 서브노드를 가진 노드를 삭제 시, 우측 하단에서 대체 노드를 찾기로 기준을 설정함.
TreeNode* Find_Min(TreeNode* root)
{
	TreeNode* cur = root;

	while (cur->left != NULL) 
	{
		cur = cur->left; //맨왼쪽 제일 하단 부분이 최소값이 됨.
	}

	return cur;
}


TreeNode* Delete_Recur(TreeNode* root, element key)
{
	if (root == NULL)
	{
		return root;
	}

	if (key < root->key)
	{
		root->left = Delete_Recur(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = Delete_Recur(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = Find_Min(root->right);

		root->key = temp->key;
		root->right = Delete_Recur(root->right, temp->key);
	}

	return root;
}

//중위순회 출력 
void InOrder(TreeNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		printf("[%d] ", root->key);
		InOrder(root->right);
	}
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* temp = NULL;

	printf("Recur : 재귀를 이용해 트리에 노드 삽입\n");
	root = Insert_Recur(root, 30);
	root = Insert_Recur(root, 20);
	root = Insert_Recur(root, 10);
	root = Insert_Recur(root, 40);
	root = Insert_Recur(root, 50);
	root = Insert_Recur(root, 60);

	printf("이진 탐색 트리 중위 순회 결과\n");
	InOrder(root);
	printf("\n\n");

	printf("30 삭제 후 중위 순회 결과\n");
	Delete_Recur(root, 30);
	InOrder(root);
	printf("\n\n");

	printf("60 삭제 후 중위 순회 결과\n");
	Delete_Recur(root, 60);
	InOrder(root);
	printf("\n\n");

	printf("10 삭제 후 중위 순회 결과\n");
	Delete_Recur(root, 10);
	InOrder(root);
	printf("\n\n");

	printf("Loop : 10 삽입 후 중위 순회 결과\n");
	Insert_Loop(root, 10);
	InOrder(root);
	printf("\n\n");

	printf("Loop : 60 삽입 후 중위 순회 결과\n");
	Insert_Loop(root, 60);
	InOrder(root);
	printf("\n\n");
	
	if (Search_Recur(root, 30) != NULL)
	{
		printf("Recur : 30 찾음.\n");
	}
	else
	{
		printf("Recur : 30 못찾음.\n");
	}

	if (Search_Loop(root, 30) != NULL)
	{
		printf("Loop : 30 찾음.\n");
	}
	else
	{
		printf("Loop : 30 못찾음.\n");
	}
	printf("\n\n");

	printf("Loop : 30 삽입 후 중위 순회 결과\n");
	Insert_Loop(root, 30);
	InOrder(root);
	printf("\n\n");

	if (Search_Recur(root, 30) != NULL)
	{
		printf("Recur : 30 찾음.\n");
	}
	else
	{
		printf("Recur : 30 못찾음.\n");
	}

	if (Search_Loop(root, 30) != NULL)
	{
		printf("Loop : 30 찾음.\n");
	}
	else
	{
		printf("Loop : 30 못찾음.\n");
	}
	printf("\n\n");
	return 0;
}
*/