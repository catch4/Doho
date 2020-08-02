/*
	[����] 1507 �ñ��� ��ȣ
	
	[Ǯ�� ���] �÷��̵� �ͼ�
		1. �÷��̵� �ͼ� �˰����� �������� �ǵ����� �������� ������ Ǯ����.
		2. a -> b���� a->k->b��� [a][k] + [k][b] == [a][b]�� ���̴�. �� ������ �����Ѵٸ� [a][b] = 0���� �������ش�.
		3. �������� A->B�� ��� ��찡 �����ϴٰ� �ߴ�. �̸��� A->B�� �ּ� �Ÿ��� �ƴ϶�� �Ұ����� ����� �Ѵ�.

	[���� ����]
		1. distance �迭�� ���� 0���� �����ع����� Ʋ��. -> answer �迭 �߰��� ����

	[Ǯ�� ����] 2020.07.31
*/

#include <iostream>
#include <vector>

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> distance(N, std::vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> distance[i][j];
	}

	std::vector<std::vector<int>> answer = distance;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i==k||j==k) continue;
				if (distance[i][j] == (distance[i][k] + distance[k][j]))
					answer[i][j] = 0;
				else if(distance[i][j] > distance[i][k] + distance[k][j])
				{
					std::cout << -1;
					return 0;
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			sum += answer[i][j];
	}
	std::cout << sum;

	return 0;
}