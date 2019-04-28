
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 1008_����������������
/*
���������������� preorder ��ƥ��Ķ�����������binary search tree���ĸ���㡣
(����һ�£������������Ƕ�������һ�֣���ÿ���ڵ㶼�������¹��򣬶��� node.left ���κκ����ֵ�� < node.val���� node.right ���κκ����ֵ�� > node.val�����⣬�������������ʾ�ڵ��ֵ��Ȼ����� node.left�����ű��� node.right����
ʾ����
���룺[8,5,1,7,10,12]
�����[8,5,10,1,7,null,12]
��ʾ��
1 <= preorder.length <= 100
���� preorder �е�ֵ�ǲ�ͬ�ġ�
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
	// 8ms(86.9%), 11.1MB(100%)
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		return getRoot(preorder, 0, preorder.size() - 1);
	}

	TreeNode* getRoot(vector<int> & nums, int left, int right)
	{
		if (left > right)
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(nums[left]);
		int edge = left + 1;
		for (; edge <= right; edge++)
		{
			if (nums[edge] > nums[left])
			{
				break;
			}
		}
		root->left = getRoot(nums, left + 1, edge - 1);
		root->right = getRoot(nums, edge, right);
		return root;
	}
};

#pragma endregion
