/*
	[����] 16234 �α� �̵�
		���� ��ó : https://www.acmicpc.net/problem/16234
		Ǯ�� ���� : 2020.07.02.

	[Ǯ�� ���] Disjoint set
		1. bfs�� �̿��� ������ ĭ(�����¿�)�� ���� �������� üũ�Ѵ�.
		2. üũ ��� ���� �����ϴٸ� ť�� �ִ´�. �̶� isUsed�� �̿��� �湮�� ������ üũ�Ѵ�.
		2-1. bfs while���� ���� ���� ť�� �߰��� ������ ���� �������� �з��Ѵ�.
		2-2. ��� ������ �湮�� �� ���� bfs�� �ݺ��Ѵ�. �̶� ������ �̷�� ��Ұ� ���� ��� �ݺ��� �����Ѵ�.
		3. ���� �������� �з��� �������� �α��� ����� ���ϰ� �����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <queue>

int N, L, R;
std::vector<std::pair<int, int>> direction{ {-1,0},{1,0},{0,-1},{0,1} };

bool checkPosition(const std::vector<std::vector<int>>& population, const int sourceY, const int sourceX, const int destY, const int destX)
{
	if (sourceY < 0 || sourceY >= N || sourceX < 0 || sourceX >= N) return false;
	if (destY < 0 || destY >= N || destX < 0 || destX >= N) return false;

	int diff = abs(population[sourceY][sourceX] - population[destY][destX]);
	if (diff >= L && diff <= R)
		return true;
	return false;
}


int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N >> L >> R;

	std::vector<std::vector<int>> population(N, std::vector<int>(N));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> population[i][j];
	}

	int answer = 0;
	while (true)
	{
		std::vector<std::vector<bool>> isUsed(N, std::vector<bool>(N, false));
		std::vector<std::vector<int*>> group;
		std::queue<std::pair<int, int>> queue;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isUsed[i][j]) continue;

				queue.push({ i,j });
				isUsed[i][j] = true;
				std::vector<int*> subGroup;
				while (!queue.empty())
				{
					auto front = queue.front();
					queue.pop();

					for (const auto& k : direction)
					{
						int newY = front.first + k.first;
						int newX = front.second + k.second;

						if (!checkPosition(population, front.first, front.second, newY, newX) || isUsed[newY][newX])	continue;	// 1�� : ���� ���� ���ɿ��� üũ
						// 2�� : ���տ� �߰�
						isUsed[newY][newX] = true;
						queue.push({ newY,newX });
						subGroup.push_back(&population[newY][newX]);
					}
				}
				if (subGroup.empty()) continue;
				subGroup.push_back(&population[i][j]);
				group.push_back(subGroup);
			}
		}
		
		if (group.empty())
			break;

		for (auto& i : group)
		{
			if (i.empty()) continue;
			int sum = 0;
			int count = i.size();
			for (auto& j : i)
				sum += *j;
			sum /= count;

			for (auto& j : i)
				*j = sum;
		}
		answer++;
	}

	std::cout << answer;
	return 0;
}
