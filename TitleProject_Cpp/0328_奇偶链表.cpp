// TitleProject_Cpp.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 0_
/*

*/
#pragma endregion

#pragma region 328_��ż����
/*
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�
�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������
ʾ�� 1:
����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL
ʾ�� 2:
����: 2->1->3->5->6->4->7->NULL
���: 2->3->6->7->1->5->4->NULL
˵��:
Ӧ�����������ڵ��ż���ڵ�����˳��
����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�
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
	// ���� 24ms(95.33%), 9.5MB(91.97%)
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* odd = head;
		ListNode* evenhead = head->next;
		ListNode* even = evenhead;

		while (even != nullptr && even->next != nullptr)
		{
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}

		odd->next = evenhead;
		return head;
	}
};

#pragma endregion

int main()
{

}

