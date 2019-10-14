
#pragma region 404_��Ҷ��֮��
/*
���������������������Ҷ��֮�͡�

ʾ����

	3
   / \
  9  20
	/  \
   15   7

������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sum-of-left-leaves
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}

		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
		{
			return root->left->val + sumOfLeftLeaves(root->right); // �ұ��������߼�
		}
		else
		{
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right); // �����߲���Ҷ��Ҳ�������߼�
		}
	}

	// ��һ��������¼�Ƿ�Ϊ���
	//Runtime: 4 ms, faster than 82.33% of C++ online submissions for Sum of Left Leaves.
	//Memory Usage : 13.2 MB, less than 100.00 % of C++ online submissions for Sum of Left Leaves.
	int sumOfLeftLeaves(TreeNode* root) {
		int res = 0;
		dfs(root, false, res);
		return res;
	}

	void dfs(TreeNode* root, bool bIsLeft, int& res)
	{
		if (root == NULL)
		{
			return;
		}

		if (bIsLeft && root->left == NULL && root->right == NULL)
		{
			res += root->val;
		}
		else
		{
			dfs(root->left, true, res);
			dfs(root->right, false, res);
		}
	}
};
#pragma endregion
