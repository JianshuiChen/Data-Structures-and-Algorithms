#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 437_·���ܺ� III - Path Sum III
/*
����һ��������������ÿ����㶼�����һ������ֵ��
�ҳ�·���͵��ڸ�����ֵ��·��������
·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
������������1000���ڵ㣬�ҽڵ���ֵ��Χ�� [-1000000,1000000] ��������
ʾ����
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
	  10
	 /  \
	5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
���� 3���͵��� 8 ��·����:
1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
*/


 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 // ��113��·������II �����ĵ�ϸ������˫�ݹ�, Ӧ�ÿ��Ը�����
 // 40ms(18%), 15.3MB(70%)
class Solution {
	int result;
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
		{
			return 0;
		}
		hasPathSum(root, sum, result);
		pathSum(root->left, sum);
		pathSum(root->right, sum);
		return result;
	}

	bool hasPathSum(TreeNode* root, int sum, int& result) {
		if (root == nullptr) return false;
		sum -= root->val;
		if (sum == 0)
		{
			result++;
		}
		return hasPathSum(root->left, sum, result) || hasPathSum(root->right, sum, result);
	}
};

#pragma endregion