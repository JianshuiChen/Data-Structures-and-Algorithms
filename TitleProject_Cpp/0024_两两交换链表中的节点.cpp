
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 24_�������������еĽڵ�
/*
����һ���������������������ڵĽڵ㣬�����ؽ����������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
ʾ��:
���� 1->2->3->4, ��Ӧ�÷��� 2->1->4->3.
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
	// ���� : 8ms(38%), 8.88MB(87%)
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;

		ListNode * cur = head;
		ListNode * before = nullptr;
		head = head->next;
		while (cur != nullptr)
		{

			ListNode* first = cur;
			ListNode* second = first->next;
			if (second == nullptr)
			{
				break;
			}
			if (before != nullptr)
			{
				before->next = second;
			}
			before = first;
			first->next = second->next;
			second->next = first;
			cur = first->next;
		}
		return head;
	}

	// �ݹ� - 4ms(100%), 8.7MB(98.65%)
	ListNode* swapPairs(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* second = head->next;
		head->next = swapPairs(second->next);
		second->next = head;
		return second;
	}
};
#pragma endregion
