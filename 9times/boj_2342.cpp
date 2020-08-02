/*
	[����] 2342 Dance Dance Revolution
		���� ��ó : https://www.acmicpc.net/problem/2342

	[Ǯ�� ���] DFS + DP
		1. DFS�� ��� ��츦 ���ϸ� �ð��ʰ��� ����.
			- ��� ��츦 �� ���ؾ��Ѵ�. �պκ��� �ּҰ��̶� �ؼ� ������ �ּҰ��̶�� ������ ����. ex) 1 2 3 2 1 0 -> 11
		2. dpTable�� �����Ѵ�. [count][left][right]�̴�. count��°�� �� left, right�� �ּڰ��̴�.
			���������� ä������ [0][0][0]�� ���� �ȴ�.
	[Ǯ�� ����] 2020.08.01
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int SIZE;
int costs[5][5] { {-1,2,2,2,2},{-1,1,3,4,3},{-1,3,1,3,4},{-1,4,3,1,3},{-1,3,4,3,1} };
int dpTable[100001][5][5];
const int INF = 2147483647;
std::vector<int> steps;

int dfs(const int left = 0, const int right = 0, const int count = 0)
{
	if (count == SIZE)
		return 0;

	auto& ref = dpTable[count][left][right];
	if (ref != 0)
		return ref;

	// {0,0}�� ���� ��, �� �Ѵ� ����.
	int nextStep = steps[count];
	ref = INF;
	// ����
	ref = std::min(dfs(nextStep, right, count + 1) + costs[left][nextStep],ref);
	ref = std::min(dfs(left, nextStep, count + 1) + costs[right][nextStep],ref);
	return ref;
}

int main()
{

	while (true)
	{
		int number;
		std::cin >> number;
		if (number == 0) break;
		steps.push_back(number);
	}
	SIZE = steps.size();

	std::cout<<dfs();
	return 0;
}