#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;

using namespace std;

#pragma region 412_Fizz Buzz
/*
дһ����������� 1 �� n ���ֵ��ַ�����ʾ��
1. ��� n ��3�ı����������Fizz����
2. ��� n ��5�ı����������Buzz����
3.��� n ͬʱ��3��5�ı�������� ��FizzBuzz����
ʾ����
n = 15,
����:
[
	"1",
	"2",
	"Fizz",
	"4",
	"Buzz",
	"Fizz",
	"7",
	"8",
	"Fizz",
	"Buzz",
	"11",
	"Fizz",
	"13",
	"14",
	"FizzBuzz"
]
*/
// 28ms(����1%), 10.3MB
class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> result;

		for (int i = 1; i <= n; i++)
		{
			if (i % 15 == 0)
			{
				result.push_back("FizzBuzz");
			}
			else if (i % 5 == 0)
			{
				result.push_back("Buzz");
			}
			else if (i % 3 == 0)
			{
				result.push_back("Fizz");
			}
			else
			{
				result.push_back(to_string(i));
			}
		}
		return result;
	}
};

#pragma endregion