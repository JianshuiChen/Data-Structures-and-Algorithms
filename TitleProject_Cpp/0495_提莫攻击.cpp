
#pragma region 495_��Ī����
/*
�ڡ�Ӣ�����ˡ��������У���һ���� ����Ī�� ��Ӣ�ۣ����Ĺ��������õз�Ӣ�۰�ϣ������ע���������֣������ж�״̬�����ڣ�������Ī�԰�ϣ�Ĺ���ʱ�����к���Ī�������ж�����ʱ�䣬����Ҫ�����ϣ���ж�״̬��ʱ����

�������Ϊ��Ī�ڸ�����ʱ�����й�����������ʹ��ϣ�����ж�״̬��

ʾ��1:

����: [1,4], 2
���: 4
ԭ��: �ڵ� 1 �뿪ʼʱ����Ī��ʼ�԰�ϣ���й�����ʹ�������ж����ж�״̬��ά�� 2 ���ӣ�ֱ���� 2 ���ӽ�����
�ڵ� 4 �뿪ʼʱ����Ī�ٴι�����ϣ��ʹ�ð�ϣ������� 2 ����ж�ʱ�䡣
����������� 4 �롣
ʾ��2:

����: [1,2], 2
���: 3
ԭ��: �ڵ� 1 �뿪ʼʱ����Ī��ʼ�԰�ϣ���й�����ʹ�������ж����ж�״̬��ά�� 2 ���ӣ�ֱ���� 2 ���ӽ�����
�����ڵ� 2 �뿪ʼʱ����Ī�ٴι������Ѿ������ж�״̬�İ�ϣ��
�����ж�״̬���ɵ��ӣ���Ī�ڵ� 2 �뿪ʼʱ����ι������ڵ� 3 ���ӽ�����
����������� 3��
ע�⣺

����Լٶ�ʱ������������ܳ��Ȳ����� 10000��
����Լٶ���Ī����ʱ�������е����ֺ���Ī�������ж�����ʱ�䶼�ǷǸ����������Ҳ����� 10,000,000��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/teemo-attacking
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	//Runtime: 64 ms, faster than 29.99% of C++ online submissions for Teemo Attacking.
	//Memory Usage : 10.6 MB, less than 100.00 % of C++ online submissions for Teemo Attacking.
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.empty())
		{
			return 0;
		}
		int res = 0;
		for (int i = 1; i < timeSeries.size(); ++i)
		{
			int real = timeSeries[i] - timeSeries[i - 1];
			if (real < duration)
			{
				res += real;
			}
			else
			{
				res += duration;
			}
		}
		res += duration;
		return res;
	}
};
#pragma endregion
