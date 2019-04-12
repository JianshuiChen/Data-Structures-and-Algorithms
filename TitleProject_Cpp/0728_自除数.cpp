
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 728_�Գ���
/*
�Գ��� ��ָ���Ա���������ÿһλ������������
���磬128 ��һ���Գ�������Ϊ 128 % 1 == 0��128 % 2 == 0��128 % 8 == 0��
���У��Գ������������ 0 ��
�����ϱ߽���±߽����֣����һ���б��б��Ԫ���Ǳ߽磨���߽磩�����е��Գ�����
ʾ�� 1��
���룺
�ϱ߽�left = 1, �±߽�right = 22
����� [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
ע�⣺
ÿ����������ı߽����� 1 <= left <= right <= 10000��
*/

class Solution {
	// 4ms(100%), 8.4MB(99.25%)
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (size_t i = left; i <= right; i++)
		{
			if (IsDividingNum(i))
			{
				res.push_back(i);
			}
		}
		return res;
	}

	bool IsDividingNum(int num)
	{
		int fix = num;
		while (num != 0)
		{
			int n = num % 10;
			if (n != 0 && fix % n == 0)
			{
				num /= 10;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
#pragma endregion
