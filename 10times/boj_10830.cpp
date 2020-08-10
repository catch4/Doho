/*
	[����] 10830 ��� ����
		���� ��ó : https://www.acmicpc.net/problem/10830

	[Ǯ�� ���] ���
		1. squar number�� Ȧ���� A�� ���Ѵ�.
		2. ¦���� ������ ���ش�.

	[���� ����]
		1. B��ŭ ������ ���鼭 �ϳ��ϳ� ��� : �ð��ʰ�
			-> 4������ (2+2)
		2. ��Ÿ�� ���� 5*5 �迭�� 100,000,000,000 ũ�⸸ŭ �����ϸ� �޸� ����.
	[Ǯ�� ����] 2020.08.04

���� :  https://matrixcalc.org/ko/#%7B%7B1,2%7D,%7B3,4%7D%7D%5E6
*/

#include <iostream>
#include <vector>

long long N, B;

std::vector<std::vector<int>> power(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b) {
	std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				result[i][j] += (a[i][k] * b[k][j]);
				result[i][j] %= 1000;
			}
		}
	}
	return result;
}

std::vector<std::vector<int>> dfs(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &v, long long square) {
	if (square == 1) return v;
	std::vector<std::vector<int>> temp(N, std::vector<int>(N, 0));
	if (square % 2 == 0) {
		temp = dfs(a, v, square / 2);
		return power(temp, temp);
	}
	temp = dfs(a, v, square - 1);
	return power(temp, a);
}
int main()
{
	std::cin >> N >> B;
	std::vector<std::vector<int>> input(N,std::vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> input[i][j];

	std::vector<std::vector<int>> answer = input;
	
	answer = dfs(answer, input, B);

	for (const auto& i : answer)
	{
		for (const auto j : i)
			std::cout << j % 1000<< ' ';
		std::cout << '\n';
	}
	return 0;
}