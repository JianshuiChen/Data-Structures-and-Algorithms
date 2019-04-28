
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 654_��������
/*
����һ�������ظ�Ԫ�ص��������顣һ���Դ����鹹�������������������£�
�������ĸ��������е����Ԫ�ء�
��������ͨ�����������ֵ��߲��ֹ����������������
��������ͨ�����������ֵ�ұ߲��ֹ����������������
ͨ�����������鹹�������������������������ĸ��ڵ㡣
Example 1:
����: [3,2,1,6,0,5]
����: ��������������ĸ��ڵ㣺
	  6
	/   \
   3     5
	\    /
	 2  0
	   \
		1
ע��:
����������Ĵ�С�� [1, 1000] ֮�䡣
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
	// 76ms(88.8%), 28.9MB(77.59%)
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return getRoot(nums, 0, nums.size() - 1);
	}

	TreeNode* getRoot(vector<int> & nums, int left, int right)
	{
		if (left > right)
		{
			return nullptr;
		}

		// ���ҳ���Χ�ڵ����ֵ�±�
		int maxIndex = left;
		for (size_t i = left + 1; i <= right; i++)
		{
			if (nums[maxIndex] < nums[i])
			{
				maxIndex = i;
			}
		}

		TreeNode* root = new TreeNode(nums[maxIndex]);
		root->left = getRoot(nums, left, maxIndex - 1);
		root->right = getRoot(nums, maxIndex + 1, right);
		return root;
	}
};
#pragma endregion
