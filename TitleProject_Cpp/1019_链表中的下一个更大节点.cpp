
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 1019_�����е���һ������ڵ�
/*
����һ����ͷ�ڵ� head ��Ϊ��һ���ڵ�����������еĽڵ�ֱ���Ϊ��node_1, node_2, node_3, ... ��
ÿ���ڵ㶼��������һ������ֵ��next larger value�������� node_i������� next_larger(node_i) �� node_j.val��
��ô���� j > i ��  node_j.val > node_i.val���� j �ǿ��ܵ�ѡ������С���Ǹ������������������ j����ô��һ������ֵΪ 0 ��
�������������� answer������ answer[i] = next_larger(node_{i+1}) ��
ע�⣺�������ʾ���У����� [2,1,5] ���������루�������������������л���ʾ����ͷ�ڵ��ֵΪ 2���ڶ����ڵ�ֵΪ 1���������ڵ�ֵΪ 5 ��
ʾ�� 1��
���룺[2,1,5]
�����[5,5,0]
ʾ�� 2��
���룺[2,7,4,3,5]
�����[7,0,5,5,0]
ʾ�� 3��
���룺[1,7,5,1,9,2,5,1]
�����[7,9,9,9,0,5,0,0]
��ʾ��
���������е�ÿ���ڵ㣬1 <= node.val <= 10^9
�����б�ĳ����� [0, 10000] ��Χ��
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	// ���� - ��Ȼ��ʱ
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> res;
		if (head == nullptr)
		{
			return res;
		}

		// ȫ������������
		int num;
		while (head != nullptr)
		{
			res.push_back(head->val);
			head = head->next;
		}

		int len = res.size();
		for (int i = 0; i < len; i++)
		{
			int temp = i;
			while (++temp < res.size())
			{
				if (res[i] < res[temp])
				{
					res[i] = res[temp];
					break;
				}
			}
			if (temp == len)
			{
				res[i] = 0;
			}
		}
		return res;
	}

	// ��ջ - ������һһ��ջ, ���������һ������ǰһ������ʱ��ջ, �����µ�ǰλ�õ�val
	// 212ms(92.44%), 25.8MB(43.33%)
	vector<int> nextLargerNodes(ListNode* head) {
		int count = 0;
		vector<int> res;

		stack<pair<int, int>> temp; // first: value, second: index
		while (head)
		{
			res.push_back(0);
			// ջ������head��val����ջ����ֵ
			while (!temp.empty() && head->val > temp.top().first)
			{
				res[temp.top().second] = head->val;
				temp.pop();
			}
			temp.push(pair<int, int>(head->val, count++));
			head = head->next;
		}
		return res;
	}
};
#pragma endregion
