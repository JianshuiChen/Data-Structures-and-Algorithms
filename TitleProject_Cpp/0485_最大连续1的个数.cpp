
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 485_�������1�ĸ���
/*
����һ�����������飬 ���������������1�ĸ�����
ʾ�� 1:
����: [1,1,0,1,1,1]
���: 3
����: ��ͷ����λ��������λ��������1�������������1�ĸ����� 3.
ע�⣺
���������ֻ���� 0 ��1��
��������ĳ��������������Ҳ����� 10,000��
*/

class Solution {
public:
	// 40ms(72.8%), 11.9MB(49.2%)
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = 0;
		int max = 0;
		for (auto item : nums)
		{
			if (item == 1)
			{
				count++;
				if (count > max)
				{
					max = count;
				}
			}
			else
			{
				count = 0;
			}
		}
		return max;
	}
};
#pragma endregion
