#include <iostream>
#include <vector>

// 0 : �� -> �� -> �� -> �� (%4)
int map[51][51];
typedef std::pair<int, int> pair;

int n, m;

pair getPos(pair nowPos, int direction)
{
	switch (direction)
	{
	case 0:
		nowPos.second -= 1;
		break;
	case 1:
		nowPos.first -= 1;
		break;
	case 2:
		nowPos.second += 1;
		break;
	case 3:
		nowPos.first += 1;
		break;
	default:
		break;
	}

	return nowPos;
}

pair getBackPos(pair nowPos, int direction)
{
	switch (direction)
	{
	case 0:
		nowPos.first += 1;
		break;
	case 1:
		nowPos.second -= 1;
		break;
	case 2:
		nowPos.first -= 1;
		break;
	case 3:
		nowPos.second += 1;
		break;
	default:
		break;
	}
	return nowPos;
}

void cleanning(pair pos, int &count)
{
	count++;
	map[pos.first][pos.second] = count + 1;
}

void dfs(pair pos, int direction, int& count)
{
	// ���� ��ġ û��
	cleanning(pos, count);

	// ���� ���� û�� ���� üũ
	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			pair destPos = getPos(pos, direction);
			direction = (direction == 0) ? 3 : direction - 1;
			// û������ ���� �����̸鼭 ���� �ƴ� ��� üũ
			if (map[destPos.first][destPos.second] == 0)
				return dfs(destPos, direction, count);
		}
		// 4���� ��� û�Ұ� �Ǿ��ų� ���� ��� -> ����
		pos = getBackPos(pos, direction);
		if (map[pos.first][pos.second] == 1)
			return;
	}

}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;

	int r = 0, c = 0, d = 0;
	std::cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cin >> map[i][j];
	}
	int count = 0;
	dfs(std::make_pair(r, c), d, count);
	std::cout << count;
	return 0;
}

/*
�Է�:
6 6
2 1 3
1 1 1 1 1 1
1 0 0 0 0 1
1 0 1 1 1 1
1 0 1 1 1 1
1 0 1 1 1 1
1 1 1 1 1 1
����: 7

*/