
#pragma region 448_�ҵ�������������ʧ������
/*
����һ����Χ��  1 �� a[i] �� n ( n = �����С ) �� �������飬�����е�Ԫ��һЩ���������Σ���һЩֻ����һ�Ρ�
�ҵ������� [1, n] ��Χ֮��û�г����������е����֡�
�����ڲ�ʹ�ö���ռ���ʱ�临�Ӷ�ΪO(n)�������������������? ����Լٶ����ص����鲻���ڶ���ռ��ڡ�
ʾ��:
����:
[4,3,2,7,8,2,3,1]
���:
[5,6]
*/

class Solution {
public:
	// û��0���±����ȱʧ��
	// 104ms(97.04%), 15MB(63.94%)
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		for (auto item : nums)
		{
			nums[abs(item) - 1] = -abs(nums[abs(item) - 1]);
		}
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
			{
				res.push_back(i + 1);
			}
		}
		return res;
	}
};
#pragma endregion

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(8);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	s.findDisappearedNumbers(v);
}
