
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 1054_������ȵ�������
/*
��һ���ֿ����һ�������룬���е� i ��������Ϊ barcodes[i]��
��������������Щ�����룬ʹ�����������ڵ������� ���� ��ȡ� ����Է����κ������Ҫ��Ĵ𰸣����Ᵽ֤���ڴ𰸡�
ʾ�� 1��
���룺[1,1,1,2,2,2]
�����[2,1,2,1,2,1]
ʾ�� 2��
���룺[1,1,1,1,2,2,3,3]
�����[1,3,1,3,2,1,2,1]
��ʾ��
1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
*/

class Solution {
public:
	// ��Ϊһ���н�, ���������������� 1/2
	// ��������ż���� - ���һ������û��һ���Դ�����Ϳ��ܳ������������
	// ���ǵ�ͳ��, ˼����ͳ�Ƶķ���...
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		vector<int> res(barcodes.size());

		sort(barcodes.begin(), barcodes.end());

		int count = 0;
		for (size_t i = 0; i < res.size(); i += 2)
		{
			res[i] = barcodes[count++];
		}
		for (size_t i = 1; i < res.size(); i += 2)
		{
			res[i] = barcodes[count++];
		}

		return res;
	}

	// ͳ�����ֳ��ֵĴ���, ������������ż����
	// 224ms(74.9%), 20.3MB(100%)
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {

		vector<int> res(barcodes.size());

		map<int, int> numpair;

		for (auto item : barcodes)
		{
			numpair[item]++;
		}

		int maxKey;
		// �ҵ�����key
		for (auto item : numpair)
		{
			if (item.second > numpair[maxKey])
				maxKey = item.first;
		}

		// �Ƚ���������
		int evenIndex = 0;
		while (numpair[maxKey] > 0)
		{
			res[evenIndex] = maxKey;
			numpair[maxKey]--;
			evenIndex += 2;
		}
		int oddIndex = 1;
		for (auto item : numpair)
		{
			// ��ʣ��ż��λ������
			while (evenIndex < res.size() && item.second > 0)
			{
				res[evenIndex] = item.first;
				item.second--;
				evenIndex += 2;
			}

			// ����
			while (oddIndex < res.size() && item.second > 0)
			{
				res[oddIndex] = item.first;
				item.second--;
				oddIndex += 2;
			}
		}
		return res;
	}
};
#pragma endregion
