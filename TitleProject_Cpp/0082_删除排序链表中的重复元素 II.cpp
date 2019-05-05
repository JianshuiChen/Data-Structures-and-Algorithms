
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 82_ɾ�����������е��ظ�Ԫ�� II
/*
����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
ʾ�� 1:
����: 1->2->3->3->4->4->5
���: 1->2->5
ʾ�� 2:
����: 1->1->1->2->3
���: 2->3
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
	// ���õ����͵ݹ�Ϳ�����
	// ���� + �ݹ� (˼·���������) 8ms(100%), 9.2MB(30.5%)
	ListNode* deleteDuplicates(ListNode* head) {
		head = getNotEqual(head); // �׸����⴦��
		if (head == nullptr)
		{
			return head;
		}
		ListNode* cur = head;
		while (cur != nullptr)
		{
			ListNode* old = cur->next;
			cur->next = getNotEqual(cur->next);
			if (old == cur->next)
			{
				// û��
				cur = cur->next;
			}
		}
		return head;
	}

	// ����һ���ڵ�, ������ظ��ͷ��ز��ظ����Ǹ�
	// ���û�ظ��ͷ����Լ�
	ListNode* getNotEqual(ListNode* head)
	{
		ListNode* cur = head;
		int count = 1;
		while (cur != nullptr)
		{
			if (cur->next == nullptr || cur->next->val != cur->val)
			{
				break;
			}
			cur = cur->next;
			count++;
		}
		if (count > 1)
		{
			return getNotEqual(cur->next);
		}
		return head;
	}
};
#pragma endregion

int main()
{
	ListNode* cur = new ListNode(1);
	cur->next = new ListNode(2);
	cur->next->next = new ListNode(2);
	Solution s;
	s.deleteDuplicates(cur);
}