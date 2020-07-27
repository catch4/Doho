/*
	[����] 2252 �� �����
		���� ��ó : https://www.acmicpc.net/problem/2252

	[Ǯ�� ���] �������� (BFS)
		1. A�� B�� �տ� �;��ϴ� ������ B�� ���� ������ �߰��Ǵ� �� �̴�.
		2. ���� ������ 0�� �͵��� ť�� �ִ´�.
		3. ť���� �ε����� �̾� �� �ε����� ��� ������ �������ش�. (�������� ���� ���� --)

	[���� ����]

	[Ǯ�� ����] 2020.07.27
*/

#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> inDegreeCount(N, 0);
	std::vector<std::vector<int>> paths(N, std::vector<int>());

	for (int i = 0; i < M; i++)
	{
		int A, B;
		std::cin >> A >> B;
		inDegreeCount[--B]++;
		paths[--A].push_back(B);
	}

	std::queue<int> queue;
	for (int i = 0; i < N; i++)
	{
		if (!inDegreeCount[i])
			queue.push(i);
	}
	
	while (!queue.empty())
	{
		int nowIndex = queue.front();
		std::cout << (nowIndex+1) << ' ';
		queue.pop();

		for (const auto i : paths[nowIndex])
		{
			inDegreeCount[i]--;
			if (!inDegreeCount[i])
				queue.push(i);
		}
	}

	return 0;
}