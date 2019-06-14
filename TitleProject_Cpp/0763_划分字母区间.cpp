
#pragma region 763_������ĸ����
/*
�ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ����ĸֻ����������е�һ��Ƭ�Ρ�����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�
ʾ�� 1:
����: S = "ababcbacadefegdehijhklij"
���: [9,7,8]
����:
���ֽ��Ϊ "ababcbaca", "defegde", "hijhklij"��
ÿ����ĸ��������һ��Ƭ���С�
�� "ababcbacadefegde", "hijhklij" �Ļ����Ǵ���ģ���Ϊ���ֵ�Ƭ�������١�
ע��:
S�ĳ�����[1, 500]֮�䡣
Sֻ����Сд��ĸ'a'��'z'��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/partition-labels
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	// 4ms(97.39%), 8.6MB(81.72%)
	vector<int> partitionLabels(string S) {
		vector<int> res;
		int maxArray[26] = { 0 };

		for (auto i = 0; i < S.size(); i++)
			maxArray[S[i] - 'a'] = i;

		int left = 0;
		while (left < S.length())
		{
			int init = left;
			int right = maxArray[S[left] - 'a'];
			while (left < right)
			{
				left++;
				if (right < maxArray[S[left] - 'a'])
				{
					// �����ұ߽�
					right = maxArray[S[left] - 'a'];
				}
			}
			res.push_back(++left - init);
		}
		return res;
	}
};
#pragma endregion
