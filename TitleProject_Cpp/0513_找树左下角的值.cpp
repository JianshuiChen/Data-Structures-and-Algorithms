
#pragma region 513_�������½ǵ�ֵ
/*
����һ�������������������һ���ҵ�����ߵ�ֵ��
ʾ�� 1:
����:
	2
   / \
  1   3
���:
1
ʾ�� 2:
����:
		1
	   / \
	  2   3
	 /   / \
	4   5   6
	   /
	  7
���:
7
ע��: �����Լ��������������ĸ��ڵ㣩��Ϊ NULL��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-bottom-left-tree-value
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
	// bfs - ��->�� - ����
	//Runtime: 16 ms, faster than 67.36% of C++ online submissions for Find Bottom Left Tree Value.
	//Memory Usage : 20.8 MB, less than 84.06 % of C++ online submissions for Find Bottom Left Tree Value.
	int findBottomLeftValue(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> layer;
		layer.push(root);
		int res = 0;
		while (!layer.empty())
		{
			int count = layer.size();
			res = layer.front()->val; // ÿһ�������ߵ�ֵ
			for (int i = 0; i < count; ++i)
			{
				TreeNode* node = layer.front();
				layer.pop();
				if (node->left != nullptr)
				{
					layer.push(node->left);
				}
				if (node->right != nullptr)
				{
					layer.push(node->right);
				}
			}
		}
		return res;
	}
};
#pragma endregion
