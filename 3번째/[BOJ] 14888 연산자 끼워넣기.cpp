/*
	[백준] 14888. 연산자 끼워넣기
		문제 출처 : https://www.acmicpc.net/problem/14888
		풀이 : 2020.06.19
		비고 : sloved.
*/

/*
	[풀이 방법] - DFS 알고리즘을 이용
		1. 연산자 + - x / 순서대로 vector operatorCount 할당
		2. 수의 개수가 N이므로 재귀 호출을 N번할 때 RETURN 해준다.
		3. 중간 계산의 결과도 ± 10억이라서 int형으로 충분하다.
		4. 입력받는 수는 1부터 시작이므로 /연산 예외처리 안해줘도 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> numbers;
int min = 2147483647, max = -2147483647;

void dfs(int value, int count, std::vector<int> operatorCount)
{
	if (count == N)
	{
		min = std::min(min, value);
		max = std::max(max, value);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (operatorCount[i] != 0)
		{
			operatorCount[i] -= 1;
			if (i == 0)
				dfs(value + numbers[count], count + 1, operatorCount);
			else if(i==1)
				dfs(value - numbers[count], count + 1, operatorCount);
			else if (i == 2)
				dfs(value * numbers[count], count + 1, operatorCount);
			else
				dfs(value / numbers[count], count + 1, operatorCount);
			operatorCount[i] += 1;
		}
	}
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	numbers.resize(N);
	for (int i = 0; i < N; i++)
		std::cin >> numbers[i];

	std::vector<int> operatorCount(4);
	for (int i = 0; i < 4; i++)
		std::cin >> operatorCount[i];

	dfs(numbers[0], 1, operatorCount);

	std::cout << max << '\n' << min;


	return 0;
}