#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 680_��֤�����ַ��� ��
/*
����һ���ǿ��ַ��� s�����ɾ��һ���ַ����ж��Ƿ��ܳ�Ϊ�����ַ�����
ʾ�� 1:
����: "aba"
���: True
ʾ�� 2:
����: "abca"
���: True
����: �����ɾ��c�ַ���
ע��:
�ַ���ֻ������ a-z ��Сд��ĸ���ַ�������󳤶���50000��
*/

class Solution {
	// 108ms(78%), 26.1MB(0)
public:
	bool validPalindrome(string s) {
		int left = 0;
		int right = s.length() - 1;
		bool one = false;

		while (left < right)
		{
			if (s[left] == s[right])
			{
				left++;
				right--;
			}
			else
			{
				return Repeat(left + 1, right, s) || Repeat(left, right - 1, s);
			}
		}
		return true;
	}

	bool Repeat(int left, int right, string s)
	{
		while (left < right)
		{
			if (s[left] == s[right])
			{
				left++;
				right--;
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