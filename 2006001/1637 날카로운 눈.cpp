#include <iostream>
#include <vector>
#include <algorithm>

/*
	Ǯ�� ���:
		- N���� �Է°� �� �ּҰ� : left, �ִ� : right ���� �ϰ� �̺�Ž�� ����
		- mid ���� ������ ���� ���� ���� : Ȧ�� (�̹� Ȧ���� ������ ����)
*/

std::vector<std::vector<unsigned unsigned int>> pile;
int N;

int getCount(const int value)
{
	int count = 0;
	for (const auto i : pile)
	{
		if (i[0] > value) continue;		// min > value : �� ���� �������� value���� ���� ���� �������� ����.
		for (int j = i[0]; j <= value && j <= i[1]; j += i[2], count++);
	}
	return count;
}

int main()
{
	std::cin >> N;

	unsigned int min, max, add;
	unsigned int left = 2147483647, right = 0;	
	for (int i = 0; i < N; i++)
	{
		std::cin >> min >> max >> add;
		pile.push_back({ min,max,add });
		left = std::min(left, min);
		right = std::max(right, max);
	}

	unsigned int mid = 0;	// left : 1 , right : INT_MAX�� ��� left+right = int overflow
	int answer = -1;			// ���� Ž�� �� answer == -1�̸� Ȧ���� ���� ���
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (getCount(mid) % 2 == 0)
			left = mid + 1;
		else
		{
			right = mid - 1;
			answer = mid;
		}
	}

	if (answer == -1)
		std::cout << "NOTHING";
	else
		std::cout << answer<<' '<<(getCount(answer) - getCount(answer - 1));

	return 0;
}

/*
3
1 10 1
1 5 1
6 10 1
answer : NOTHING
*/