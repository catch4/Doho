/*
	[����] 1937 ������� �Ǵ� 
		���� ��ó : https://www.acmicpc.net/problem/1937

	[Ǯ�� ���] : DP & DFS
		1. DP�� 0���� �ʱ�ȭ �Ѵ�.
		2. ���� DP[x][y]�� 0�� �ƴϸ� ���Ž���� ����̴�. �ٷ� �������ش�.
		2-1. 0�̸� �����¿� �����̸鼭 ���Ž���� �Ѵ�.
			-> DFS�� �̿��ϴ� ������ Ž���ϴ� ��ġ�� �ִ��� ���� ���� �� ��ġ�� �����ϱ� ����! (���)


	[���� ����]
		1. BFS�� �̿��� �� ��ġ���� �ִ� ������ ���� ���ߴ�. -> �ð��ʰ�.
		2. DP & �޸������̼��� ����ߴ�. -> �ð��ʰ�
			-> BFS�� �ƴ϶� DFS�� ����

	[Ǯ�� ����] 2020.07.18
*/

#include <iostream>
#include <vector>
#include <algorithm>

const int SIZE = 500;
int N, answer;
std::pair<int, int> dir[]{ {-1,0},{1,0},{0,-1},{0,1} };

int map[SIZE][SIZE];
int path[SIZE][SIZE];

int DFS(std::pair<int,int> source)
{
	if (path[source.first][source.second] != 0)
		return path[source.first][source.second];

	path[source.first][source.second] = 1;

	for (int i = 0; i < 4; i++)
	{
		std::pair<int, int> newPos = source;
		newPos.first += dir[i].first;
		newPos.second += dir[i].second;

		if (newPos.first < 0 || newPos.first >= N || newPos.second < 0 || newPos.second >= N) continue;
		if (map[source.first][source.second] < map[newPos.first][newPos.second])
			path[source.first][source.second] = std::max(path[source.first][source.second], DFS(newPos)+1);
	}
	return path[source.first][source.second];
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> map[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			answer = std::max(answer, DFS({ i,j }));
	}
	std::cout << answer;
	return 0;
}