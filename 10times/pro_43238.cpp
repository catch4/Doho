/*

	[���� ����]
		1. Ȥ�ó� �ؼ� �켱����ť �̿��غ����� �ð� �ʰ� 
		2. sum�� ���� int -> long long�� ����
		3. TC 8���� �����Ѵٸ� max���� ���캸��. times�迭�� ������ Ÿ���� int�̴�. int * int = int : overflow ����
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