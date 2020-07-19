/*
	[����] 16681 ���
		���� ��ó : https://www.acmicpc.net/problem/16681

	[Ǯ�� ���] ���ͽ�Ʈ��
		1. ���������� �� ��庰 �ִܰŸ��� ���Ѵ�. �̶� ���� ����� ���̰� �� ���ƾ��Ѵ�.
			- ������ ������ ������ ���������� ���� ���� ����ϸ� �ȴ�.

	[���� ����]
		1. 61%���� �޸��ʰ� ���� �߻�
			-> queue�� prioirty_queue�� ���� 
		2. �켱���� ť�� ���� �� �ð��ʰ� ���� �߻�
			-> ť���� ���� ����� ��ϵ� ��뺸�� ���� ��� �н�
		3. 76%���� Ʋ�Ƚ��ϴ�.
			-> int �ڷ����� long long���� ����.
	
	[Ǯ�� ����] 2020.07.19
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <climits>

long long N, M, D, E;

std::vector<int> heights;
std::vector<std::vector<std::pair<long long, long long>>> distance;
std::vector<std::vector<long long>> costs;

void dijkstra()
{
	for (int i = 0; i < 2; i++)
	{
		int source;
		if (i == 0)
			source = 0;
		else
			source = heights.size() - 1;


		std::priority_queue<std::pair<long long,int>,std::vector<std::pair<long long,int>>,std::greater<std::pair<int,int>>> queue;
		queue.push({ 0,source });
		costs[i][source] = 0;

		while (!queue.empty())
		{
			long long nowCost = queue.top().first;
			int nowPos = queue.top().second;
			queue.pop();

			if (nowCost > costs[i][nowPos]) continue;

			for (const auto& val : distance[nowPos])
			{
				long long nextCost = val.first + nowCost;
				int nextPos = val.second;
				if (heights[nowPos] >= heights[nextPos] || nextCost >= costs[i][nextPos]) 
					continue;
				queue.push({ nextCost,nextPos });
				costs[i][nextPos] = nextCost;
			}
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M >> D >> E;
	//	 N : ������ ����, M : ��� ����, D : ü�� �Ҹ�, E : ���밨 ȹ�淮
	
	heights.resize(N);
	for (int i = 0; i < N; i++)
		std::cin >> heights[i];

	distance.resize(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		a -= 1;
		b -= 1;
		distance[a].push_back( { c,b });
		distance[b].push_back({ c,a });
	}

	costs.resize(2);
	costs[0].resize(N,LLONG_MAX);
	costs[1].resize(N, LLONG_MAX);
	dijkstra();

	long long answer = LONG_MIN;
	for (int i = 1; i < N-1; i++)
	{
		if (costs[0][i] == LLONG_MAX || costs[1][i] == LLONG_MAX) continue;
		answer = std::max(answer, (long long)(heights[i] * E) - ((costs[0][i] + costs[1][i])*D));
	}

	if (answer == LONG_MIN)
		std::cout << "Impossible";
	else
		std::cout << answer;

	return 0;
}