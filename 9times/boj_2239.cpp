/*
	[����] 2239 ������
		���� ��ó : https://www.acmicpc.net/problem/2239
	
	[Ǯ�� ���] ����Ž��

	[���� ����]
		1. board call by value -> call by reference�� ���� (�ð��ʰ�)
		2. ������ �������� ��� ������ �����ؼ� ���� ���� �� : set�� �̿� (�ð��ʰ�)
			=> �ִ밪 answer ���� ũ�� �� �� answer�� ũ�� �����ϴ� ������� �ٲ� (�ð��ʰ�)
		3. ���� �˻� �Խ��� ���� �ذ� : ������ �������� ���� ������.
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

std::string answer = "999999999999999999999999999999999999999999999999999999999999999999999999";

bool isCorrect(const std::vector<std::string>& board, const std::pair<int, int> position, const char checkNumber)
{
	for (int i = 0; i < 9; i++)
		if (board[position.first][i] == checkNumber || board[i][position.second] == checkNumber)
			return false;
	
	int yIndex = (position.first / 3) * 3;
	int xIndex = (position.second / 3) * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[yIndex + i][xIndex + j] == checkNumber)
				return false;
		}
	}

	return true;
}

bool dfs(std::vector<std::string>& board, int zeroCount)
{
	if (zeroCount == 0)
	{
		std::string result;
		for (int i = 0; i < board.size(); i++)
			result += board[i];
		if (answer > result)
			answer = result;
		return true;
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '0')
			{
				for (int number = 1; number <= 9; number++)
				{
					if (!isCorrect(board, { i,j }, number + '0'))
						continue;
					board[i][j] = number + '0';
					if (dfs(board, zeroCount - 1))
						return true;
					board[i][j] = '0';
				}
				break;
			}
		}
		if (board[i].find('0') != std::string::npos) return false;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	std::vector<std::string> board(9);
	int zeroCount = 0;
	for (int i = 0; i < 9; i++)
	{
		std::cin >> board[i];
		for (int j = 0; j < 9; j++)
			if (board[i][j] == '0')
				zeroCount++;
	}

	dfs(board,zeroCount);

	for (int i = 0; i < answer.size(); i++)
	{
		if (i != 0 && i % 9 == 0)
			std::cout << '\n';
		std::cout << answer[i];
	}

	return 0;
}