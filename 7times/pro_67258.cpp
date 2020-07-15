/*
	[PRO] ���� ����
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/67258

	[Ǯ�� ���] : �� ������ / �����̵� ������
		1. ������ ������ �ִ��� Ȯ���Ѵ�.
			- set/map�� �̿�
		2. �迭�� ��ȸ�ϸ鼭 endIndex ��ġ�� ������ map (nowStatus)�� �ִ´�. �ι�° ���ڴ� endIndex��.
			- �̹� ����ִ� ������ �ٽ� ���ð�� �ε����� �������ش�.
		3. nowStatus�� ũ�Ⱑ ������ ���� ������ ���ٸ� ��� ������ �����ߴٴ� �� �̴�.
			- nowStatus���� �� ������ �ε����� �ִ�. �ּ� �ε��� ���� �ִ� �ε��� ���� ���Ѵ�.
			- ������ ���� �ΰ��� ���� �̿��� ������ ���̸� ã�´�.
		4. ������ ���̿� ����, �� �ε����� ���ߴٸ� map (answer)�� insert���ش�.
			- �ּ� ������ ���̸� ��� ���ؼ��̸�, answer�� value�� map�� ������ ���̰� ���� �� ���� �ε����� ���� ���� ã�� ���ؼ���.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void isAll(const map<string, int>& lists, int* start, int * end)
{
	for (const auto& i : lists)
	{
		*start = std::min(*start, i.second);
		*end = std::max(*end, i.second);
	}
}
vector<int> solution(vector<string> gems) {
	map<string, int> gemLists;

	for (const auto& i : gems)
	{
		if (gemLists.find(i) == gemLists.end())
			gemLists[i];
	}

	map<string, int> nowStatus;
	map<int, map<int, int>> answer;
	int endIndex = 0;
	while (true)
	{
		if (endIndex >= gems.size())
			break;
		nowStatus[gems[endIndex++]] = endIndex;		
		int start=gems.size(), end = 0;
		if (gemLists.size() == nowStatus.size())
		{
			isAll(nowStatus, &start, &end);
			answer[(end - start + 1)].insert({ start + 1, end + 1 });
		}
	}

	return{ answer.begin()->second.begin()->first,answer.begin()->second.begin()->second };
}

int main()
{
	solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
	return 0;
}