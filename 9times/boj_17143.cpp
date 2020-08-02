/*
	[����] 17143 ���ÿ�
		���� ��ó : https://www.acmicpc.net/problem/17143

	[Ǯ�� ���] ����
		1. ���͸� �̿��� 2���� �迭�� �����߰�, vector ���δ� list�� ������� �ε����� �����Ѵ�.
		2. �� ĭ�� ����Ⱑ 2���� �̻��� ���� list.size() > 2�̴�.
		3. ����Ⱑ �̵��� �� ������ �̿��� (�̵��Ÿ� % ���İ��) �� ��ŭ�� �ݺ������� �̵�����.

	[���� ����]
		1. �ð��ʰ�
			- ��� �̵��� �ݺ������� 1ĭ�� ���������. ex) speed 8�̸� 8�� loop
				-> �� ���� ����� ��ġ �״�� ���� �̵��Ÿ��� (R-1)*2 & (C-1)*2 �̴�. �տ��� ���� ���� ������ ����� �ӵ��� ������ ������ �̿��ؼ� ���� �����ŭ�� �̵��ϰ� ������.

	[Ǯ�� ����] 2020.07.31
*/

#include <iostream>
#include <vector>
#include <list>

int R, C, M;

struct shark {
	int y;
	int x;
	int speed;
	int weight;
	int direction;
};

std::pair<int, int> direction[]{ {-1,0},{1,0},{0,1},{0,-1} };

int fishing(std::vector<std::vector<std::list<int>>>& board, const int fisherPosition)
{
	for (int i = 0; i < R; i++)
	{
		if (board[i][fisherPosition].size() != 0)
		{
			int retVal = board[i][fisherPosition].front();
			board[i][fisherPosition].clear();
			return retVal;
		}
	}
	return -1;
}

void sharkMove(std::vector<std::vector<std::list<int>>>& board, std::vector<shark>& sharkIndex)
{
	std::list<int> tempList;
	for (int i = 0; i < M; i++)
	{
		auto& node = sharkIndex[i];
		if (node.y == -1) continue;
		board[node.y][node.x].clear();

		int distance = 0;
		if (node.direction == 0 || node.direction == 1)
			distance = node.speed % ((R - 1) * 2);
		else
			distance = node.speed % ((C - 1) * 2);
		for (int move = 0; move < distance; move++)
		{
			node.y += direction[node.direction].first;
			node.x += direction[node.direction].second;
			if (node.direction == 0 || node.direction == 1)
			{
				if (node.y < 0 || node.y >= R)
				{
					node.direction = (node.direction == 1) ? 0 : 1;
					node.y += direction[node.direction].first * 2;
				}
			}
			else
			{
				if (node.x < 0 || node.x >= C)
				{
					node.direction = (node.direction == 3) ? 2 : 3;
					node.x += direction[node.direction].second * 2;
				}
			}
		}
		tempList.push_back(i);
	}

	for (const auto i : tempList)
		board[sharkIndex[i].y][sharkIndex[i].x].push_back(i);
}

void sharkEat(std::vector<std::vector<std::list<int>>>& board, std::vector<shark>& sharkIndex)
{
	for (auto& i : board)
	{
		for (auto& j : i)
		{
			if (j.size() > 1)
			{
				int maxIndex = j.front();
				for (auto& k : j)
				{
					if (k == j.front()) continue;
					if (sharkIndex[k].weight > sharkIndex[maxIndex].weight)
					{
						sharkIndex[maxIndex].y = -1;
						maxIndex = k;
					}
					else
						sharkIndex[k].y = -1;
				}
				j.clear();
				j.push_back(maxIndex);
			}
		}
	}
}

int main()
{
	// 1. input
	std::cin >> R >> C >> M;
	std::vector<std::vector<std::list<int>>> board(R, std::vector<std::list<int>>(C, std::list<int>()));
	std::vector<shark> sharkIndex(M);

	for (int i = 0; i < M; i++)
	{
		auto& temp = sharkIndex[i];
		std::cin >> temp.y >> temp.x >> temp.speed >> temp.direction >> temp.weight;
		temp.y -= 1;
		temp.x -= 1;
		temp.direction -= 1;
		board[temp.y][temp.x].push_back(i);
	}

	int fisherPosition = -1;
	int answer = 0;
	do {
		fisherPosition++;
		int fishIndexCaught = fishing(board,fisherPosition);
		if (fishIndexCaught != -1)
		{
			answer += sharkIndex[fishIndexCaught].weight;
			sharkIndex[fishIndexCaught].y = -1;
		}
		sharkMove(board, sharkIndex);
		sharkEat(board, sharkIndex);
	} while (fisherPosition < C - 1);

	std::cout << answer;
	return 0;
}