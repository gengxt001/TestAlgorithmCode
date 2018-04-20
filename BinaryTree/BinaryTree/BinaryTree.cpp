// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>  
#include <vector>  
#include <queue>  

using namespace std;

struct TreeNode  
{  
    int val;  
    TreeNode *left;  
    TreeNode *right;  
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
};  


//初始化一个二叉树  
TreeNode* initBTree(int elements[], int size);  

TreeNode* initBTree(int elements[], int size)  
{  
    if (size < 1)  
    {  
        return NULL;  
    }  
    //动态申请size大小的指针数组  
    TreeNode **nodes = new TreeNode*[size];  
    //将int数据转换为TreeNode节点  
    for (int i = 0; i < size; i++)  
    {  
        if (elements[i] == 0)  
        {  
            nodes[i] = NULL;  
        }  
        else  
        {  
            nodes[i] = new TreeNode(elements[i]);  
        }  
    }  
    queue<TreeNode*> nodeQueue;  
    nodeQueue.push(nodes[0]);  
  
    TreeNode *node;  
    int index = 1;  
    while (index < size)  
    {  
        node = nodeQueue.front();  
        nodeQueue.pop();  
        nodeQueue.push(nodes[index++]);  
        node->left = nodeQueue.back();  
        nodeQueue.push(nodes[index++]);  
        node->right = nodeQueue.back();  
    }  
    return nodes[0];  
}  

void PreOrder(TreeNode *root, vector<int> &result)
{
	if(root)
	{
		result.push_back(root->val);
		PreOrder(root->left, result);
		PreOrder(root->right, result);
	}
}

void MidOrder(TreeNode *root, vector<int> &result)
{
	if(root)
	{
		PreOrder(root->left, result);
		result.push_back(root->val);
		PreOrder(root->right, result);
	}
}

void PostOrder(TreeNode *root, vector<int> &result)
{
	if(root)
	{
		PreOrder(root->left, result);
		PreOrder(root->right, result);
		result.push_back(root->val);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nums[] = { 1, 2, 3, 4, 0, 5, 6, 0, 7 };  
    TreeNode *root = initBTree(nums, 9);  

	vector<int> preResult;  
	vector<int> midResult;  
	vector<int> postResult;  

	PreOrder(root, preResult);

	for(int i=0; i<preResult.size(); i++)
	{
		printf("%d\t", preResult[i]);
	}

	printf("==========\n");
	MidOrder(root, midResult);
	for(int i=0; i<midResult.size(); i++)
	{
		printf("%d\t", midResult[i]);
	}

	printf("==========\n");
	PostOrder(root, postResult);
	for(int i=0; i<postResult.size(); i++)
	{
		printf("%d\t", postResult[i]);
	}

	return 0;
}

