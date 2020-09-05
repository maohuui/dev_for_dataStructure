#pragma once
#include <iostream>
using namespace std;


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
	TreeNode(const int& elem, TreeNode* theLeft, TreeNode* theRight) {
		val = elem;
		left = theLeft;
		right = theRight;
	}
};