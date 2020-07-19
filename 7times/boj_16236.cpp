/*
	[����] 16236  �Ʊ���
		���� ��ó : https://www.acmicpc.net/problem/16236

	[Ǯ�� ���] : BFS
		1. ���� �Ʊ� ��� ��ġ���� ���� �� �ִ� �������� �ִܰŸ��� BFS ����� �̿��� ���Ѵ�.
			- ���� �� �ִ� ������� �Ÿ�, ��ǥ�� �켱���� ť�� �־��ش�.
			- �켱���� ť�� ����� ��� : ���� �� �ִ°� ���� / �켱���� ť�� !empty()�� ��� : top() ����

	[����]
		1. ��Ÿ�� ����
			- ���� �� �ִ� �������� �Ÿ��� ���� ����� ���� BFS�� �Ÿ��� ����Ͽ� BFS �۾��� ������ ���� �����̾���.
				: ��ü �������� ���� �� �ִ� �������� ��� ã�� ���� ����� ���� �ִ� ��ü�� �����ϴ� ������ ����.

	[Ǯ�� ����] : 2020.07.17
*/

#include <iostream>
#include <deque>
#include <queue>

class position {
public:
	int y = 0;
	int x = 0;
public:
	void addPos(int y, int x) { this->y += y; this->x += x;}
	position() {}
	position(int y, int x) : y(y), x(x) {}
};

position sharkPos;
int N;
int answer, nowSize, eatCount;

std::pair<int, int> dir[]{ {-1,0},{1,0},{0,-1},{0,1} };

struct cmp {
	bool operator() (const std::pair<int, position>& a, const std::pair<int, position>& b) {
		if (a.first == b.first)
		{
			if (a.second.y == b.second.y)
				return a.second.x > b.second.x;
			return a.second.y > b.second.y;
		}
		return a.first > b.first;
	}
};

bool isMove(const position& pos)
{
	if (pos.y >= 0 && pos.y < N && pos.x >= 0 && pos.x < N)
		return true;
	return false;
}

std::pair<int, position> BFS(const std::deque<std::deque<int>>& space)
{
	std::deque<std::deque<bool>> isUsed(N, std::deque<bool>(N, false));
	std::priority_queue<std::pair<int, position>, std::vector<std::pair<int, position>>, cmp> fish;
	std::priority_queue<std::pair<int, position>, std::vector<std::pair<int, position>>, cmp> q;

	q.push({ 0,sharkPos });
	isUsed[sharkPos.y][sharkPos.x] = true;

	while (!q.empty())
	{
		auto top = q.top();
		q.pop();

		int newCost = top.first + 1;
		for (int i = 0; i < 4; i++)
		{
			position newPos = top.second;
			newPos.addPos(dir[i].first, dir[i].second);
			if (isMove(newPos) && !isUsed[newPos.y][newPos.x] && space[newPos.y][newPos.x] <= nowSize)
			{
				if (space[newPos.y][newPos.x] < nowSize && space[newPos.y][newPos.x] != 0)
					fish.push({ newCost,newPos });

				q.push({ newCost, newPos });
				isUsed[newPos.y][newPos.x] = true;
			}

		}
	}

	if (fish.empty())
		return{ 0,{-1,-1} };
	else
		return fish.top();
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N;

	std::deque<std::deque<int>> space(N, std::deque<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> space[i][j];
			if (space[i][j] != 0)
			{
				if (space[i][j] == 9)
				{
					sharkPos = { i,j };
					space[i][j] = 0;
				}
			}
		}
	}

	answer = 0, nowSize = 2, eatCount = 0;

	while (true)
	{
		std::pair<int,position> retVal = BFS(space);

		if (retVal.second.y == -1 && retVal.second.x	== -1)
			break;

		answer += retVal.first;

		sharkPos = retVal.second;
		space[sharkPos.y][sharkPos.x] = 0;
		eatCount++;
		if (eatCount == nowSize)
		{
			eatCount = 0;
			nowSize++;
		}
	}
	std::cout << answer;
	return 0;
}
