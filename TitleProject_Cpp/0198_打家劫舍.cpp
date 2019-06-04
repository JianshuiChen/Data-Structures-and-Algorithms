
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 198_��ҽ���
/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�
ʾ�� 1:
����: [1,2,3,1]
���: 4
����: ͵�� 1 �ŷ��� (��� = 1) ��Ȼ��͵�� 3 �ŷ��� (��� = 3)��
	 ͵�Ե�����߽�� = 1 + 3 = 4 ��
ʾ�� 2:
����: [2,7,9,3,1]
���: 12
����: ͵�� 1 �ŷ��� (��� = 2), ͵�� 3 �ŷ��� (��� = 9)������͵�� 5 �ŷ��� (��� = 1)��
	 ͵�Ե�����߽�� = 2 + 9 + 1 = 12 ��
*/

class Solution {
public:
	// 4ms(89.16%), 8.7MB(52.58%)
	int rob(vector<int>& nums) {

		int evenSum = 0;
		int oddSum = 0;
		for (auto i = 0; i < nums.size(); i++)
		{
			if (i % 2 == 0)
			{
				evenSum += nums[i];
				evenSum = max(evenSum, oddSum);
			}
			else
			{
				oddSum += nums[i];
				oddSum = max(evenSum, oddSum);
			}
		}
		return max(evenSum, oddSum);
	}
};
#pragma endregion
