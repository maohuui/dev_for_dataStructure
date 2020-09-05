#include "ArrayBinaryTree.h"


ArrayBinaryTree::ArrayBinaryTree(char array[], int size) // 前序遍历数组
{
	if (size == 0)
		root = NULL;
	m_iSize = 0;
	//root = CreateTree(array, size, m_iSize); //前序遍历构建
	root = CreateTree(array, size, &m_iSize); //前序遍历构建
	cout << "---------------------------root: " << root << endl;
	PrintTreeNode(root);
}

ArrayBinaryTree::~ArrayBinaryTree()
{
	DestroyTree(root);
}

TreeNode* ArrayBinaryTree::CreateTree(char array[], int size, int* index)
{
	TreeNode* node = NULL;
	if ((*index) >= size)
		return NULL;
	
	if (array[*index] == '#')
	{
		(*index)++;
		return NULL;
	}
	else
	{
		node = new TreeNode;
		node->val = array[*index];
		(*index)++;
		node->left = CreateTree( array, size, index);
		node->right = CreateTree(array, size, index);
		return node;
	}
	
}

void ArrayBinaryTree::DestroyTree(TreeNode* node)
{
	TreeNode* deleteNode = NULL;
	if (node == NULL)
		return;
	if (node->left == NULL && node->right == NULL)
	{
		deleteNode = node;
		delete deleteNode;
		node = NULL;
		return;
	}
	DestroyTree(node->right);
	DestroyTree(node->left);
}

void ArrayBinaryTree::PrintTreeNode(TreeNode* node)
{
	if (node == NULL)
	{
		cout << "#;";
		return;
	}
	cout << node->val << ";";
	PrintTreeNode(node->left); 
	PrintTreeNode(node->right);
	
}

int ArrayBinaryTree::Height(TreeNode* node)
{
	if (node == NULL)
		return 0;
	//int leftHeight = Height(node->left) + 1;
	//int rightHeight = Height(node->right) + 1;
	int leftHeight = Height(node->left);
	int rightHeight = Height(node->right);

	return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void ArrayBinaryTree::_Preorder(TreeNode* node)
{
	if (node == NULL)
		return;
	cout << " " << node->val << " ;";
	_Preorder(node->left);
	_Preorder(node->right);
}
void ArrayBinaryTree::_InOrder(TreeNode* node)
{
	if (node == NULL)
		return;
	
	_Preorder(node->left);
	cout << " " << node->val << " ;";
	_Preorder(node->right);

}
void ArrayBinaryTree::_PostOrder(TreeNode* node)
{
	if (node == NULL)
		return;
	_Preorder(node->left);
	_Preorder(node->right);
	cout << " " << node->val << " ;";
}
void ArrayBinaryTree::_LevelOrder(TreeNode* node)
{

}

int ArrayBinaryTree::GetTreeHeight()
{
	return Height(root);
}

void ArrayBinaryTree::Preorder()
{
	cout << "---------------------------root: " << root << endl;
	_Preorder(root);
	cout << endl;
}
void ArrayBinaryTree::InOrder()
{
	cout << "---------------------------root: " << root << endl;
	_InOrder(root);
	cout << endl;
}
void ArrayBinaryTree::PostOrder()
{
	cout << "---------------------------root: " << root << endl;
	_PostOrder(root);
	cout << endl;
}
void ArrayBinaryTree::LevelOrder()
{
	_LevelOrder(root);
	cout << endl;
}