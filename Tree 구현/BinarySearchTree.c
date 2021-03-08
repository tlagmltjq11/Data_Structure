#include <stdio.h>
#include <stdlib.h>

/*
typedef int element;
typedef struct TreeNode
{
	element key;
	struct TreeNode* left, * right;
}TreeNode;

//�ݺ����� Ž��
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

//��ȯ(���)���� Ž��
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

//�ݺ����� ����
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

//��ȯ���� ����
TreeNode* Insert_Recur(TreeNode * root, element key)
{
	if (root == NULL)
	{
		return NewNode(key); //���� �� ��ġ�� ã������ �ش� ��带 ���� �� ��ȯ
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

//2���� �����带 ���� ��带 ���� ��, ���� �ϴܿ��� ��ü ��带 ã��� ������ ������.
TreeNode* Find_Min(TreeNode* root)
{
	TreeNode* cur = root;

	while (cur->left != NULL) 
	{
		cur = cur->left; //�ǿ��� ���� �ϴ� �κ��� �ּҰ��� ��.
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

//������ȸ ��� 
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

	printf("Recur : ��͸� �̿��� Ʈ���� ��� ����\n");
	root = Insert_Recur(root, 30);
	root = Insert_Recur(root, 20);
	root = Insert_Recur(root, 10);
	root = Insert_Recur(root, 40);
	root = Insert_Recur(root, 50);
	root = Insert_Recur(root, 60);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	InOrder(root);
	printf("\n\n");

	printf("30 ���� �� ���� ��ȸ ���\n");
	Delete_Recur(root, 30);
	InOrder(root);
	printf("\n\n");

	printf("60 ���� �� ���� ��ȸ ���\n");
	Delete_Recur(root, 60);
	InOrder(root);
	printf("\n\n");

	printf("10 ���� �� ���� ��ȸ ���\n");
	Delete_Recur(root, 10);
	InOrder(root);
	printf("\n\n");

	printf("Loop : 10 ���� �� ���� ��ȸ ���\n");
	Insert_Loop(root, 10);
	InOrder(root);
	printf("\n\n");

	printf("Loop : 60 ���� �� ���� ��ȸ ���\n");
	Insert_Loop(root, 60);
	InOrder(root);
	printf("\n\n");
	
	if (Search_Recur(root, 30) != NULL)
	{
		printf("Recur : 30 ã��.\n");
	}
	else
	{
		printf("Recur : 30 ��ã��.\n");
	}

	if (Search_Loop(root, 30) != NULL)
	{
		printf("Loop : 30 ã��.\n");
	}
	else
	{
		printf("Loop : 30 ��ã��.\n");
	}
	printf("\n\n");

	printf("Loop : 30 ���� �� ���� ��ȸ ���\n");
	Insert_Loop(root, 30);
	InOrder(root);
	printf("\n\n");

	if (Search_Recur(root, 30) != NULL)
	{
		printf("Recur : 30 ã��.\n");
	}
	else
	{
		printf("Recur : 30 ��ã��.\n");
	}

	if (Search_Loop(root, 30) != NULL)
	{
		printf("Loop : 30 ã��.\n");
	}
	else
	{
		printf("Loop : 30 ��ã��.\n");
	}
	printf("\n\n");
	return 0;
}
*/