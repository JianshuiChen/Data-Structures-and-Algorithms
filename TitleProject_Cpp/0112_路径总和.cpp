#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

#pragma region 112_·���ܺ�
/*
����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:
�������¶��������Լ�Ŀ��� sum = 22��

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \      \
		7    2      1
���� true, ��Ϊ����Ŀ���Ϊ 22 �ĸ��ڵ㵽Ҷ�ӽڵ��·�� 5->4->11->2��
*/


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 // DFS(������ȱ���)
class Solution {

	// 16ms(99.8%), 19.9MB
	// �ݹ��㷨
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		sum -= root->val;
		if (root->right == nullptr && root->left == nullptr) return sum == 0;
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}

	// ����
	bool hasPathSum2(TreeNode* root, int sum)
	{
		if (root == nullptr)
		{
			return false;
		}
		int result = 0;
		stack<TreeNode*> nodeS;
		nodeS.push(root);
		while (nodeS.size() != 0)
		{
			TreeNode* cur = nodeS.top();
			nodeS.pop();
			result += cur->val;

			if (cur->right != nullptr)
			{
				nodeS.push(cur->right);
			}

			if (cur->left != nullptr)
			{
				nodeS.push(cur->left);
			}

			if (node->right == nullptr && node->left == nullptr)
			{
				if (result == sum)
				{
					return true;
				}
			}
		}
		return false;
	}
};

#pragma endregion