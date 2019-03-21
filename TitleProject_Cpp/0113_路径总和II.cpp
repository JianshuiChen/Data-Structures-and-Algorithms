#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 113_·���ܺ�II
/*
����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ��:
�������¶��������Լ�Ŀ��� sum = 22��

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1
����:
[
   [5,4,11,2],
   [5,8,4,5]
]
*/


 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
// dfs, 40ms(23%), 38.4MB
// -> cur�����������ͺ�16ms(����100%), 19.7MB(����93%)
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> cur;
		dfs(root, sum, cur, result);
		return result;
	}

	void dfs(TreeNode* root, int sum, vector<int>& cur, vector<vector<int>>& result)
	{
		if (root == nullptr) return;
		sum -= root->val;
		cur.push_back(root->val);
		if (root->right == nullptr && root->left == nullptr)
		{
			if (sum == 0)
			{
				result.push_back(cur);
			}
		}
		dfs(root->left, sum, cur, result);
		dfs(root->right, sum, cur, result);
		cur.pop_back();
	}
};
#pragma endregion