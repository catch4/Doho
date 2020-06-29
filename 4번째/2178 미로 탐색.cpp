/*
	[����] 2178. �̷� Ž��
		���� ��ũ : https://www.acmicpc.net/problem/2178
		Ǯ�� : 2020.06.23

	[Ǯ�� ���]	-	BFS�� �̿��� �׷��� �˰��� (�ִ� �Ÿ� ���ϱ�)
	
	[����]
		2��°���� �Է°��� String�� �޾ƾ� �Ѵ�.
		8����Ʈ ��ȣ���� ���� �ڷ����� �ִ� 20�ڸ��������� ǥ���� �� �ִ�.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

int N, M;
std::vector<std::pair<int, int>> direction { {-1,0},{1,0},{0,-1},{0,1} };

class node
{
public:
	int cost = 0;
	int y = 0;
	int x = 0;

public:
	node(int cost, int y, int x) : cost(cost), y(y), x(x) {}
};

class cmp
{
public:
	bool operator() (const node& a, const node& b)
	{
		return a.cost > b.cost;
	}
};

bool checkPosition(const int y, const int x) 
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return false;
	return true;
}

int bfs(const std::vector<std::vector<int>>& labyrinth)
{
	std::priority_queue<node,std::vector<node>,cmp> queue;
	std::vector<std::vector<bool>> isUsed(N, std::vector<bool>(M, false));

	queue.push({ labyrinth[0][0],0,0 });

	while (!queue.empty())
	{
		auto top = queue.top();
		queue.pop();

		if (top.y == N - 1 && top.x == M - 1)
			return top.cost;

		for (const auto& i : direction)
		{
			const int destY = top.y + i.first;
			const int destX = top.x + i.second;

			if (checkPosition(destY,destX) && labyrinth[destY][destX] == 1 && isUsed[destY][destX] == false)
			{
				isUsed[destY][destX] = true;
				queue.push({ top.cost + 1,destY,destX });
			}
		}
	}
	// �׻� ������ġ�� �̵��� �� �ִ� ��츸 ���̽��� �־���
}

int main()
{
	std::cin >> N >> M;

	std::vector<std::vector<int>> labyrinth(N,std::vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		std::string number;
		std::cin >> number;
		for (int j = 0; j < M; j++)
			labyrinth[i][j] = number[j]-'0';
	}

	std::cout << bfs(labyrinth);
	return 0;
}
