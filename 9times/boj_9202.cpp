/*
	[백준] 9202. Boggle
		문제 출처 : https://www.acmicpc.net/problem/9202

	[풀이 방법]

	[실패 과정]
		1. BFS에서 방문한 위치는 재방문 X

	[풀이 일자]
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

std::pair<int, int> direction[]{ {-1,0},{-1,-1}, {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };	// UU, UL, LL, DL, DD, DR, RR, UR
std::set<std::string> dictionary;
std::set<std::string> trie;
std::set<std::string> answerList;
std::map<int, std::set<std::string>> answer;

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

int bfs(const std::vector<std::string>& board, const std::string str, std::pair<int, int> position)
{
	std::queue<std::pair<std::string, std::pair<int, int>>> queue;
	queue.push({ str , position });

	std::vector<std::vector<bool>> isUsed(4, std::vector<bool>(4, false));
	isUsed[position.first][position.second] = true;
	int score = 0;
	while (!queue.empty())
	{
		auto front = queue.front();
		queue.pop();
		if (front.first.size() > 8)
			continue;

		if (dictionary.find(front.first) != dictionary.end())
		{
			if (answerList.find(front.first) == answerList.end())
			{
				score += getScore(front.first.size());
				answerList.insert(front.first);
				answer[front.first.size()].insert(front.first);
			}
			continue;
		}
		for (int i = 0; i < 8; i++)
		{
			int newY = front.second.first + direction[i].first;
			int newX = front.second.second + direction[i].second;
			if (newY < 0 || newY >= 4 || newX < 0 || newX >= 4) continue;
			if (isUsed[newY][newX]) continue;
			std::string newString = front.first + board[newY][newX];
			if (trie.find(newString) == trie.end())
				continue;
			queue.push({ newString,{ newY,newX } });
			isUsed[newY][newX] = true;
		}
	}

	return score;
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
		int score = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				score += bfs(board, board[i].substr(j, 1), { i,j });
		}

		std::cout << score << ' ' << *(answer.rbegin()->second.begin()) << ' ' << answerList.size() << '\n';
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