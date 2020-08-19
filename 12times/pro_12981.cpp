/*
	[����] ���� �����ձ�
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/12981

	[Ǯ�� ���]
		1. �迭 words�� ��ȸ�ϸ鼭 ������ ������ üũ�Ѵ�.
		2. ���� �迭 ������ ���������� ��ȸ�ߴٸ� 0,0�� �����Ѵ�.
		2-1. �� ���� ��� ������ �����Ѵ�.
*/

#include <iostream>	
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	set<string> used_words{ words.front() };
	int i = 1;
	for (i; i<words.size(); i++)
	{
		if (words[i].front() != words[i - 1].back())
			break;
		auto retVal = used_words.insert(words[i]);
		if (retVal.second == false)
			break;
	}

	if (i == words.size())
		return{ 0,0 };
	else
	{
		answer.push_back((i%n) + 1);
		answer.push_back((i / n) + 1);
		return answer;
	}
}

