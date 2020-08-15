/*
	[����] 2931 ������
		���� ��ó : https://www.acmicpc.net/problem/2931

	[Ǯ�� ���] ����, ���� Ž��
		1. ���� ��ü�� ��ȸ�ϸ鼭 '.'�̸鼭 ����Ǵ� ���� �ִ� ��츦 ã�´�.
		2. ����Ǵ� ���� �����ϸ� ���Ϳ� ��ǥ���� ���� ��ġ�� �ִ´�.
		3. ������ ���� 0�� �ƴ� ��� �׿� �´� ���� �������ش�.
			- �����帧�� ������ ��츸 �Է����� �־����Ƿ� vec�� ���� ���� '.' ��ǥ�� ���� 1���̴�.

		[���� ����]
			1. BFS�� �̿��� Ǯ���µ� ���⿡ ���� Y,X �� ���ؼ� �̵��ϴ� �κп��� ����ó���� Ʋ�� �κ��� �־���.
				������ �� ã�ƺ��߰ڴ�. -> ����.

*/

#include <iostream>
#include <vector>
#include <queue>

int R, C;

std::vector<std::vector<char>> pipes{ {'|','+','1','4'},{ '|','+','2','3' } ,{ '-','+','1','2' } ,{ '-','+','3','4' } };
std::pair<int, int> movePosition[]{ {-1,0},{1,0},{0,-1},{0,1} };

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> R >> C;
	std::vector<std::vector<char>> board(R, std::vector<char>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			std::cin >> board[i][j];
	}

	std::vector<int> vec;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == '.')
			{
				for (int k = 0; k < 4; k++)
				{
					int newY = i + movePosition[k].first;
					int newX = j + movePosition[k].second;
					if (newY < 0 || newY >= R || newX < 0 || newX >= C) continue;
					if (board[newY][newX] == '.') continue;
					for (int z = 0; z < 4; z++)
						if (board[newY][newX] == pipes[k][z])
							vec.push_back(k);
				}
				if (!vec.empty())
				{
					std::cout << i + 1 << ' ' << j + 1 << ' ';
					if (vec.size() == 4)
					{
						std::cout << '+';
						return 0;
					}
					if (vec.size() == 2)
					{
						if (vec[0] == 0)
						{
							if (vec[1] == 1) std::cout << '|';
							else if (vec[1] == 2) std::cout << '3';
							else if (vec[1] == 3) std::cout << '2';
						}
						else if (vec[0] == 1)
						{
							if (vec[1] == 0) std::cout << '|';
							else if (vec[1] == 2) std::cout << '4';
							else if (vec[1] == 3) std::cout << '1';
						}
						else if (vec[0] == 2)
						{
							if (vec[1] == 0) std::cout << '3';
							else if (vec[1] == 1) std::cout << '4';
							else if (vec[1] == 3) std::cout << '-';
						}
						else if (vec[0] == 3)
						{
							if (vec[1] == 0) std::cout << '2';
							else if (vec[1] == 1) std::cout << '1';
							else if (vec[1] == 3) std::cout << '-';
						}
						return 0;
					}
				}
			}
		}
	}
	return 0;
}