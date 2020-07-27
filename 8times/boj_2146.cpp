/*
	[����] 2146 �ٸ� �����
		���� ��ó : https://www.acmicpc.net/problem/2146

	[Ǯ�� ���] - DFS, BFS
		1. DFS�� �̿��� ��ǥ�� �� ���� �и��Ѵ�.
			- �����¿� ��ǥ �� 0�� �ִ� ��쿡�� set�� �ִ´�. ������ ��� Ž���� ������ ���� �����̴�.
		2. BFS�� �̿��� �ִܰŸ��� ���Ѵ�.

	[���� ����]
		1. ���� ������ 1�� ��� üũ.

	[Ǯ�� ����] 2020.07.24.
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

int N;
int answer = 2147483647;
std::pair<int, int> direction[]{ {-1,0},{1,0},{0,-1},{0,1} };

class node {
public:
	int cost, y, x;
public:
	node() {}
	node(int cost, int y, int x) : cost(cost), y(y), x(x) {}
	bool operator< (const node& b) const { return this->cost > b.cost; }
};

bool isArea(const std::vector<std::vector<int>>& map, std::pair<int, int> nowPos)
{
	for (int i = 0; i < 4; i++)
	{
		std::pair<int, int> newPos = nowPos;
		newPos.first += direction[i].first;
		newPos.second += direction[i].second;
		if (newPos.first < 0 || newPos.first >= N || newPos.second < 0 || newPos.second >= N) continue;
		if (map[newPos.first][newPos.second] == 0)
			return true;
	}
	return false;
}

void dfs(const std::vector<std::vector<int>>& map, std::vector<std::vector<bool>>& isUsed, std::set<std::pair<int,int>>& islands, std::pair<int, int> nowPos)
{
	if (isArea(map, nowPos))
		islands.insert(nowPos);

	for (int i = 0; i < 4; i++)
	{
		std::pair<int, int> newPos = nowPos;
		newPos.first += direction[i].first;
		newPos.second += direction[i].second;
		if (newPos.first >= 0 && newPos.first < N && newPos.second >= 0 && newPos.second < N)
		{
			if (map[newPos.first][newPos.second] == 1 && !isUsed[newPos.first][newPos.second])
			{
				isUsed[newPos.first][newPos.second] = true;
				dfs(map, isUsed, islands, newPos);
			}
		}
	}
}

int BFS(const std::vector<std::vector<int>>& map, const std::map<int, std::set<std::pair<int, int>>>& islands, const std::pair<int, int> startPos, const int islandCount)
{
	std::vector<std::vector<bool>> isUsed(N, std::vector<bool>(N, false));
	std::priority_queue<node> queue;
	queue.push({ 0,startPos.first,startPos.second });
	isUsed[startPos.first][startPos.second] = true;

	while (!queue.empty())
	{
		int nowCost = queue.top().cost;
		int nowY = queue.top().y;
		int nowX = queue.top().x;
		queue.pop();

		if (nowCost > answer) return nowCost;

		if (map[nowY][nowX] == 1)
		{
			for (const auto& i : islands)
			{
				if (i.first == islandCount) continue;
				if (i.second.find({ nowY,nowX }) != i.second.end())
					return nowCost - 1;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int newY = nowY + direction[i].first;
			int newX = nowX + direction[i].second;
			int newCost = nowCost + 1;
			if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
			if (isUsed[newY][newX]) continue;
			if (islands.at(islandCount).find({ newY,newX }) != islands.at(islandCount).end()) continue;
			isUsed[newY][newX] = true;
			queue.push({ newCost,newY,newX });
		}
	}
	return 2147483647;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N;

	std::vector<std::vector<int>> map(N,std::vector<int>(N));
	std::vector<std::vector<bool>> isUsed(N, std::vector<bool>(N,false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> map[i][j];
	}

	std::map<int,std::set<std::pair<int, int>>> islands;
	int islandCount = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0 || isUsed[i][j]) continue;
			dfs(map, isUsed, islands[islandCount],{ i,j });
			islandCount++;
		}
	}

	islandCount = 0;
	for (const auto& i : islands)
	{
		for (const auto& j : i.second)
		{
			answer = std::min(answer, BFS(map,islands,j, islandCount));
		}
		islandCount++;
	}

	std::cout << answer;

	return 0;
}
