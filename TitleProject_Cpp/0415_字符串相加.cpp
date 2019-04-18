#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
#pragma region 415_�ַ������
/*
���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
ע�⣺
num1 ��num2 �ĳ��ȶ�С�� 5100.
num1 ��num2 ��ֻ�������� 0-9.
num1 ��num2 ���������κ�ǰ���㡣
�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��
*/

class Solution {
	// 8ms(93%), 8.9MB(100%)
public:
	string addStrings(string num1, string num2) {
		string res = "";
		int l1 = num1.size() - 1;
		int l2 = num2.size() - 1;
		int cur = 0;
		while (l1 >= 0 || l2 >= 0 || cur != 0)
		{
			if (l1 >= 0)
				cur += num1[l1--] - '0';
			if (l2 >= 0)
				cur += num2[l2--] - '0';
			res += to_string(cur % 10);
			cur /= 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
#pragma endregion