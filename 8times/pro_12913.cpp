/*
	[PRO] 땅따먹기
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12913

	[풀이 방법] DP?
		1. 첫행을 제외한 2번째 행부터 누적합의 최댓값을 구한다.
			- {1, 2, 3, 5}, {5, 6, 7, 8} 일 때 2번째의 0번 누적합은 {7, 8, 9} 가 된다. 이 중 최댓값을 새로운 배열(newLand[1][0])에 저장해준다.

	[실패 과정]
		1. DFS를 이용해 모든 경우를 체크하는 방법은 효율성 이전에 정확성에서 시간초과가 뜬다.
		2. BFS를 이용한 다익스트라 알고리즘처럼 접근했다. -> 효율성 테스트 시간초과 
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


//-----------------DFS----------------------------------	// 정확성 부분 시간 초과

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


//----------------BFS----------------------------------	// 효율성 부분 시간 초과

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