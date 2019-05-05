
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 148_��������
/*
�� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£��������������
ʾ�� 1:
����: 4->2->1->3
���: 1->2->3->4
ʾ�� 2:
����: -1->5->3->4->0
���: -1->0->3->4->5
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
	// 72ms(29.31%), 13.8MB(49.79%)
	ListNode* sortList(ListNode* head) {

		vector<int> res;
		while (head != nullptr)
		{
			res.push_back(head->val);
			head = head->next;
		}

		sort(res.begin(), res.end());

		ListNode* newhead = new ListNode(0);
		ListNode* cur = newhead;
		for (auto item : res)
		{
			cur->next = new ListNode(item);
			cur = cur->next;
		}
		return newhead->next;
	}
};
#pragma endregion
