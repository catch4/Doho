/*
	[����] 1806 �κ���
		���� ��ó : https://www.acmicpc.net/problem/1806

	[Ǯ�� ���] : �� ������ (�����̵� ������)
		1. ���� �ε������� �κ����� S�� �����ϴ� ���̸� ã�´�.
		2. ���̸� ������ ��� ���� �ε����� ���̿��� �����Ѵ�.
		3. 1���� �ݺ��Ѵ�.

	[����]
		1. index 0���� N-1���� ��� ��� üũ -> �ð� �ʰ� 
			- ���� Ž�� : X
		2. sequence[0] �κ� üũ ����
		3. N�� ��� ����ϴ� ��� üũ (10 10 1 1 1 1 1 1 1 1 1 1) output : 10
	[Ǯ�� ����] : 2020.07.09.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, S;
	std::cin >> N >> S;

	std::vector<int> sequence(N);
	for (int i = 0; i < N; i++)
		std::cin >> sequence[i];

	int answer = 100000;
	int startIndex = 0, endIndex = 1, count = 1;
	int sum = sequence[0];
	while (endIndex <= N)
	{
		if (sum < S)
		{
			sum += sequence[endIndex++];
			count++;
		}
		else
		{
			answer = std::min(answer, count);
			sum -= sequence[startIndex++];
			count--;
		}
	}
	std::cout << ((answer != 100000) ? answer : 0);
	return 0;
}