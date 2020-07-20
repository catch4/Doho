/*
	[PRO] �����Ա�
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/12913

	[Ǯ�� ���] DP?
		1. ù���� ������ 2��° ����� �������� �ִ��� ���Ѵ�.
			- {1, 2, 3, 5}, {5, 6, 7, 8} �� �� 2��°�� 0�� �������� {7, 8, 9} �� �ȴ�. �� �� �ִ��� ���ο� �迭(newLand[1][0])�� �������ش�.

	[���� ����]
		1. DFS�� �̿��� ��� ��츦 üũ�ϴ� ����� ȿ���� ������ ��Ȯ������ �ð��ʰ��� ���.
		2. BFS�� �̿��� ���ͽ�Ʈ�� �˰���ó�� �����ߴ�. -> ȿ���� �׽�Ʈ �ð��ʰ� 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
	vector<vector<int>> newLand(land.size(), vector<int>(4, 0));
	for (int i = 0; i < 4; i++)
		newLand[0][i] = land[0][i];

	for (int i = 1; i < land.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (j == k) continue;
				newLand[i][j] = max(newLand[i][j], (newLand[i - 1][k] + land[i][j]));
			}
		}
	}

	return *max_element(newLand.back().begin(), newLand.back().end());
}


//-----------------DFS----------------------------------	// ��Ȯ�� �κ� �ð� �ʰ�

int dfs(const vector<vector<int>>&  land, int level, int prevIndex, int sum)
{
	if (level >= land.size())
		return sum;

	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		if (prevIndex == i) continue;
		ret = max(dfs(land, level + 1, i, sum + land[level][i]),ret);
	}
	return ret;
}

int solution(vector<vector<int> > land)
{
	int answer = 0;

	for (int i = 0; i < 4; i++)
		answer = max(dfs(land,1,i,land[0][i]), answer);

	return answer;
}


//----------------BFS----------------------------------	// ȿ���� �κ� �ð� �ʰ�

#include <queue>
struct node {
	int cost;
	int y, x;

	bool operator < (const node& a) const
	{
		return cost < a.cost;
	}

};

int solution(vector<vector<int> > land)
{
	priority_queue<node> queue;
	vector<vector<int>> isUsed(land.size(), vector<int>(4, 0));
	for (int i = 0; i < 4; i++)
		queue.push({ land[0][i],0,i });

	while (!queue.empty())
	{
		int nowCost = queue.top().cost;
		int nowY = queue.top().y;
		int nowX = queue.top().x;

		queue.pop();

		if (nowY == land.size() - 1) continue;
		for (int i = 0; i < 4; i++)
		{
			if (nowX == i) continue;
			int newCost = nowCost + land[nowY + 1][i];
			if (newCost <= isUsed[nowY + 1][i]) continue;
			isUsed[nowY + 1][i] = newCost;
			queue.push({ newCost,nowY + 1,i });
		}
	}

	return *max_element(isUsed.back().begin(), isUsed.back().end());
}

int main()
{
	cout << solution({ {1,2,3,5},{5,6,7,8},{4,3,2,1} });

	return 0;
}