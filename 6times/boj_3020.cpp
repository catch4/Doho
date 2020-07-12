/*
	[BOJ] 3020 ���˹���
		���� ��ó : https://www.acmicpc.net/problem/3020

	[���� Ǯ��] : �̺� Ž�� (upper_bound, lower_bound)
		1. �������� ������ ���̸� ���� ���Ϳ� ������ �� �����Ѵ�.
		2. ���� 1���� H���� ������ ���鼭 ����ϴ� ��ֹ� ������ Ž���Ѵ�.
			- map�� ����� ��ֹ� ���� �� count�� ������ �Ͱ� �ܼ� ������ �ּҰ����� ������ cnt++�ϴ� ���� 12ms�� ���̰� ����. (map�� input�ø��� �����ϴ� �κ� �����̶�� �Ǵ�)
		2-1. ������ (up) : ���̰� (H - i) ���� ū �͵��� ������ �������� ����Ǵ� ��ֹ� �����̴�.	-> upper_bound
		2-2. ���� (down) : ���̰� i���� �����͵��� ������ �������� ����Ǵ� ��ֹ� �����̴�.	-> lower_bound.			

	[����]
		1. ���� Ž������ ���̰� 1���� H���� ������ üũ�ϴ� ���� �ð��ʰ� �߻�. : �ִ� 1õ��� ����
			 - Ž������ �� ��ֹ��� ������ �ּڰ����� ũ�� ���� Ż�� : �ð� �ʰ�

	[Ǯ�� ����] 2020.07.09.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, H;
	std::cin >> N >> H;

	std::vector<int> up;
	std::vector<int> down;

	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		if (i % 2 == 0)
			up.push_back(temp);
		else
			down.push_back(temp);
	}

	std::sort(up.begin(), up.end());
	std::sort(down.begin(), down.end());

	int answer = 2147483647;
	int cnt = 1;
	for (int i = 1; i <= H; i++)
	{
		// ����
		int count = down.size() - (std::lower_bound(down.begin(), down.end(), i) - down.begin());
		// ������
		count += up.size() - (std::upper_bound(up.begin(), up.end(), (H - i)) - up.begin());
		if (answer == count)
			cnt++;
		if (answer > count)
		{
			answer = count;
			cnt = 1;
		}
	}

	std::cout << answer << ' ' << cnt;
	return 0;
}