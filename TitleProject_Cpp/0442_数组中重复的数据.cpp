
#pragma region 442_�������ظ�������
/*
����һ���������� a������1 �� a[i] �� n ��nΪ���鳤�ȣ�, ������ЩԪ�س������ζ�����Ԫ�س���һ�Ρ�
�ҵ����г������ε�Ԫ�ء�
����Բ��õ��κζ���ռ䲢��O(n)ʱ�临�Ӷ��ڽ�����������
ʾ����
����:
[4,3,2,7,8,2,3,1]
���:
[2,3]
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	// �� a[i] ���±�, ��ȡֵ�ظ�����res
	//Runtime : 100 ms, faster than 97.64 % of C++ online submissions for Find All Duplicates in an Array.
	//Memory Usage : 14.9 MB, less than 90.00 % of C++ online submissions for Find All Duplicates in an Array.
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			int value = abs(nums[i]);
			if (nums[value - 1] > 0)
			{
				nums[value - 1] *= -1;
			}
			else
			{
				res.push_back(value);
			}
		}
		return res;
	}
};
#pragma endregion
