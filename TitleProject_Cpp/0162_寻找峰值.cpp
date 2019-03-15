#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 162_Ѱ�ҷ�ֵ
/*
��ֵԪ����ָ��ֵ������������ֵ��Ԫ�ء�
����һ���������� nums������ nums[i] �� nums[i+1]���ҵ���ֵԪ�ز�������������
������ܰ��������ֵ������������£������κ�һ����ֵ����λ�ü��ɡ�
����Լ��� nums[-1] = nums[n] = -�ޡ�
ʾ�� 1:
����: nums = [1,2,3,1]
���: 2
����: 3 �Ƿ�ֵԪ�أ���ĺ���Ӧ�÷��������� 2��
ʾ�� 2:
����: nums = [1,2,1,3,5,6,4]
���: 1 �� 5
����: ��ĺ������Է������� 1�����ֵԪ��Ϊ 2��
	 ���߷������� 5�� ���ֵԪ��Ϊ 6��
˵��:
��ĽⷨӦ���� O(logN) ʱ�临�Ӷȵġ�
*/

class Solution {
public:
	// 12ms(����16.2%)��9MB - �����ж��ɣ�Ӣ�İ��8ms, ����99.31%
	// ���֣�nums[mid - 1] < nums[mid], �����һ��һ���з�ֵ
	int findPeakElement(vector<int>& nums) {
		if (nums.size()==1)
		{
			return 0;
		}
		int left = 0;
		int right = nums.size() - 1;

		while (left + 1 < right)
		{
			int mid = (left + right) / 2;
			if (mid > 0 && nums[mid - 1] < nums[mid]){
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return nums[left] > nums[right] ? left : right; 
	}
};
#pragma endregion