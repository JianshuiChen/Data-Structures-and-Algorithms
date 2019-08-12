
#pragma region 575_���ǹ�
/*
����һ��ż�����ȵ����飬���в�ͬ�����ִ����Ų�ͬ������ǹ���ÿһ�����ִ���һ���ǹ���
����Ҫ����Щ�ǹ�ƽ���ָ�һ���ܵܺ�һ�����á��������ÿ��Ի�õ�����ǹ�����������
ʾ�� 1:
����: candies = [1,1,2,2,3,3]
���: 3
����: һ��������������ǹ���ÿһ�ֶ���������
	 ���ŷ��䷽�������û��[1,2,3],�ܵ�Ҳ���[1,2,3]������ʹ���û���ǹ�����������ࡣ
ʾ�� 2 :
����: candies = [1,1,2,3]
���: 2
����: ���û���ǹ�[2,3],�ܻܵ���ǹ�[1,1]�����������ֲ�ͬ���ǹ����ܵ�ֻ��һ�֡�����ʹ�����ÿ��Ի�õ��ǹ���������ࡣ
ע��:
����ĳ���Ϊ[2, 10,000]������ȷ��Ϊż����
���������ֵĴ�С�ڷ�Χ[-100,000, 100,000]�ڡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/distribute-candies
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	/*
	const static auto ioSpeedUp = []() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		return NULL;
	}();
	*/
	//Runtime: 284 ms, faster than 73.65% of C++ online submissions for Distribute Candies.
	//Memory Usage : 54.6 MB, less than 33.33 % of C++ online submissions for Distribute Candies.
	int distributeCandies(vector<int>& candies) {
		set<int> pool; // ��bitsetЧ�ʸ���, ��������+100000
		for (int i = 0; i < candies.size(); ++i)
		{
			pool.insert(candies[i]);
		}
		return min(candies.size() / 2, pool.size());
	}
};
#pragma endregion
