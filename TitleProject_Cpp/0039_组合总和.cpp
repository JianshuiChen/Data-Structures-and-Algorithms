
#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 39_����ܺ�
/*
����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е����ֿ����������ظ���ѡȡ��
˵����
�������֣����� target��������������
�⼯���ܰ����ظ�����ϡ�
ʾ�� 1:
����: candidates = [2,3,6,7], target = 7,
����⼯Ϊ:
[
  [7],
  [2,2,3]
]
ʾ�� 2:
����: candidates = [2,3,5], target = 8,
����⼯Ϊ:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
// �����㷨 - 40ms(����9%), 10.3MB
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		if (candidates.size() == 0) {
			return result;
		}
		int count = 0;
		vector<int> cur;
		addNumber(candidates, target, count, cur, 0, result);
		return result;
	}

	void addNumber(vector<int>& candidates, int target, int count, vector<int>& cur, int index, vector<vector<int>>& result) {
		for (size_t i = index; i < candidates.size(); i++)
		{
			count += candidates[i];
			cur.push_back(candidates[i]);
			if (count == target)
			{
				result.push_back(cur);
			}
			else if (count < target)
			{
				addNumber(candidates, target, count, cur, i, result);
			}
			cur.pop_back();
			count -= candidates[i];
		}
	}
};
#pragma endregion