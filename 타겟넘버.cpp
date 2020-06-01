#include <string>
#include <vector>

using namespace std;

int answer = 0;
int destValue = 0;

void dfs(vector<int> numbers, int index)
{
	if (index >= numbers.size())
		return;

	numbers[index] *= -1;

	int sum = 0;
	for (const auto value : numbers)
		sum += value;

	if (sum == destValue)
	{
		answer++;
		return;
	}

	for (int i = index + 1; i < numbers.size(); i++)
		dfs(numbers, i);
}

int solution(vector<int> numbers, int target) {
	destValue = target;

	for (int i = 0; i<numbers.size(); i++)
		dfs(numbers, i);

	return answer;
}