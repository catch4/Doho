/*
	[����] 14890 ����
		���� ��ó : https://www.acmicpc.net/problem/14890

	[Ǯ�� ���] : ���� Ž��
		1. Ž���Ϸ��� ���� ���� ���� ����Ѵ�.
			- ���� ���̰� 1 �̻��̶�� return false;
			- ���θ� ���� ���� ������ ���ӵ� ���� ĭ�� ���̰� L���� ���� ��� return false;
				- Ž���� �� �������� ���̰� ����/���� ���� üũ�ؾ��մϴ�.
			- ���θ� ���� ���� �� ���θ� ���� ���

	[���� ����]
		1. ���� ���� ���� �� ���θ� ���� ���� �˻��ϴ� ���� ���θ� �ǹ�����. 
			-	���ο� ���ο� ���ΰ� ���� ��ġ�� ���̰� �Ǵ� ���� ���ΰ� ��ġ�� ��찡 �ƴϴ�!
*/

#include <iostream>
#include <vector>

int N, L;
std::vector<std::vector<int>> map;

bool checkHorizon(const int index)
{
	std::vector<bool> isUsed (N,false);
	for (int i = 1; i < N; i++)
	{
		int diff = map[index][i] - map[index][i - 1];
		if (diff > 1 || diff < -1) return false;
		if (diff == 0) continue;
		
		// ���� ���̰� 1�� ��� : i�� i-1���� ����
		if (diff == 1)
		{
			// i-1 ���� -- �ϸ鼭 ���̰� ������ üũ. -> L��ŭ -- �ϴµ� �� ���� ������ ������ return false
			int rangeIndex = i;
			int rangeHeight = map[index][i - 1];
			for (int j = i-1; j >= 0 && (i - j) <= L; j--)
			{
				if (map[index][j] != rangeHeight) break;
				if (isUsed[j]) break;
				rangeIndex = j;
			}
			if (i - rangeIndex < L) return false;

			// ���� ��ġ
			for (; rangeIndex != i; rangeIndex++)
				isUsed[rangeIndex] = true;
		}
		else
		{
			// ���� ���̰� -1�� ��� : i�� i-1���� ����
			int rangeIndex = i-1;
			int rangeHeight = map[index][i];
			for (int j = i; j < N && (j - (i - 1)) <= L; j++)
			{
				if (map[index][j] != rangeHeight) break;
				if (isUsed[j]) break;
				rangeIndex = j;
			}
			if ((rangeIndex - (i - 1)) < L) return false;
			for (; rangeIndex >=  i; i++)
				isUsed[i] = true;
			i -= 1;
		}		
	}
	return true;
}

bool checkVertical(const int index)
{
	std::vector<bool> isUsed(N, false);
	for (int i = 1; i < N; i++)
	{
		int diff = map[i][index] - map[i-1][index];
		if (diff > 1 || diff < -1) return false;
		if (diff == 0) continue;

		// ���� ���̰� 1�� ��� : i�� i-1���� ����
		if (diff == 1)
		{
			// i-1 ���� -- �ϸ鼭 ���̰� ������ üũ. -> L��ŭ -- �ϴµ� �� ���� ������ ������ return false
			int rangeIndex = i;
			int rangeHeight = map[i-1][index];
			for (int j = i - 1; j >= 0 && (i - j) <= L; j--)
			{
				if (map[j][index] != rangeHeight) break;
				if (isUsed[j]) break;
				rangeIndex = j;
			}
			if (i - rangeIndex < L) return false;

			// ���� ��ġ
			for (; rangeIndex != i; rangeIndex++)
				isUsed[rangeIndex] = true;
		}
		else
		{
			// ���� ���̰� -1�� ��� : i�� i-1���� ����
			int rangeIndex = i-1;
			int rangeHeight = map[i][index];
			for (int j = i; j < N && (j - (i - 1)) <= L; j++)
			{
				if (map[j][index] != rangeHeight) break;
				if (isUsed[j]) break;
				rangeIndex = j;
			}
			if ((rangeIndex - (i - 1)) < L) return false;
			for (; rangeIndex >= i; i++)
				isUsed[i] = true;
			i -= 1;
		}
	}
	return true;
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> L;

	map.resize(N);

	for (int i = 0; i < N; i++)
	{
		map[i].resize(N);
		for (int j = 0; j < N; j++)
			std::cin >> map[i][j];
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (checkHorizon(i))
			answer++;
		if (checkVertical(i))
			answer++;

	}

	std::cout << answer;

}