﻿
#pragma region 84_柱状图中最大的矩形
/*
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
示例:
输入: [2,1,5,6,2,3]
输出: 10
*/

class Solution {
public:
	// 暴力 - O(n²) - 超时
	int largestRectangleArea(vector<int>& heights) {

		int maxArea = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			int minH = heights[i];
			maxArea = max(maxArea, minH);
			for (int j = i; j < heights.size() - 1; j++)
			{
				minH = min(minH, heights[j + 1]);
				maxArea = max(maxArea, minH * (j - i + 1));
			}
		}
		return maxArea;
	}
};
#pragma endregion

#pragma region 179_最大数
/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
示例 1:
输入: [10,2]
输出: 210
示例 2:
输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/
/*
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), func_sort);
		string str = "";
		for (size_t i = 0; i < nums.size(); i++)
		{
			str += to_string(nums[i]);
		}
		return str;
	}

	bool func_sort(int a, int b)
	{
		string res1 = to_string(a);
		string res2 = to_string(b);
		if (res1[0] == res2[0])
		{
			if (res1.length() == 1)
			{
				return res1[1] != '0';
			}
			if (res2.length() == 1)
			{
				return res2[1] != '0';
			}
			return res1[1] > res2[1];
		}
		return res1[0] > res2[0];
	}
};
*/
#pragma endregion

#pragma region 204_计数质数
/*
统计所有小于非负整数 n 的质数的数量。
示例:
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/
/*
class Solution2 {
public:
	// -- 暴力 -- 超时
	int countPrimes(int n) {
		int count = 0;
		for (size_t i = 0; i < n; i++)
		{

			if (isPrimes(i))
			{
				count++;
			}
		}
		return count;
	}

	bool isPrimes(int num)
	{
		if (num == 0 || num == 1)
		{
			return false;
		}
		int n = sqrt(num);
		for (size_t i = 2; i <= n; i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		return true;
	}

	// 厄拉多塞筛法
	int countPrimes2(int n)
	{
		if (n == 0 || n == 1)
		{
			return 0;
		}
		vector<bool> arr(n + 1, 0);
		// 0, 1 不是质数
		arr[0] = 1;
		arr[1] = 1;
		int count = 0;
		for (size_t i = 2; i < n; i++)
		{
			if (arr[i] == 0)
			{
				count++;
				// 出现一个质数, 他的倍数都不是质数
				for (int j = i * i; j < n; j += i)
				{
					arr[j] = 1;
				}
			}
		}
		return count;
	}
};

#define MAXN 100
// 数组
bool flag[MAXN] = { 0 };    //将标识初始化为true
void erat(int maxn)
{
	flag[0] = 0;            //0不是質数
	flag[1] = 0;            //1不是質数
	for (int i = 2; i <= maxn; ++i)
	{
		/*当i为質数时，i的所有倍数都不是質数*/
if (flag[i])
{
	for (int j = i * i; j <= maxn; j += i)
	{
		flag[j] = 0;
	}
}
	}
}
*/
#pragma endregion

#pragma region 687_最长同值路径
/*
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
注意：两个节点之间的路径长度由它们之间的边数表示。
示例 1:
输入:
			  5
			 / \
			4   5
		   / \   \
		  1   1   5
输出:
2
示例 2:
输入:
			  1
			 / \
			4   5
		   / \   \
		  4   4   5
输出:
2
注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
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
 /*
 class Solution3 {
 public:
	 int longestUnivaluePath(TreeNode* root) {
		 if (root == nullptr)
		 {
			 return 0;
		 }
		 int res = 1;
		 int cur = 0;
		 DFS(root->left, root->val, cur, res);
		 DFS(root->right, root->val, cur, res);
		 return res;
	 }

	 void DFS(TreeNode* root, int parent, int cur, int& res)
	 {
		 if (root == nullptr)
		 {
			 return;
		 }

		 if (root->val == parent)
		 {
			 cur++;
			 if (cur > res)
			 {
				 res = cur;
			 }
		 }
		 else
		 {
			 cur = 0;
		 }

		 DFS(root->left, root->val, cur, res);
		 DFS(root->right, root->val, cur, res);
	 }
 };
 */
#pragma endregion

#pragma region 889_根据前序和后序遍历构造二叉树
 /*
 返回与给定的前序和后序遍历匹配的任何二叉树。
  pre 和 post 遍历中的值是不同的正整数。
 示例：
 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 输出：[1,2,3,4,5,6,7]
 提示：
 1 <= pre.length == post.length <= 30
 pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
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
  /*
  class Solution4 {
  public:
	  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

	  }
  };
  */
#pragma endregion