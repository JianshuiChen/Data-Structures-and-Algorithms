
#pragma region 349_��������Ľ���
/*
�����������飬��дһ���������������ǵĽ�����
ʾ�� 1:
����: nums1 = [1,2,2,1], nums2 = [2,2]
���: [2]
ʾ�� 2:
����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
���: [9,4]
˵��:
�������е�ÿ��Ԫ��һ����Ψһ�ġ�
���ǿ��Բ�������������˳��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-arrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	// ������һ��, �����ֹ��Ĵ���map��
	// 16ms(73.5%), 9.3MB(61.72%)
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> temp;
		vector<int> res;

		for (size_t i = 0; i < nums1.size(); i++)
		{
			if (temp.find(nums1[i]) == temp.end())
			{
				temp[nums1[i]] = 1;
			}
		}

		for (size_t i = 0; i < nums2.size(); i++)
		{
			if (temp.find(nums2[i]) != temp.end())
			{
				if (find(res.begin(), res.end(), nums2[i]) == res.end())
				{
					res.push_back(nums2[i]);
				}
			}
		}
		return res;
	}
};
#pragma endregion
