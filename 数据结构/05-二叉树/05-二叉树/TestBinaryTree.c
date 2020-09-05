//#include <stdio.h>
//
//typedef char DataType;
//
//typedef struct 
//{
//	DataType val;
//	struct TreeNode* left, * right;
//}TreeNode;
//
//TreeNode* CreateTree(char array[], int size, int* index)
//{
//	TreeNode* node = NULL;
//	if (size == 0 || (*index) >= size)
//		return NULL;
//	if (array[*index] == '#')
//	{
//		(*index)++;
//		return NULL;
//	}
//	else
//	{
//		node = (TreeNode*)malloc(sizeof(TreeNode));
//		node->val = array[*index];
//		(*index)++;
//		node->left = CreateTree(array, size, index);
//		node->right = CreateTree(array, size, index);
//		return node;
//	}
//}
//
//void PreOrder(TreeNode* root)
//{
//	if (root == NULL)
//		return;
//	printf(" %c,", root->val);
//	PreOrder(root->left);
//	PreOrder(root->right);
//}
//
//void InOrder(TreeNode* root)
//{
//	if (root == NULL)
//		return;
//	
//	InOrder(root->left);
//	printf(" %c,", root->val);
//	InOrder(root->right);
//}
//
//void PostOrder(TreeNode* root)
//{
//	if (root == NULL)
//		return;
//	PostOrder(root->left);
//	PostOrder(root->right);
//	printf(" %c,", root->val);
//}
//
//
//int main()
//{
//	char array[] = { 'A','B','D','#','#','G','#','#','C','F' };
//	int size = sizeof(array) / sizeof(array[0]);
//	int index = 0;
//	TreeNode* root = CreateTree(array, size, &index);
//
//	PreOrder(root);
//	printf("\n");
//
//	InOrder(root);
//	printf("\n");
//
//	PostOrder(root);
//	printf("\n");
//
//	return 0;
//}