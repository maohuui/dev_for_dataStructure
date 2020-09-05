#pragma once
#include <iostream>

template <class T>
struct TreeNode
{
	T val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		left = right = NULL;
	}
	TreeNode(const T& elem) {
		val = elem;
	}
	TreeNode(const T& elem, TreeNode* theLeft, TreeNode* theRight) {
		val = elem;
		left = theLeft;
		right = theRight;
	}
};

template <class T>
class BinaryTree
{
	public:
		virtual ~BinaryTree() {}
		virtual bool empty() const = 0;
		virtual int height() const = 0; // 数的高度
		virtual void Preorder() = 0;    //前序遍历
		virtual void InOrder() = 0;     //中序遍历
		virtual void PostOrder() = 0;   // 后序遍历
		virtual void LevelOrder() = 0;  // 层序遍历
};
