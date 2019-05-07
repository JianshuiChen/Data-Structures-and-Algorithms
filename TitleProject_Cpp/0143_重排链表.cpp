
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 143_ ��������
/*
����һ�������� L��L0��L1������Ln-1��Ln ��
�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
ʾ�� 1:
�������� 1->2->3->4, ��������Ϊ 1->4->2->3.
ʾ�� 2:
�������� 1->2->3->4->5, ��������Ϊ 1->5->2->4->3.
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
	// 44ms(100%), 12.1MB(82.8%)
	// ���� -> ��ת���� -> ����ǰ��
	void reorderList(ListNode* head) {
		if (head == nullptr) return;

		// ����ָ�����
		ListNode * first = head;
		ListNode * second = head;

		while (second != nullptr && second->next != nullptr)
		{
			first = first->next;
			second = second->next->next;
		}

		// ��ת�󲿷�����
		ListNode* right = first->next;
		first->next = nullptr;
		right = reverseList(right);

		// �󲿷ֲ���ǰ��
		ListNode* cur = head;
		while (right != nullptr)
		{
			ListNode* n1 = cur->next;
			ListNode* n2 = right->next;

			cur->next = right;
			right->next = n1;
			cur = n1;
			right = n2;
		}
	}

	// ��ת����
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != nullptr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		return prev;
	}

	// �򵥴ֱ�, ���ڵ㶼�����б���
	// ��ʱ
	void reorderList(ListNode* head) {
		vector<ListNode*> list;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			list.push_back(cur);
			cur = cur->next;
		}

		int count = list.size() - 1;
		int mid = count / 2;
		for (size_t i = 0; i <= mid; i++)
		{
			list[i]->next = list[count - i];
			if (i + 1 != count - i)
			{
				list[count - i]->next = list[i + 1];
			}
		}
	}
};
#pragma endregion
