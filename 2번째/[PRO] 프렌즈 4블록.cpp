#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int search(int m, int n, vector<string>& board, set<pair<int, int>>& deletePos)
{
	for (int height = 0; height < m - 1; height++)
	{
		for (int width = 0; width < n - 1; width++)
		{
			if (board[height][width] == '-') continue;
			if (board[height][width] != board[height][width + 1]) continue;
			if (board[height][width] != board[height + 1][width + 1]) continue;
			if (board[height][width] != board[height + 1][width]) continue;

			deletePos.insert(make_pair(height, width));
			deletePos.insert(make_pair(height, width + 1));
			deletePos.insert(make_pair(height + 1, width));
			deletePos.insert(make_pair(height + 1, width + 1));
		}
	}
	return deletePos.size();
}

void blockDelete(vector<string>& board, set<pair<int, int>>& deletePos)
{
	for (const auto& value : deletePos)
		board[value.first][value.second] = '-';
}

void fillBoard(int m, int n, vector<string>& board)
{
	for (int height = m - 1; height > 0; height--)
	{
		for (int width = 0; width < n; width++)
		{
			if (board[height][width] != '-') continue;
			for (int temp = height - 1; temp >= 0; temp--)
			{
				if (board[temp][width] != '-')
				{
					board[height][width] = board[temp][width];
					board[temp][width] = '-';
					break;
				}
			}

		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	while (true)
	{
		set<pair<int, int>> deletePos;

		// 삭제할 블록 찾기
		answer += search(m, n, board, deletePos);

		if (deletePos.empty())
			break;

		blockDelete(board, deletePos);

		// 블록 하강
		fillBoard(m, n, board);
	}
	return answer;
}

int main()
{
	cout << solution(4, 5, { {"CCBDE"},{"AAADE"},{"AAABF"},{"CCBBF"} });
	return 0;
}