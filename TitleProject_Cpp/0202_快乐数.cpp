
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 202_������
/*
��дһ���㷨���ж�һ�����ǲ��ǡ�����������
һ����������������Ϊ������һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���ͣ�Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ����������ѭ����ʼ�ձ䲻�� 1��������Ա�Ϊ 1����ô��������ǿ�������
ʾ��:
����: 19
���: true
����:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
	// �� map ��¼
	// 8ms(34.4%), 8.7MB(5.6%)
	bool isHappy(int n) {
		map<int, bool> res;
		while (true)
		{
			int sum = 0;
			while (n != 0)
			{
				int num = n % 10;
				sum += num * num;
				n /= 10;
			}
			if (sum == 1)
			{
				return true;
			}
			if (res.find(sum) == res.end())
			{
				res[sum] = true;
				n = sum;
			}
			else
			{
				return false;
			}
		}
	}
};

#pragma endregion
