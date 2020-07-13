/*
	[����] 10159 ����
		���� ��ó : https://www.acmicpc.net/problem/10159

	[Ǯ�� ���]
		1. �� ����� �� �� �ִ� �׷��� DEQUE�� �����Ѵ�.
		1-1. ���� i�� �ڽŰ� �� ����� �� �� �ִ� ��ȣ���� set���� �����Ѵ�.
		2. A B�� �Է¹޾��� �� VEC.back()�� A�� �׷��� �ִ��� Ȯ���Ѵ�. 
			-> �ִ� : VEC.push_back(B)
			-> ���� : VEC.front()�� B�� �׷��� ã�´�.
				-> �ִ� : VEC.push_front(A)
				-> ���� : VEC.push_back(A), VEC.push_back(B)
		3. ���ο� ���� �߰��� VEC�� ����鿡 ���ο� ���� ON �Ǿ����� �˸���.
		-> 1 4 , 1 7 �� �� 2���� ���� ������ ��������ϱ� ������ �� ����� ���� ����.

	[Ǯ�� ���] : �÷��̵� �ͼ� �˰���
*/

#include <iostream>
#include <vector>

const int INF = 214748367;
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> vec(N + 1, std::vector<int>(N + 1, INF));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			if (i == j) vec[i][j] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int A, B;
		std::cin >> A >> B;
		vec[A][B] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (vec[j][k] > vec[j][i] + vec[i][k]) {
					vec[j][k] = vec[j][i] + vec[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int count = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (vec[i][j] == INF && vec[j][i] == INF) {
				count++;
			}
		}
		std::cout << count << '\n';
	}
	return 0;
}