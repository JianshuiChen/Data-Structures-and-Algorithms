
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 19_ɾ������ĵ�����N���ڵ�
/*
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
ʾ����
����һ������: 1->2->3->4->5, �� n = 2.
��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����
������ n ��֤����Ч�ġ�
���ף�
���ܳ���ʹ��һ��ɨ��ʵ����
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
	// ˫ָ�� - 4ms(100%), 8.6MB(100%)
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* first = head;
		ListNode* second = head;

		// ǰָ������n��
		for (size_t i = 0; i < n; i++)
		{
			second = second->next;
		}
		if (second == nullptr)
		{
			// ֱ���ߵ���֮�� -> ˵���Ƴ�����head
			return head->next;
		}

		// ˫ָ��ͬʱǰ�� -> 
		while (true)
		{
			second = second->next;
			if (second == nullptr)
			{
				first->next = first->next->next;
				return head;
			}
			first = first->next;
		}
	}
};

#pragma endregion
