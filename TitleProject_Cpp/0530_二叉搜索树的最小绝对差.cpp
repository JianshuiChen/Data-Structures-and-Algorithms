#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 530_��������������С���Բ�
/*
����һ�����нڵ�Ϊ�Ǹ�ֵ�Ķ������������������������ڵ�Ĳ�ľ���ֵ����Сֵ��
ʾ�� :
����:
   1
	\
	 3
	/
   2
���:
1
����:
��С���Բ�Ϊ1������ 2 �� 1 �Ĳ�ľ���ֵΪ 1������ 2 �� 3����
ע��: ����������2���ڵ㡣
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
	// ����������õ�һ�� vector<int>, �������ԱȲ�ֵ����
	// 24ms(98%), 22.3MB(94.9%)
public:
	int getMinimumDifference(TreeNode* root) {
		vector<int> res;
		getVec(root, res);

		int num = abs(res[0] - res[1]);
		for (size_t i = 1; i < res.size() - 1; i++)
		{
			int n = abs(res[i] - res[i + 1]);
			if (n < num)
			{
				num = n;
			}
		}
		return num;
	}

	void getVec(TreeNode* root, vector<int>& res)
	{
		if (root == nullptr) return;
		getVec(root->left, res);
		res.push_back(root->val);
		getVec(root->right, res);
	}
};

#pragma endregion

int main()
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	Solution s;
	s.getMinimumDifference(root);
}