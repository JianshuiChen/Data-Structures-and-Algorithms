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

	// 28ms, 19.9MB
	// �ݹ��㷨
public:
	bool hasPathSum(TreeNode* root, int sum) {
		int result = 0;
		return AddNumber(root, sum, result);
	}

	bool AddNumber(TreeNode* node, int& sum, int& result)
	{
		if (node == nullptr)
		{
			return false;
		}

		result += node->val;
		if (node->left != nullptr)
		{
			if (AddNumber(node->left, sum, result))
			{
				return true;
			}
		}

		if (node->right != nullptr)
		{
			if (AddNumber(node->right, sum, result))
			{
				return true;
			}
		}

		if (node->right == nullptr && node->left == nullptr)
		{
			if (sum == result)
			{
				return true;
			}
		}
		result -= node->val;
		return false;
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
		}
	}
};

#pragma endregion