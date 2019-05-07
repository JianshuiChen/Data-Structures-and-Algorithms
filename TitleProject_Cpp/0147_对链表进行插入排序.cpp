
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 147_��������в�������
/*
��������в�������
��������Ķ�����ʾ���ϡ��ӵ�һ��Ԫ�ؿ�ʼ����������Ա���Ϊ�Ѿ����������ú�ɫ��ʾ����
ÿ�ε���ʱ���������������Ƴ�һ��Ԫ�أ��ú�ɫ��ʾ������ԭ�ؽ�����뵽���ź���������С�
���������㷨��
���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
�ظ�ֱ�������������ݲ�����Ϊֹ��
ʾ�� 1��
����: 4->2->1->3
���: 1->2->3->4
ʾ�� 2��
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
	ListNode* insertionSortList(ListNode* head) {
		ListNode* res = new ListNode(-99999);
		res->next = head;

		ListNode * item = head->next;
		head->next = nullptr;
		while (true)
		{
			ListNode* cur = res;
			while (true)
			{
				if (cur->next == nullptr)
				{
					cur->next = item;
					break;
				}
				if (item->val < cur->next->val)
				{
					ListNode* temp = item->next;
					item->next = cur->next;
					cur->next = item;
					item = temp;
					break;
				}
				cur = cur->next;
			}

			if (item == nullptr)
			{
				break;
			}
		}
		return res->next;
	}
};
#pragma endregion

int main()
{
	ListNode* node = new ListNode(3);
	node->next = new ListNode(2);
	node->next->next = new ListNode(1);
	node->next->next->next = new ListNode(4);
	Solution s;
	s.insertionSortList(node);
}