/*
	[����] 2151 �ſ� ��ġ
		���� ��ó : 

	[Ǯ�� ���]  BFS

	[���� ����]
		1. �Է����� ���� ���� ���� 2���� �迭 isUsed�� �����ϰ� �ּ� ��ġ �ſ��� ���� �����ߴ�.
			- �� ���⿡ ���� �پ��� ����� �� ����
			-> isUsed�� 3���� �迭�� �����ϰ� �� ���⿡ ���ؼ� �ּڰ��� �Է�.

	[Ǯ�� ����] 2020.07.18
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N;
int answer = 214748367;
std::pair<int, int> source{ -1,-1 }, dest{ -1,-1 };
std::pair<int, int> dir[]{ {-1,0},{1,0},{0,-1},{0,1} };


class position {
public:
	int y = -1;
	int x = -1;
	int dir = -1;
public:
	position() {}
	position(int y, int x, int dir) : y(y), x(x), dir(dir) {}
};

struct cmp {
	bool operator() (const std::pair<int, position>& a, const std::pair<int, position>& b)
	{
		return a.first > b.first;
	}
};

std::pair<int, int> Move(const std::vector<std::vector<char>>& map, const std::pair<int, int>& source, int direction)
{
	std::pair<int, int> temp = source;
	while (true)
	{
		temp.first += dir[direction].first;
		temp.second += dir[direction].second;
		if (temp.first < 0 || temp.first >= N  || temp.second < 0 || temp.second >= N )
			break;
		else if (map[temp.first][temp.second] == '*')
			break;
		else if (map[temp.first][temp.second] == '!' || map[temp.first][temp.second] == '#')
			return temp;
	}
	return{ -1,-1 };
}

int checkDir(const int nowDirection)
{
	int tempDirection = nowDirection;
	if (tempDirection < 2)
	{
		tempDirection++;
		return (tempDirection % 2);
	}
	else
	{
		tempDirection++;
		return ((tempDirection % 2) + 2);
	}
}

void BFS(const std::vector<std::vector<char>>& map, std::vector<std::vector<std::vector<int>>>& isUsed)
{
	std::priority_queue<std::pair<int, position>,std::vector<std::pair<int,position>>,cmp> q;

	for (int i = 0; i < 4; i++)
	{
		q.push({ 0, { source.first,source.second, i} });
		isUsed[source.first][source.second][i] = 0;
	}

	while (!q.empty())
	{
		auto front = q.top();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (i == checkDir(front.second.dir)) continue;
			auto retVal = Move(map, { front.second.y,front.second.x }, i);
			if (retVal.first == -1 || retVal.second == -1) continue;
			int newCount = front.first;
			if (i != front.second.dir)
				newCount++;
			if (isUsed[retVal.first][retVal.second][i] <= newCount) continue;
			q.push({ newCount,{ retVal.first,retVal.second,i } });
			isUsed[retVal.first][retVal.second][i] = newCount;
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N;

	std::vector<std::vector<char>> map (N,std::vector<char>(N));
	std::vector<std::vector<std::vector<int>>> isUsed(N, std::vector<std::vector<int>>(N, std::vector<int>(4, 214748367)));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] == '#')
			{
				if (source.first == -1)
				{
					source.first = i;
					source.second = j;
				}
				else
				{
					dest.first = i;
					dest.second = j;
				}
			}
		}
	}

	BFS(map,isUsed);

	auto& vec = isUsed[dest.first][dest.second];
	int min = vec.front();
	for (const auto& i : vec)
		min = std::min(min, i);
	
	std::cout << min;
	return 0;
}