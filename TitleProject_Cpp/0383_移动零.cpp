#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 283_�ƶ���
/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:

����: [0,1,0,3,12]
���: [1,3,12,0,0]
˵��:

������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������
*/
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int count = nums.size();
		int left = 0;
		for (size_t i = 0; i < count; i++)
		{
			if (nums[i] != 0)
			{
				nums[left++] = nums[i];
			}
		}

		while (left < count)
		{
			nums[left++] = 0;
		}
	}
};
#pragma endregion