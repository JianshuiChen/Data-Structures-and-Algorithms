
#pragma region 172_�׳˺����
/*
����һ������ n������ n! ���β�������������
ʾ�� 1:
����: 3
���: 0
����: 3! = 6, β����û���㡣
ʾ�� 2:
����: 5
���: 1
����: 5! = 120, β������ 1 ����.
˵��: ���㷨��ʱ�临�Ӷ�ӦΪ O(log n) ��
*/

class Solution {
public:
	// 0ms(100%), 8.1MB(84.93%)
	int trailingZeroes(int n) {
		if (n < 5)
		{
			return 0;
		}
		else
		{
			return n / 5 + trailingZeroes(n / 5);
		}
	}
};
#pragma endregion
