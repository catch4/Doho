/*
	[����] 1328 ���� ����
		���� ��ó : https://www.acmicpc.net/problem/1328

	[Ǯ�� ���]
		Ǯ�� ���� : https://ksj14.tistory.com/entry/BackJoon1328-%EA%B3%A0%EC%B8%B5-%EB%B9%8C%EB%94%A9
		��ȭ�� : dp[n][l][r] = dp[n - 1][l][r] * (n - 2) + dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1]

		dp[1][1][1] = dp[2][2][1] = dp[2][1][2] = 1
		dp[n][1][n] = dp[n][n][1] = 1	-> 123, 321 �̷� ���
		N : 3���� N����, L,R�� 1���� L,R����

		dp�� �ڷ����� long long���� �ؾ��Ѵ�.
		1000000007�� ������ ������ ����� �����Ѵٰ� int�� �� ���� ������.
		dp[n][l][r]�� ���� ����� �� ������ ����ȯ���� int�� ��� ����� ���ϵǱ� �����̴�.
*/

#include <iostream>

long long dp[101][101][101];

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, L, R;
	std::cin >> N >> L >> R;

	dp[1][1][1] = dp[2][2][1] = dp[2][1][2] = 1;

	for (int n = 3; n <= N; n++)
	{
		dp[n][n][1] = dp[n][1][n] = 1;
		for (int l = 1; l <= L; l++)
		{
			for (int r = 1; r <= R; r++)
			{
				long long temp=0;
				temp = ((dp[n - 1][l][r] * (n - 2)) + dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1]);
				dp[n][l][r] = temp % 1000000007;
			}
		}
	}
	std::cout << dp[N][L][R];
}