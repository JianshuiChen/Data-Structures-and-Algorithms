#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 367_��Ч����ȫƽ����
/*
����һ�������� num����дһ����������� num ��һ����ȫƽ�������򷵻� True�����򷵻� False��
˵������Ҫʹ���κ����õĿ⺯������  sqrt��
ʾ�� 1��
���룺16
�����True
ʾ�� 2��
���룺14
�����False
*/

class Solution {
	// һ��ķ��� - 4ms(61%), 7.9MB(95.2%)
public:
	bool isPerfectSquare(int num) {
		long n = 1; // �� int Խ��
		while (true)
		{
			long sum = n * n;
			if (sum == num)
			{
				return true;
			}
			if (sum > num)
			{
				return false;
			}
			++n;
		}
	}

	// ���ַ� - 4ms(100%), 8.1MB(42%)
	bool isPerfectSquare(int num) {
		if (num == 1) return true;

		long left = 0;
		long right = num;

		while (left < right)
		{
			long mid = (left + right + 1) / 2;

			if (mid <= num / mid)
			{
				left = mid;
			}
			else
			{
				right = mid - 1;
			}
		}
		return left * left == num;
	}
};
#pragma endregion