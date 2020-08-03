/*

	[실패 과정]
		1. 혹시나 해서 우선순위큐 이용해봤지만 시간 초과 
		2. sum의 값을 int -> long long로 수정
		3. TC 8번이 실패한다면 max값을 살펴보자. times배열의 데이터 타입은 int이다. int * int = int : overflow 가능
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	long long min = 1, max = (static_cast<long long>(*max_element(times.begin(), times.end())) * n);
	while (min <= max)
	{
		long long mid = (min + max) / 2;
		int sum = 0;
		for (const auto value : times)
			sum += (mid /value);
		if (sum >= n)
		{
			max = mid - 1;
			answer = mid;
		}
		else
			min = mid + 1;
	}
	return answer;
}

int main()
{
	cout << solution(3, { 1 });
	return 0;
}