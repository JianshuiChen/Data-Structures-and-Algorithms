#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 451_�����ַ�����Ƶ������
/*
����һ���ַ������뽫�ַ�������ַ����ճ��ֵ�Ƶ�ʽ������С�
ʾ�� 1:
����:
"tree"
���:
"eert"
����:
'e'�������Σ�'r'��'t'��ֻ����һ�Ρ�
���'e'���������'r'��'t'֮ǰ�����⣬"eetr"Ҳ��һ����Ч�Ĵ𰸡�
ʾ�� 2:
����:
"cccaaa"
���:
"cccaaa"
����:
'c'��'a'���������Ρ����⣬"aaaccc"Ҳ����Ч�Ĵ𰸡�
ע��"cacaca"�ǲ���ȷ�ģ���Ϊ��ͬ����ĸ�������һ��
ʾ�� 3:
����:
"Aabb"
���:
"bbAa"
����:
���⣬"bbaA"Ҳ��һ����Ч�Ĵ𰸣���"Aabb"�ǲ���ȷ�ġ�
ע��'A'��'a'����Ϊ�����ֲ�ͬ���ַ���
*/

class Solution {
	// 20ms(75%), 11MB(62%)
public:
	string frequencySort(string s) {
		string res;
		map<char, int> all;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (all.find(s[i]) == all.end())
			{
				all[s[i]] = 1;
			}
			else
			{
				all[s[i]]++;
			}
		}
		vector<pair<char, int>> vec;
		for (auto& item : all)
		{
			vec.push_back({ item.first, item.second });
		}
		sort(vec.begin(), vec.end(), [](pair<char, int> i1, pair<char, int> i2) {return i1.second > i2.second; });
		for (auto& item : vec)
		{
			res += string(item.second, item.first);
		}
		return res;
	}
};
#pragma endregion