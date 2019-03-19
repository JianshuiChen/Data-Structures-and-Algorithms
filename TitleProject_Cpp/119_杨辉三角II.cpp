#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 119_�������II
/*
����һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�
����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�
ʾ��:
����: 3
���: [1,3,3,1]
���ף�
������Ż�����㷨�� O(k) �ռ临�Ӷ���
*/
// 8ms, 8.3MB
class Solution {
public:
	vector<int> getRow(int rowIndex) {

		// begin line 2
		vector<int> cur;
		cur.push_back(1);
		if (rowIndex == 0)
		{
			return cur;
		}
		cur.push_back(1);

		vector<int> next;
		for (size_t i = 0; i < rowIndex - 1; i++)
		{
			next.push_back(1);
			for (size_t i = 0; i < cur.size() - 1; i++)
			{
				next.push_back(cur[i] + cur[i + 1]);
			}
			next.push_back(1);

			cur = next;
			vector<int> tmp;
			next = tmp;
		}
		return cur;
	}
};
#pragma endregion