/*
	[����] 16398 �༺ ����
		���� ��ó : https://www.acmicpc.net/problem/16398
		Ǯ�� ���� : 2020.07.02

	[Ǯ�� ���] : �ּ� ���� Ʈ�� (���� �˰���)
		1. ���� �˰����� �̿��� ���� ����� ���� ��� �� ����ġ�� ���� ������ �����Ѵ�.
		2. isUsed�� ����� �̹� �湮�� ���� ��湮 ���� �ʴ´�.
*/

#include <iostream>
#include <vector>
#include <queue>

struct node {
	int cost;
	int index;
};

struct cmp
{
	bool operator()(const node& a, const node& b)
	{
		return a.cost > b.cost;
	}
};

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::vector<std::pair<int, int>>> graph(N, std::vector<std::pair<int, int>>(N));
	std::vector<bool> isUsed(N, false);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			std::cin >> temp;
			graph[i][j] = { temp,j };
		}
	}

	std::priority_queue<node, std::vector<node>, cmp> queue;
	queue.push({ 0,0});
	int answer = 0;
	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();
		const int cost = top.cost;
		const int index = top.index;

		if (isUsed[index]) continue;
		isUsed[index] = true;
		answer +=cost;
		for (const auto& i : graph[index])
		{
			if (isUsed[i.second]) continue;
			if (i.first == 0) continue;
			queue.push({ i.first,i.second });

		}
	}
	std::cout << answer;
	return 0;
}