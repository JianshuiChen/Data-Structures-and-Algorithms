
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 814_��������֦
/*
��������������� root ����������ÿ������ֵҪô�� 0��Ҫô�� 1��
�����Ƴ������в����� 1 ��������ԭ��������
( �ڵ� X ������Ϊ X �����Լ����� X �ĺ����)
ʾ��1:
����: [1,null,0,0,1]
���: [1,null,0,null,1]
����:
ֻ�к�ɫ�ڵ��������������в����� 1 ����������
��ͼΪ���صĴ𰸡�
ʾ��2:
����: [1,0,1,0,0,0,1]
���: [1,null,1,null,1]
ʾ��3:
����: [1,1,0,1,1,0,1,0]
���: [1,1,0,1,1,null,1]
˵��:
�����Ķ���������� 100 ���ڵ㡣
ÿ���ڵ��ֵֻ��Ϊ 0 �� 1 ��

������: https://leetcode-cn.com/problems/binary-tree-pruning/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	// 12ms(38%), 9.7MB(95%)
	TreeNode* pruneTree(TreeNode* root) {
		if (isEmpty(root))
		{
			// Ӧ�� [0] ���������
			return nullptr;
		}
		return root;
	}

	bool isEmpty(TreeNode* root)
	{
		if (root == nullptr)
			return true;
		if (isEmpty(root->left))
		{
			root->left = nullptr;
		}
		if (isEmpty(root->right))
		{
			root->right = nullptr;
		}
		return root->val == 0 && root->left == nullptr && root->right == nullptr;
	}
};

#pragma endregion
