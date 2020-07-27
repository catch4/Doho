/*
	[PRO] 경주로 건설
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/67259

	[풀이 방법] BFS


	[풀이 일자] - 테스트 케이스 14 실패.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> directionPosition[]{ {-1,0},{1,0},{0,-1},{0,1} };
enum direction { NONE = 0,UP,DOWN,LEFT,RIGHT};
const int INF = 2147483647;

class node {
public:
	int cost;
	int x, y;
	direction dir;
public:
	node() {}
	node(int y, int x) : y(y), x(x), cost(0),dir(direction::NONE) {}
	node(int cost, int y, int x, direction dir) : cost(cost),y(y),x(x),dir(dir) {}
	bool operator<(const node& compare) const { return this->cost > compare.cost; }
};

bool checkCorner(const direction sourceDirection, const direction destDirection)
{
	if (sourceDirection == direction::UP || sourceDirection == direction::DOWN)
	{
		if (destDirection == direction::LEFT || destDirection == direction::RIGHT)
			return true;
		else
			return false;
	}
	else if (sourceDirection == direction::LEFT || sourceDirection == direction::RIGHT)
	{
		if (destDirection == direction::UP || destDirection == direction::DOWN)
			return true;
		else
			return false;
	}
	else
		return false;
}

int solution(vector<vector<int>> board) {
	int N = board.size();
	pair<int, int> destPosition{ N - 1,N - 1 }, sourcePosition {0,0};

	vector<vector<int>> costs(N, vector<int>(N, INF));
	priority_queue<node> queue;
	queue.push(node(0,0, 0,direction::NONE));
	costs[0][0] = 0;

	while (!queue.empty())
	{
		node topNode = queue.top();
		queue.pop();

		if (topNode.y == destPosition.first && topNode.x == destPosition.second)
			break;

		for (int i = 0; i < 4; i++)
		{
			int newY = topNode.y + directionPosition[i].first;
			int newX = topNode.x + directionPosition[i].second;
			int newCost = topNode.cost;
			newCost += 100;
			if (checkCorner(topNode.dir, static_cast<direction>(i + 1)))
				newCost += 500;

			if (newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
			if (board[newY][newX]) continue;
			if (costs[newY][newX] < newCost) continue;

			queue.push(node(newCost, newY, newX, static_cast<direction>(i + 1)));
			costs[newY][newX] = newCost;
		}
	}
	return costs[N - 1][N - 1];
}

int main()
{
	//cout << solution({ {0,0,0},{0,0,0},{0,0,0} });
	cout << solution({ {0, 0, 0, 0, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0, 0, 1 },{ 0, 0, 1, 0, 0, 0, 1, 0 },{ 0, 1, 0, 0, 0, 1, 0, 0 },{ 1, 0, 0, 0, 0, 0, 0, 0 } });
}