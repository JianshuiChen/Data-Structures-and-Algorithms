
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 520_����д��ĸ
/*
����һ�����ʣ�����Ҫ�жϵ��ʵĴ�дʹ���Ƿ���ȷ��
���Ƕ��壬���������ʱ�����ʵĴ�д�÷�����ȷ�ģ�
ȫ����ĸ���Ǵ�д������"USA"��
������������ĸ�����Ǵ�д������"leetcode"��
������ʲ�ֻ����һ����ĸ��ֻ������ĸ��д�� ���� "Google"��
�������Ƕ����������û����ȷʹ�ô�д��ĸ��
ʾ�� 1:
����: "USA"
���: True
ʾ�� 2:
����: "FlaG"
���: False
ע��: �������ɴ�д��Сд������ĸ��ɵķǿյ��ʡ�
*/

class Solution {
public:
	// ��������� 4ms(100%), 8.4MB(98.75%)
	bool detectCapitalUse(string word) {

		int num = 0;
		for (size_t i = 0; i < word.size(); i++)
		{
			if (isUpper(word[i]))
			{
				if (num < i) // ֻҪ��һ����д��ĸ������Сд��ĸ�������false
				{
					return false;
				}
				num++;
			}
		}

		// Ҫ����д�ַ����� == �ַ�������
		// Ҫ����д��ĸû�л�ֻ��һ��
		return num == word.size() || num <= 1;
	}

	bool isUpper(char c)
	{
		return c >= 'A' && c <= 'Z';
	}
};
#pragma endregion
