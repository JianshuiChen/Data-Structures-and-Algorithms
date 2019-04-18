#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#pragma region 872_Ҷ�����Ƶ���
/*
�뿼��һ�Ŷ����������е�Ҷ�ӣ���ЩҶ�ӵ�ֵ�������ҵ�˳�������γ�һ�� Ҷֵ���� ��
�ٸ����ӣ�����ͼ��ʾ������һ��Ҷֵ����Ϊ (6, 7, 4, 9, 8) ������
��������Ŷ�������Ҷֵ��������ͬ����ô���Ǿ���Ϊ������ Ҷ���� �ġ�
�������������ͷ���ֱ�Ϊ root1 �� root2 ������Ҷ���Ƶģ��򷵻� true�����򷵻� false ��
��ʾ��
���������������ܻ��� 1 �� 100 �����
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
	// 8ms(99.87%), 14.1MB(68.46%)
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> res1;
		dfs(root1, res1);
		vector<int> res2;
		dfs(root2, res2);

		if (res1.size() != res2.size())
		{
			return false;
		}
		else
		{
			for (size_t i = 0; i < res1.size(); i++)
			{
				if (res1[i] != res2[i])
				{
					return false;
				}
			}
			return true;
		}
	}

	void dfs(TreeNode* root, vector<int>& res)
	{
		if (root == nullptr) return;
		if (root->left == nullptr && root->right == nullptr)
		{
			res.push_back(root->val);
		}
		dfs(root->left, res);
		dfs(root->right, res);
	}
};
#pragma endregion
