#include <iostream>
#include <vector>
#include <queue>

int R, C;

char pipes[]{ '|','-','+','1','2','3','4' };
enum direction {UP=0,DOWN,LEFT,RIGHT};
std::pair<int, int> movePosition[]{ {-1,0},{1,0},{0,-1},{0,1} };
std::pair<int, int> startPosition, destPosition;

struct node {
	direction dir;
	int y;
	int x;
};

bool isPossible(const direction nextDirection, char nextPipe)
{
	if (nextDirection == direction::UP)
	{
		if (nextPipe == pipes[3] || nextPipe == pipes[6] || nextPipe == pipes[0] || nextPipe == pipes[2])
			return true;
	}
	if (nextDirection == direction::DOWN)
	{
		if (nextPipe == pipes[4] || nextPipe == pipes[5] || nextPipe == pipes[0] || nextPipe == pipes[2])
			return true;
	}
	if (nextDirection == direction::LEFT)
	{
		if (nextPipe == pipes[3] || nextPipe == pipes[4] || nextPipe == pipes[1] || nextPipe == pipes[2])
			return true;
	}
	if (nextDirection == direction::RIGHT)
	{
		if (nextPipe == pipes[5] || nextPipe == pipes[6] || nextPipe == pipes[1] || nextPipe == pipes[2])
			return true;
	}
	return false;
}

direction getDirection(const direction nowDir, const char destPipe)
{
	if (nowDir == direction::UP)
	{
		if (destPipe == pipes[0])
			return nowDir;
		if (destPipe == pipes[2])
			return nowDir;
		if (destPipe == pipes[3])
			return direction::RIGHT;
		if (destPipe == pipes[6])
			return direction::LEFT;
	}
	if (nowDir == direction::DOWN)
	{
		if (destPipe == pipes[0])
			return nowDir;
		if (destPipe == pipes[2])
			return nowDir;
		if (destPipe == pipes[4])
			return direction::RIGHT;
		if (destPipe == pipes[5])
			return direction::LEFT;
	}
	if (nowDir == direction::LEFT)
	{
		if (destPipe == pipes[1])
			return nowDir;
		if (destPipe == pipes[2])
			return nowDir;
		if (destPipe == pipes[3])
			return direction::DOWN;
		if (destPipe == pipes[4])
			return direction::UP;
	}
	if (nowDir == direction::RIGHT)
	{
		if (destPipe == pipes[1])
			return nowDir;
		if (destPipe == pipes[2])
			return nowDir;
		if (destPipe == pipes[6])
			return direction::DOWN;
		if (destPipe == pipes[5])
			return direction::UP;
	}
	return nowDir;
}

bool isOK(const std::vector<std::vector<char>>& board, const std::vector<node>& vec)
{
	if (isPossible(vec[1].dir, board[vec[0].y][vec[0].x]))
	{
		if (isPossible(vec[2].dir, board[vec[0].y][vec[0].x]))
			return true;
	}
	return false;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> R >> C;
	std::vector<std::vector<char>> board(R, std::vector<char>(C));
	std::vector<std::vector<bool>> isVisted(R, std::vector<bool>(C, false));
	int pipeCount = 1;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			std::cin >> board[i][j];
			if (board[i][j] == 'M')
			{
				startPosition = { i,j };
				isVisted[i][j] = true;
			}
			else if (board[i][j] == 'Z')
				destPosition = { i,j };
		}
	}

	std::queue<node>  q;
	for (int i = 0; i < 4; i++)
	{
		int newY = startPosition.first + movePosition[i].first;
		int newX = startPosition.second + movePosition[i].second;
		if (newX < 0 || newX >= C || newY < 0 || newY >= R) continue;
		if (board[newY][newX] == '.') continue;
		if (!isPossible((direction)i, board[newY][newX])) continue;
		q.push({getDirection((direction)i,board[newY][newX]), newY,newX });
		isVisted[newY][newX] = true;
	}

	while (!q.empty())
	{
		auto front = q.front();
		q.pop();

		if (board[front.y][front.x] == '+')
		{
			for (int i = 0; i < 4; i++)
			{
				int newY = front.y + movePosition[i].first;
				int newX = front.x + movePosition[i].second;
				if (isVisted[newY][newX]) continue;
				isVisted[newY][newX] = true;
				q.push({ getDirection(front.dir,board[newY][newX]),newY,newX });
			}
		}
		else if (board[front.y][front.x] == '.')
		{
			std::vector<node> temp;
			temp.push_back({ (direction)-1,front.y,front.x });
			for (int i = 0; i < 4; i++)
			{
				int newY = front.y + movePosition[i].first;
				int newX = front.x + movePosition[i].second;
				if (newX < 0 || newX >= C || newY < 0 || newY >= R) continue;
				if (board[newY][newX] == '.' || board[newY][newX] == 'M' || board[newY][newX] == 'Z') continue;
				if (!isPossible((direction)i, board[newY][newX])) continue;
				temp.push_back({ (direction)( (i%2 ==0) ? i+1 : i-1) ,newY,newX });
			}
			char answer;
			if (temp.size() > 3)
				answer = '+';
			else
			{
				for (int i = 0; i < 7; i++)
				{
					if (i == 2) continue;
					board[front.y][front.x] = pipes[i];
					if (isOK(board, temp))
					{
						std::cout << front.y + 1 << ' ' << front.x + 1 << ' ' << pipes[i];
						return 0;
					}
					board[front.y][front.x] = '.';
				}
			}
		}
		else
		{
			int newY = front.y + movePosition[front.dir].first;
			int newX = front.x + movePosition[front.dir].second;
			if (isVisted[newY][newX]) continue;
			q.push({getDirection(front.dir,board[newY][newX]) ,newY,newX });
			isVisted[newY][newX] = true;
		}
		

	}

	return 0;
}