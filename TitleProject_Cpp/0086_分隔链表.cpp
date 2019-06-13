
#pragma region 86_�ָ�����
/*
����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
ʾ��:
����: head = 1->4->3->2->5->2, x = 3
���: 1->2->2->4->3->5

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/partition-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
	// 8ms(85.77%), 8.8MB(14.2%)
	ListNode* partition(ListNode* head, int x) {
		ListNode* left_head = new ListNode(0);
		ListNode* left = left_head;
		ListNode* right_head = new ListNode(0);
		ListNode* right = right_head;

		while (head != nullptr)
		{
			if (head->val < x)
			{
				left->next = head;
				left = left->next;
			}
			else
			{
				right->next = head;
				right = right->next;
			}
			head = head->next;
		}

		left->next = right_head->next;
		right->next = nullptr;
		return left_head->next;
	}
};
#pragma endregion
