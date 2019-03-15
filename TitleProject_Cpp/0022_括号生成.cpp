#include "pch.h";
#include <iostream>;
#include <vector>;
#include <string>;
#include <stack>;
#include <queue>;

using namespace std;

#pragma region 22_��������
/*
���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�

���磬���� n = 3�����ɽ��Ϊ��

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
// 44ms, 24.6MB, ����������
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n == 0)
		{
			return result;
		}
		stack<string> leftBrackets;
		leftBrackets.push("(");
		AddBrackets(n, 1, "(", leftBrackets, result);
		return result;
	}

	void AddBrackets(int n, int count, string s, stack<string> left, vector<string>& result) {
		if (left.empty() && count != n)
		{
			// ջ��û�� (, ��ʱֻ�ܼ� ( 
			left.push("(");
			AddBrackets(n, count + 1, s + "(", left, result);
		}
		else
		{
			if (count == n)
			{
				for (size_t i = 0; i < left.size(); i++)
				{
					s += ")";
				}
				result.push_back(s);
			}
			else
			{
				// ���Լ� (
				left.push("(");
				AddBrackets(n, count + 1, s + "(", left, result);
				left.pop();

				// Ҳ���Լ� )
				left.pop();
				AddBrackets(n, count, s + ")", left, result);
			}
		}
	}
};
#pragma endregion