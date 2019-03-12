
#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 704_���ֲ���
/*
����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��


ʾ�� 1:

����: nums = [-1,0,3,5,9,12], target = 9
���: 4
����: 9 ������ nums �в����±�Ϊ 4
ʾ�� 2:

����: nums = [-1,0,3,5,9,12], target = 2
���: -1
����: 2 ������ nums ����˷��� -1


��ʾ��

����Լ��� nums �е�����Ԫ���ǲ��ظ��ġ�
n ���� [1, 10000]֮�䡣
nums ��ÿ��Ԫ�ض����� [-9999, 9999]֮�䡣
*/
// ��׼�Ķ��ַ� - 56ms, 11.3MB ���ǳ���
int search(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}
// �������� - 84ms, 11.2MB 
int search(vector<int>& nums, int target) {
	int count = nums.size();
	for (int i = 0; i < count; i++)
	{
		if (nums[i] == target)
		{
			return i;
		}
	}
	return -1;
}
#pragma endregion