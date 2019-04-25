
#pragma region 258_��λ���
/*
����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����
ʾ��:
����: 38
���: 2
����: ��λ��ӵĹ���Ϊ��3 + 8 = 11, 1 + 1 = 2�� ���� 2 ��һλ�������Է��� 2��
����:
����Բ�ʹ��ѭ�����ߵݹ飬���� O(1) ʱ�临�Ӷ��ڽ�����������
*/

class Solution {
public:
	// 1. ֱ��Ӳ�� - 4ms(100%), 8.4MB(7.44%)
	int addDigits(int num) {
		while (true)
		{
			int sum = 0;
			while (num != 0)
			{
				int n = num % 10;
				sum += n;
				num /= 10;
			}
			if (sum < 10)
			{
				return sum;
			}
			num = sum;
		}
	}

	// 2 �ҹ��� - O(1) 4ms(100%, 8.3MB(20%)
	int addDigits(int num) {
		if (num > 9)
		{
			int res = num % 9;
			if (res == 0)
			{
				return 9;
			}
			return res;
		}
		return num;

		return num > 9 ? num % 9 != 0 ? num % 9 : 9 : num;
	}
};
#pragma endregion
