/*
	[����] 5052 ��ȭ��ȣ ���
		���� ��ó : https://www.acmicpc.net/problem/5052

	[Ǯ�� ���] ����
		1. input�� ���ڿ� ���·� �ް� �迭�� ����
		2. ���� �� i�� i+1�� �� (i+1�� substr�̿��ؼ� i�� ���̸�ŭ ���ڿ� ����)
		3. ���� ���� ������ NO, �ƴϸ� YES
		=> 120ms

	[���� ����]
		1. ���ڿ��� 0���� comapred size���� ���ϴ� �ݺ����� �� N*N�� �ݺ� : �ð��ʰ�
		2. �Է� ������� ���ڿ� �����ؼ� N*N (���� ¬ TRIE ���� �� ó��) : �ð��ʰ�

	[Ǯ�� ����] 2020.08.08

	None -> 120ms
	cin.tie(0) -> 116ms (-4ms)
	sync_with_stdio(false) -> 60ms (-60ms)
	tie + sync -> 56ms
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--)
	{
		int N;
		std::cin >> N;
		std::vector<std::string> dictionary(N);

		for (int i = 0; i < N; i++)
			std::cin >> dictionary[i];

		std::sort(dictionary.begin(), dictionary.end());

		bool isFind = false;
		for (int i = 0; i < N - 1; i++)
		{
			if (dictionary[i] == dictionary[i + 1].substr(0, dictionary[i].size()))
			{
				isFind = true;
				break;
			}
		}

		if (isFind)
			std::cout << "NO" << '\n';
		else
			std::cout << "YES" << '\n';
	}
}