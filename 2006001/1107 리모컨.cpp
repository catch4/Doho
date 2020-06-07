#include <iostream>
#include <vector>

std::vector<bool> isUseable(10, true);

bool isIn(int value)
{
	if (value < 0)
		return true;

	if (value == 0)
		return !isUseable[value];

	for (int i = 1; value/i != 0; i *= 10)
	{
		if (!isUseable[(value/i) % 10])
			return true;
	}
	return false;
}

int getDigits(int value)
{
	int count = 1;
	for (int i = 10; value / i != 0; i *= 10, count++);
	return count;
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	int answer = 0;
	if (n == 100)
		answer = 0;
	else if (m == 10)
		answer = abs(100 - n);
	else
	{
		int temp;
		for (int i = 0; i < m; i++)
		{
			std::cin >> temp;
			isUseable[temp] = false;
		}

		int count = 0;
		while (true)
		{
			if (!isIn(n - count))
			{
				count += getDigits(n - count);
				break;
			}
			if (!isIn(n + count))
			{
				count += getDigits(n + count);
				break;
			}
			count++;
		}
		answer = count;
	}

	std::cout << ((answer < abs(n-100))?answer:abs(n-100));

	return 0;
}

/*
1. N = 100 인 경우
2. 버튼이 모두 망가진 경우
3. 숫자 +-가 빠른 경우
4. +-가 빠른 경우
*/

/*
test case
0 
9
0 1 2 3 4 5 6 7 9
output : 9

9999
1
9
output : 6

162
9
0 1 3 4 5 6 7 8 9
output : 62

5
2
4 6
output : 1

10
9
1 2 3 4 5 6 7 8 9
output : 11

1555
8
0 1 3 4 5 6 7 9
output : 670
*/

/*
완전 탐색 알고리즘으로 기준값에서 ±n씩 해주면서 결과 값에 고장난 버튼 유무 확인.
*/