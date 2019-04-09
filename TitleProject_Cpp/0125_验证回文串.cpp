#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#pragma region 125_��֤���Ĵ�
/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
ʾ�� 1:
����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2
����: "race a car"
���: false
*/

class Solution {
	// ���� 48-57 A-Z 65-90 a-z 97-122
	// 12ms(77.3%), 9.8MB(5%)
public:
	bool isPalindrome(string s) {

		string str = "";

		for (size_t i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]) || isdigit(s[i]))
			{
				str += tolower(s[i]);
			}
		}
		string str2 = str;
		reverse(str.begin(), str.end());
		return str == str2;
	}
};
#pragma endregion