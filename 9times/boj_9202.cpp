/*
	[����] 9202. Boggle
		���� ��ó : https://www.acmicpc.net/problem/9202

	[Ǯ�� ���] DFS + �ణ�� trie?
		1. ���� ���ڿ��� dictionary set�� �ְ� TRIE������� ���ڿ��� ������ trie set�� �ִ´�.
		2. 4x4�� ���ڿ� ���� DFS ����
			- 8�������� Ž���ϴµ� ���ٿ��� ���ڰ� trie�� �������� ������ �н�.

	[���� ����]
		1. BFS���� �湮�� ��ġ�� ��湮 X
		2. BFS -> DFS�� ���� : �ð��ʰ�
			- isUsed üũ�� AC -> M / AM�� ���� ��� AC->M�� �湮�߱⿡ �Ұ����ϴ�.
		3. ã�� ���ڿ����� map���� ����� ���������� �ð��ʰ������� answerSize, answer string���� ����. : �ð��ʰ�
		4. dfs Ż�� ������ ���ڿ� ���̰� 8�ΰ�찡 �ƴ϶� dictionary�� ���� �� ���ڿ��� ���̷� ���� ���� : ����
		5. ���� dfs �����ϱ� ���� ���� ���ڰ� trie�� ���ϴ��� üũ -> 20ms �ð� ����

	[Ǯ�� ����] 2020.08.03.
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

std::pair<int, int> direction[]{ {-1,0},{-1,-1}, {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };	// UU, UL, LL, DL, DD, DR, RR, UR
std::set<std::string> dictionary;
std::set<std::string> trie;
std::set<std::string> answerList;
int answerSize = 0;
int maxStringSize = 0;
std::string answer;

int score = 0;
int getScore(const int stringSize)
{
	if (stringSize <= 2)
		return 0;
	else if (stringSize <= 4)
		return 1;
	else if (stringSize == 5)
		return 2;
	else if (stringSize == 6)
		return 3;
	else if (stringSize == 7)
		return 5;
	else if (stringSize == 8)
		return 11;
}

void dfs(const std::vector<std::string>& board, std::vector<std::vector<bool>>& isUsed, std::string str, std::pair<int, int> position)
{
	if (dictionary.find(str) != dictionary.end())
	{
		if (answerList.find(str) == answerList.end())
		{
			score += getScore(str.size());
			answerList.insert(str);
			if (answerSize < str.size())
			{
				answer = str;
				answerSize = str.size();
			}
			else if (answerSize == str.size())
			{
				if (answer > str)
					answer = str;
			}
		}
	}

	if (str.size() == maxStringSize)
		return;

	for (int i = 0; i < 8; i++)
	{
		int newY = position.first + direction[i].first;
		int newX = position.second + direction[i].second;
		if (newY < 0 || newY >= 4 || newX < 0 || newX >= 4) continue;
		if (isUsed[newY][newX]) continue;
		std::string newString = str +  board[newY][newX];
		if (trie.find(newString) == trie.end())
			continue;
		isUsed[newY][newX] = true;
		dfs(board, isUsed, newString, { newY,newX });
		isUsed[newY][newX] = false;

	}
}

int main()
{
	int W, B;
	std::cin >> W;

	for (int i = 0; i < W; i++)
	{
		std::string input;
		std::cin >> input;
		dictionary.insert(input);
		maxStringSize = (maxStringSize < input.size()) ? input.size() : maxStringSize;
		for(int j=0;j<input.size();j++)
			trie.insert(input.substr(0,1+j));
	}


	std::cin >> B;
	while (B--)
	{
		std::vector<std::string> board(4);
		for (int i = 0; i < 4; i++)
			std::cin >> board[i];

		answerList.clear();
		answer.clear();
		score = 0;
		answerSize = 0;
		answer = "";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::vector<std::vector<bool>> isUsed(4, std::vector<bool>(4, false));
				std::string startString = board[i].substr(j, 1);
				if (trie.find(startString) == trie.end()) continue;
				isUsed[i][j] = true;
				dfs(board, isUsed, startString, { i,j });
				isUsed[i][j] = false;
			}
		}

		std::cout << score << ' ' << answer << ' ' << answerList.size() << '\n';
	}
}
/*

1
ABA
1
ABCD
EFGH
IJKL
MNOP
*/