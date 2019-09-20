
#pragma region 539_��Сʱ���
/*
����һ�� 24 Сʱ�ƣ�Сʱ:���ӣ���ʱ���б��ҳ��б�����������ʱ�����Сʱ���ѷ�������ʾ��
ʾ�� 1��
����: ["23:59","00:00"]
���: 1
��ע:
�б���ʱ������ 2~20000 ֮�䡣
ÿ��ʱ��ȡֵ�� 00:00~23:59 ֮�䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-time-difference
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	//Runtime: 20 ms, faster than 68.12% of C++ online submissions for Minimum Time Difference.
	//Memory Usage : 12.1 MB, less than 60.00 % of C++ online submissions for Minimum Time Difference.
	int findMinDifference(vector<string>& timePoints) {
		vector<int> all;
		for (int i = 0; i < timePoints.size(); ++i)
		{
			//int point = timePoints[i].find(':');
			int hour = stoi(timePoints[i].substr(0, 2));
			int minute = stoi(timePoints[i].substr(3, 2));
			all.push_back(hour * 60 + minute);
		}
		sort(all.begin(), all.end());
		int res = all[0] + 1440 - all[all.size() - 1];
		for (int i = 0; i < all.size() - 1; ++i)
		{
			res = min(all[i + 1] - all[i], res);
		}
		return res;
	}
};
#pragma endregion
