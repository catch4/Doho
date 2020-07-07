/*
	[����]	2110	������ ��ġ
		���� ��ó : https://www.acmicpc.net/problem/2110

	[Ǯ�� ���] - �̺� Ž��
		1. ������ �̿��� ����� �� Ž���� N�� �ִ밡 200,000 �̶� �Ұ����ϴ�.
		2. �̺�Ž���� �̿��ϴµ�, Ž�� ���� ���� �ּ� ������ �� ������ ������ �Ÿ��� �Ѵ�.

*/

#include <iostream>
#include <vector>
#include <algorithm>

int checkDistance(const std::vector<int>& position, const int distance)
{
	int count = 1;
	int source = position.front();
	for (const auto& i : position)
	{
		if (i - source >= distance)
		{
			count++;
			source = i;
		}
	}
	return count;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, C;
	std::cin >> N >> C;

	std::vector<int> position(N);
	for (int i = 0; i < N; i++)
		std::cin >> position[i];

	std::sort(position.begin(), position.end());

	long long left = 1, right = position.back() - position.front(), mid = 0;
	long long answer = 0;
	while (left <= right)
	{
		mid = (left + right)/2;
		if (checkDistance(position, mid) < C)
			right = mid - 1;
		else
		{
			left = mid + 1;
			answer = mid;
		}
	}
	std::cout << answer;
}