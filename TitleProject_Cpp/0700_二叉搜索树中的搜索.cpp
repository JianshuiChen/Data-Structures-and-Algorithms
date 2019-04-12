
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 700_�����������е�����
/*
����������������BST���ĸ��ڵ��һ��ֵ�� ����Ҫ��BST���ҵ��ڵ�ֵ���ڸ���ֵ�Ľڵ㡣
�����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� NULL��
���磬
��������������:
		4
	   / \
	  2   7
	 / \
	1   3
��ֵ: 2
��Ӧ�÷�����������:
	  2
	 / \
	1   3
������ʾ���У����Ҫ�ҵ�ֵ�� 5������Ϊû�нڵ�ֵΪ 5������Ӧ�÷��� NULL��
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
	// 60ms(93%), 29.1MB(96%)
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr) return nullptr;
		if (root->val == val)
			return root;
		else if (root->val > val)
			return searchBST(root->left, val);
		else
			return searchBST(root->right, val);
	}
};
#pragma endregion