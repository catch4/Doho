/*
	[����] 6209 ���ڸ� �ָ��ٱ�
		���� ��ó : https://www.acmicpc.net/problem/6209

	[Ǯ�� ���] �̺� Ž��
		- ������ ��ġ ������ ���� �����̴�.

	[Ǯ�� ����] 2020.07.18
*/

#include <iostream>
#include <vector>
#include <algorithm>

int D, N, M;

bool isPossible(const std::vector<int>& distance, int range)
{
	int source = 0, dest = 1, count = 0;
	for (; dest <= N & count <= M; dest++)
	{
		if (distance[dest] - distance[source] < range)
			count++;
		else
			source = dest;
	}
	if (count > M) return false;
	return true;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> D >> N >> M;

	std::vector<int> distance(N+1);
	for (int i = 1; i <= N; i++)
		std::cin >> distance[i];

	std::sort(distance.begin(), distance.end());

	int min = 0, max = D, mid = 0;
	int answer = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (isPossible(distance, mid))
		{
			min = mid + 1;
			answer = mid;
		}
		else
			max = mid - 1;
	}
	std::cout << answer;
	return 0;
}