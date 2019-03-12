#pragma region 509_쳲�������
/*
	쳲���������ͨ���� F(n) ��ʾ���γɵ����г�Ϊ쳲��������С��������� 0 �� 1 ��ʼ�������ÿһ�����ֶ���ǰ���������ֵĺ͡�Ҳ���ǣ�
	F(0) = 0,   F(1) = 1
	F(N) = F(N - 1) + F(N - 2), ���� N > 1.
	���� N������ F(N)��
	ʾ�� 1��
	���룺2
	�����1
	���ͣ�F(2) = F(1) + F(0) = 1 + 0 = 1.
	ʾ�� 2��
	���룺3
	�����2
	���ͣ�F(3) = F(2) + F(1) = 1 + 1 = 2.
	ʾ�� 3��
	���룺4
	�����3
	���ͣ�F(4) = F(3) + F(2) = 2 + 1 = 3.
	��ʾ��
	0 �� N �� 30
*/
// 48ms, 8.4MB �������� - �ݹ�̫����
int fib(int N) {
	if (N == 1)
	{
		return 1;
	}
	else if (N == 0)
	{
		return 0;
	}

	return fib(N - 1) + fib(N - 2);
}

// ���� - 8ms(43%), 8.2MB
int fib2(int N) {
	if (N == 1 || N == 2)
	{
		return 1;
	}
	else if (N == 0)
	{
		return 0;
	}

	int x = 0;
	int y = 1;
	int z = 0;
	int count = 2;
	while (count <= N)
	{
		z = x + y;
		x = y;
		y = z;
		count++;
	}
	return z;
}

#pragma endregion