
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;

using namespace std;

#pragma region 102_�������Ĳ�α���
/*
����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
����:
����������: [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
�������α��������
[
  [3],
  [9,20],
  [15,7]
]
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// ���� - 24ms(����4.3%), 13.7MB  ===  Leetcode - 8ms ����100%??? 13.8MB
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr)
		{
			return result;
		}
		
		vector<TreeNode*> cur;
		cur.push_back(root);

		vector<int> curNum;
		vector<TreeNode*> next;
		while (true)
		{
			for (size_t i = 0; i < cur.size(); i++)
			{
				curNum.push_back(cur[i]->val);
				
				if (cur[i]->left != nullptr)
				{
					next.push_back(cur[i]->left);
				}
				if (cur[i]->right != nullptr)
				{
					next.push_back(cur[i]->right);
				}
			}
			result.push_back(curNum);
			if (next.size() == 0)
			{
				return result;
			}
			curNum.clear();
			cur = next;
			vector<TreeNode*> temp;
			next = temp;
		}
	}
};
#pragma endregion