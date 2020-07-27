/*
	[����] 2014 �Ҽ��� ��
		���� ��ó : https://www.acmicpc.net/problem/2014

	[Ǯ�� ���]	set
		1. �켱���� ť�� Ǯ��ٰ� �ߺ��� ���� ���� set�� �̿��ߴ�.
		2. ���� ���鿡 ���� �Ҽ����� ��� �����ش�.
		3. ������ INT ���� �̳��̸� ������ ũ��� �������� �������� �ʰ� ������ �ɾ��ش�.
			- ���� ������ ������ N���� ũ�� ���� ����� ���� ���� ������ �ִ񰪺��� ũ�� ���� ���� ������. 
				�ʿ��� ���� ū ���� �ƴ϶� ���� ���� ���̿� �� ���� ���̴�.

	[���� ����]
		1. ������ �߸� �����߾���. ����� �Ҽ��� �����ٰ� �Ҽ��� �� ��������ߴ�.
		2. ������ ������ INT����. �� ó���� ���� ������ �޸��ʰ��� ���Դ�.
		3. ����� �Ҽ����� ���� ������ N�� �Ѱ� ��� ����� ������ �ִ񰪺��� ũ�ٸ� �������ִ� ������ �߰��ߴ�. -> �ð��ʰ� ���� �ذ�

	[Ǯ�� ����]	2020.07.26.
*/

#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int K, N;
	std::cin >> K >> N;

	std::vector<int> decimals(K);
	std::set<int> calculatedNumbers;
	for (int i = 0; i < K; i++)
	{
		std::cin >> decimals[i];
		calculatedNumbers.insert(decimals[i]);
	}
	int count = 1;
	long long answer = 0, maxNumber = decimals.back();
	while (true)
	{
		answer = static_cast<long long>(*(calculatedNumbers.begin()));
		calculatedNumbers.erase(calculatedNumbers.begin());

		if (count == N)
			break;

		for (const auto data : decimals)
		{
			long long multiplicatedResult = answer * data;
			if (multiplicatedResult >= INT_MAX) break;
			if (calculatedNumbers.size() > N && multiplicatedResult > maxNumber) break;
			maxNumber = std::max(maxNumber, multiplicatedResult);
			calculatedNumbers.insert(multiplicatedResult);
		}
		count++;
	}
	std::cout << answer;
	return 0;
}