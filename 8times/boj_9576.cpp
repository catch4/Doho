/*
	[����] 9576 å �����ֱ�
		���� ��ó : https://www.acmicpc.net/problem/9576

	[Ǯ�� ���] �׸���
		1. B -> A ������ �������� ������ �Ѵ�.
			���� ��� ������ 1�� ��� (1 1, 3 3)�� 1 2, 3 4 ���� ���������� �ȴ�. �� ���ñ��� ���� ���� ���� ������ �����ش�.

	[Ǯ�� ����] 2020.07.27
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;
	while (T--)
	{
		int N, M;
		std::cin >> N >> M;

		std::vector<bool> books(N+1, false);
		std::vector<std::pair<int, int>> ranges(M);
		for (int i = 0; i < M; i++)
			std::cin >> ranges[i].first >> ranges[i].second;
		
		std::sort(ranges.begin(), ranges.end(), cmp);
		int answer = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = ranges[i].first; j <= ranges[i].second; j++)
			{
				if (!books[j])
				{
					answer++;
					books[j] = true;
					break;
				}
			}
		}
		std::cout << answer<<'\n';
	}

	return 0;
}