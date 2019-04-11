#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 66_��һ
/*
����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��
ʾ�� 1:
����: [1,2,3]
���: [1,2,4]
����: ���������ʾ���� 123��
ʾ�� 2:
����: [4,3,2,1]
���: [4,3,2,2]
����: ���������ʾ���� 4321��
*/

class Solution {
	// 4ms(100%), 8.5MB(69.9%)
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size() - 1;
		digits[len]++;
		for (size_t i = len; i > 0; --i)
		{
			if (digits[i] > 9)
			{
				digits[i] -= 10;
				digits[i - 1] += 1;
			}
		}

		if (digits[0] > 9)
		{
			digits[0] -= 10;
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};
#pragma endregion