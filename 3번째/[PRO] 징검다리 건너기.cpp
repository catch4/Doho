/*
	[프로그래머스] 징검다리 건너기
	문제 출처 : https://programmers.co.kr/learn/courses/30/lessons/64062#
*/

/*
	[풀이 방법]
		1. multiset의 값을 k만큼 유지하면서 multiset의 최댓값을 찾는다.
		2. 최댓값들 중 최솟값을 찾는다 -> 정답
			- multiset의 최댓값은 징검다리들의 k구간에서 최대로 건널 수 있는 친구들이 최댓값 명이다.

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int count = 0, retVal = 0, popPos=0;

	multiset<int> queue;


	for (count; count < k; count++)
		queue.insert(stones[count]);
	
	answer = *(queue.rbegin());

	for (count; count < stones.size(); count++, popPos++)
	{
		queue.erase(queue.find(stones[popPos]));
		queue.insert(stones[count]);
		retVal =*(queue.rbegin());
		answer = (answer > retVal) ? retVal : answer;
	}
	
	return answer;
}

int main()
{
//	cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3) << endl;
//	cout << solution({ 5,2,1,2,2 }, 4) << endl;
//	cout << solution({ 100 }, 1) << endl;
	cout << solution({ 2,2,2 }, 2) << endl;

	return 1;
}