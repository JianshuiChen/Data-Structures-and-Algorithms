#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 965_��ֵ������
/*
���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
ʾ�� 1��
���룺[1,1,1,1,1,null,1]
�����true
ʾ�� 2��
���룺[2,2,2,5,2]
�����false
��ʾ��
�������Ľڵ�����Χ�� [1, 100]��
ÿ���ڵ��ֵ������������ΧΪ [0, 99] ��
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

	// 4ms(100%), 10.7MB(99.47%)
public:
	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}

		if (root->left == nullptr && root->right == nullptr)
		{
			return true;
		}
		else if (root->left != nullptr && root->right != nullptr)
		{
			if (root->left->val == root->val && root->right->val == root->val)
			{
				return isUnivalTree(root->left) && isUnivalTree(root->right);
			}
			else
			{
				return false;
			}
		}
		else if (root->left != nullptr)
		{
			if (root->left->val == root->val)
			{
				return isUnivalTree(root->left);
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (root->right->val == root->val)
			{
				return isUnivalTree(root->right);
			}
			else
			{
				return false;
			}
		}
	}
};
#pragma endregion