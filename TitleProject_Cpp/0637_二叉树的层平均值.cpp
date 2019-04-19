#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 637_�������Ĳ�ƽ��ֵ
/*
����һ���ǿն�����, ����һ����ÿ��ڵ�ƽ��ֵ��ɵ�����.
ʾ�� 1:
����:
	3
   / \
  9  20
	/  \
   15   7
���: [3, 14.5, 11]
����:
��0���ƽ��ֵ�� 3,  ��1���� 14.5, ��2���� 11. ��˷��� [3, 14.5, 11].
ע�⣺
�ڵ�ֵ�ķ�Χ��32λ�з���������Χ�ڡ�
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
	// ���� -> 36ms(17.4%), 24.1MB(5.3%)
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		stack<TreeNode*> curLayer;
		curLayer.push(root);
		while (!curLayer.empty())
		{
			stack<TreeNode*> nextLayer;
			double num = 0;
			int count = curLayer.size();
			while (!curLayer.empty())
			{
				TreeNode* node = curLayer.top();
				curLayer.pop();
				num += node->val;
				if (node->left != nullptr)
				{
					nextLayer.push(node->left);
				}
				if (node->right != nullptr)
				{
					nextLayer.push(node->right);
				}
			}
			num /= count;
			res.push_back(num);
			curLayer = nextLayer;
		}
		return res;
	}
};
#pragma endregion
