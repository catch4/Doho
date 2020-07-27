/*
	[����] 1956 �
		���� ��ó : https://www.acmicpc.net/problem/1956

	[Ǯ�� ���] : �÷��̵�-�ͼ� 
		- �Ϲ����� �÷��̵�-�ͼ� �˰����� �ڱ��ڽ��� 0���� ���´�. ������ �� �������� ���ϴ� ���� ����Ŭ�̹Ƿ� INF�� ���´�.
		  �˰����� ������ �� costs[i][j]�� �ּڰ��� �����Ѵ�.

	[���� ����]
		������ ���� : ������ �� ����. ã�°��� �Ұ����� ��� -1 �����̴�.
			1. INF�� 5000000�����ϸ� 100ms, 4000001�� �ϸ� 104ms�� ���´�.. 
	
	[Ǯ�� ����] 2020.07.21
*/

#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 5000000;

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int V, E;
	std::cin >> V >> E;

	std::vector<std::vector<int>> costs(V, std::vector<int>(V, INF));

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		costs[a - 1][b - 1] = c;
	}

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (costs[i][j] > costs[i][k] + costs[k][j])
					costs[i][j] = costs[i][k] + costs[k][j];
			}
		}
	}

	int answer = INF;
	for (int i = 0; i < V; i++)
		answer = std::min(answer, costs[i][i]);

	if (answer == INF)
		std::cout << -1;
	else
		std::cout << answer;
	return 0;
}