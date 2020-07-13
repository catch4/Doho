/*
	[백준] 10159 저울
		문제 출처 : https://www.acmicpc.net/problem/10159

	[풀이 방법] : 실패
		1. 비교 결과를 알 수 있는 그룹을 DEQUE로 관리한다.
		1-1. 물건 i는 자신과 비교 결과를 알 수 있는 번호들을 set으로 관리한다.
		2. A B를 입력받았을 때 VEC.back()이 A인 그룹이 있는지 확인한다. 
			-> 있다 : VEC.push_back(B)
			-> 없다 : VEC.front()가 B인 그룹을 찾는다.
				-> 있다 : VEC.push_front(A)
				-> 없다 : VEC.push_back(A), VEC.push_back(B)
		3. 새로운 값이 추가된 VEC의 멤버들에 새로운 값이 ON 되었음을 알린다.
		-> 1 4 , 1 7 일 때 2가지 경우로 갈래가 뻗어나가야하기 때문에 위 방법은 옳지 않음.

	[풀이 방법] : 플로이드 와샬 알고리즘
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
