#pragma once
#include <iostream>
using namespace std;

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};

class ArrayBinaryTree
{
public:
	ArrayBinaryTree(char array[], int size); // �������������
	~ArrayBinaryTree();
	int GetTreeHeight();
	void Preorder();    //ǰ�����
	void InOrder();   //�������
	void PostOrder();   // �������
	void LevelOrder();  // �������

private:
	TreeNode* CreateTree(char array[], int size, int* index);
	void PrintTreeNode(TreeNode* node);
	void DestroyTree(TreeNode* node);
	int Height(TreeNode* node);

	void _Preorder(TreeNode* node);    //ǰ�����
	void _InOrder(TreeNode* node);   //�������
	void _PostOrder(TreeNode* node);   // �������
	void _LevelOrder(TreeNode* node);  // �������

private:
	TreeNode* root; //�����
	int m_iSize;
};

