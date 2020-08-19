/*
	[프로] 영어 끝말잇기
		문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/12981

	[풀이 방법]
		1. 배열 words를 순회하면서 문제의 조건을 체크한다.
		2. 만약 배열 끝까지 정상적으로 순회했다면 0,0을 리턴한다.
		2-1. 그 외의 경우 정답을 리턴한다.
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

