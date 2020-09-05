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
	ArrayBinaryTree(char array[], int size); // 传入层序遍历结果
	~ArrayBinaryTree();
	int GetTreeHeight();
	void Preorder();    //前序遍历
	void InOrder();   //中序遍历
	void PostOrder();   // 后序遍历
	void LevelOrder();  // 层序遍历

private:
	TreeNode* CreateTree(char array[], int size, int* index);
	void PrintTreeNode(TreeNode* node);
	void DestroyTree(TreeNode* node);
	int Height(TreeNode* node);

	void _Preorder(TreeNode* node);    //前序遍历
	void _InOrder(TreeNode* node);   //中序遍历
	void _PostOrder(TreeNode* node);   // 后序遍历
	void _LevelOrder(TreeNode* node);  // 层序遍历

private:
	TreeNode* root; //根结点
	int m_iSize;
};

