
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 83_ɾ�����������е��ظ�Ԫ��
/*
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
ʾ�� 1:
����: 1->1->2
���: 1->2
ʾ�� 2:
����: 1->1->2->3->3
���: 1->2->3
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
	// ���� 16ms(39.6%), 10.1MB(5.19%)
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
		{
			return head;
		}
		map<int, bool> all;
		all[head->val] = true;
		ListNode* cur = head;
		while (cur->next != nullptr)
		{
			if (all.find(cur->next->val) == all.end())
			{
				all[cur->next->val] = true;
				cur = cur->next;
			}
			else
			{
				cur->next = cur->next->next;
			}
		}
		return head;
	}

	// ��������2, ûע�����Ǹ���������, ��������
	// 12ms(100%), 9.4MB(10.6%)
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
		{
			return nullptr;
		}

		ListNode* cur = head;
		while (cur->next != nullptr)
		{
			if (cur->val == cur->next->val)
			{
				cur->next = cur->next->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		return head;
	}

	// �ݹ� -> ��Ϊ���Ǹ���������
	// ����һ���ڵ�, �����Լ�, ����ú��
	// 12ms(100%), 9.4MB(7.7%)
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		head->next = deleteDuplicates(head->next);
		if (head->next->val == head->val)
		{
			head->next = head->next->next;
		}
		return head;
	}
};
#pragma endregion
