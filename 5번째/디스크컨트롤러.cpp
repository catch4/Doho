#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

auto comp = [](pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	int startTime = 0, Index = 0, processCount = 0;
	
	// jobs[index][0]�� ���ĵǾ� ���� �����Ƿ� ����
	sort(jobs.begin(), jobs.end());

	priority_queue<pair<int, int>,vector<pair<int,int>>,decltype(comp)> pq(comp);

	while (processCount < jobs.size())
	{
		// startTime ������ jobs[]�� prioirty_queue�� push : ó�� ������ �۾���
		for (; Index < jobs.size() && startTime >= jobs[Index][0]; Index++)
			pq.push(make_pair(jobs[Index][1], jobs[Index][0]));

		// �۾� ������ ���� ��� ���� ��û�� ģ�� ó�� 
		if (pq.empty())
		{
			if (Index >= jobs.size()) break;
			startTime = jobs[Index][0];
			continue;
		}

		startTime += pq.top().first;
		answer += startTime - pq.top().second;
		pq.pop();		
		processCount++;
	}
	return answer / processCount;
}

void main()
{
	cout << solution({ { 0,3 },{ 1,9 },{ 2,6 } }) << ' ';				// return 9 : ok
	cout << solution({ { 0,3 },{ 4,4 },{ 5,3 },{ 4,1 } }) << ' ';		// return 3 : ok
	cout << solution({ {0, 9},{0, 4},{0, 5},{0, 7},{0, 3} }) << ' ';	// return 13 : ok
	cout << solution({ { 0,3 },{ 1,9 },{ 500,6 } });						// return 6 : ok
}