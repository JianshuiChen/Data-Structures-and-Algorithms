#include "pch.h";
#include <iostream>;
#include <vector>;

using namespace std;

#pragma region 413_�Ȳ����л���
/*
���һ����������������Ԫ�أ�����������������Ԫ��֮����ͬ����Ƹ�����Ϊ�Ȳ����С�
���磬��������Ϊ�Ȳ�����:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
�������в��ǵȲ����С�
1, 1, 2, 5, 7
���� A ���� N ��������������0��ʼ������ A ��һ�������黮��Ϊ���� (P, Q)��P �� Q ������������ 0<=P<Q<N ��
��������������������������(P, Q)Ϊ�Ȳ����飺
Ԫ�� A[P], A[p + 1], ..., A[Q - 1], A[Q] �ǵȲ�ġ����� P + 1 < Q ��
����Ҫ�������� A ������Ϊ�Ȳ�����������������
ʾ��:
A = [1, 2, 3, 4]
����: 3, A ���������ӵȲ�����: [1, 2, 3], [2, 3, 4] �Լ����� [1, 2, 3, 4]��
*/
// ��̬�滮 
// 8ms, 8.6MB
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3)
		{
			return 0;
		}
		int dp = 0;
		int sum = 0;
		int sub = A[1] - A[0];
		for (int i = 2; i < A.size(); ++i) {
			int newSub = A[i] - A[i - 1];
			if (newSub == sub)
			{
				dp++;
				sum += (dp);
			}
			else
			{
				dp = 0;
			}
			sub = newSub;
		}
		return sum;
	}

public:
	int numberOfArithmeticSlices2(vector<int>& A) {
		int l = A.size();
		if (l == 0)
		{
			return 0;
		}
		int count = 0;
		for (size_t i = 0; i < l - 2; i++)
		{
			int sub = A[i + 1] - A[i];
			if (A[i + 2] - A[i + 1] == sub)
			{
				count++;
			}
			int num = 2;
			while (i + num < l - 1)
			{
				if (A[i + num + 1] - A[i + num] == sub)
				{
					count++;
					num++;
				}
			}
		}
		return count;
	}
};
#pragma endregion
