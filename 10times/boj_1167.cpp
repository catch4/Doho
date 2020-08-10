/*
	[����] 1167 Ʈ���� ����
		���� ��ó : https://www.acmicpc.net/problem/1167

	[Ǯ�� ���] ���� (BFS)
		1. ������ ������ ����� ���� ����� ū ���� ��ǥ�� ���Ѵ�.
			- ��� ��ǥ�� ��������� �غ��� �ð��� �ʰ��ȴ�. �׷��� ������ ������ ���� ����� ū ���� ã�µ�,
			�� ������ �Ÿ� ����ġ�� ���� �͵��� ���� ���� ���� ����� ū ���� �Ǳ� �����̴�.
		2. �� ��ǥ�� ���������� ���� ����� ū ���� �������� �Ѵ�.

	[���� ����]
		1. �÷��̵� �ͼ��� ��µ� �迭�� ũ�Ⱑ �ִ� 100000 * 100000�� ���� �������� �ʾƼ� �޸� �ʰ��� ����... �ٺ� 
		2. ���ͽ�Ʈ�� (BFS) : �ð��ʰ�
			- �������� 0~N-1���� ��� �ϸ� N*N���� �ð��ʰ� 

	[Ǯ�� ����] 2020.08.08

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, pathCount;

struct node {
	int dest;
	int cost;

	bool operator < (const node& comapred) const { return this->cost > comapred.cost; }
};

std::pair<int,int> bfs(const std::vector<std::vector<node>>& paths, const int startIndex)
{
	int answer = 0, index = startIndex;
	int count = pathCount;

	std::priority_queue<node> queue;
	std::vector<int> costs(N, 1000000001);
	queue.push({ startIndex,0 });
	costs[startIndex] = 0;
	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();
		if (count == 0)
			break;
		for (const auto& i : paths[top.dest])
		{
			int newCost = top.cost + i.cost;
			if (costs[i.dest] < newCost) continue;
			costs[i.dest] = newCost;
			queue.push({ i.dest,newCost });
			if (answer < newCost)
			{
				answer = newCost;
				index = i.dest;
			}
			count--;
		}
	}

	return{ answer,index };
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N;

	std::vector<std::vector<node>> paths(N, std::vector<node>());
	for (int i = 0; i < N; i++)
	{
		int index;
		std::cin >> index;
		index  -= 1;

		while (true)
		{
			int dest, cost;
			std::cin >> dest;
			if (dest == -1)break;
			std::cin >> cost;
			pathCount++;
			paths[index].push_back({ dest - 1, cost });
		}
	}

	std::pair<int, int> retval = bfs(paths, 0);
	auto answer = bfs(paths, retval.second);
	

	std::cout << answer.first;
	return 0;
}