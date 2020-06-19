/*
	[����] 1516. ���� ����
	���� ��ó : https://www.acmicpc.net/problem/1516
	Ǯ�� : 2020.06.19
	��� : sloved.
*/

/*
	[Ǯ�� ���] - BFS �˰����� �̿�
	1. i��° ��带 ���Գ��� ���� ������ vector�� ����
		ex ) 1�� ��带 ���Գ��� ���� ���� 2,3,4,6		=>		vector[i]. {2, 3, 4, 6}
	2. queue�� ���Գ�尡 ���� ���� ���� (��庰 refCount�� ���Գ�� ī����)
	3. answer[i]�� value (time)�� ����	=> ���Գ�� �ð� (answer[i]) + ������ �ð�
	4. ���� ����� ���� ���� ����� �� ���� ������� answer[i] = ���� ����� ��
		- ���� �������� �ϴ� �ǹ��� ��� �Ǽ��Ǿ�� i��° �ǹ��� �Ǽ��� �� �ִ�. 
		- 3�� �ǹ��� ���� ���� 1,2�� �ǹ��� ������Ѵٸ�, 1�� �ϼ��ð� 10�� / 2�� �ϼ��ð� 20�� ��� 3�� �ǹ��� 20�ʺ��� �Ǽ��� �� �ִ�.

	[�ı�]
		ó���� DFS�� �̿��ؼ� Ǯ �� ������ ����Ŭ (�ߺ� ���) ó���� �ָ������� BFS�� �����ߴ�.
*/

#include <iostream>
#include <vector>
#include <queue>

struct pathData
{
	int value = 0;
	std::vector<int> paths;
	int refCount = 0;
};

std::vector<std::pair<int, pathData>> list;
std::vector<int> answer;

void bfs()
{
	std::queue<int> queue;

	for (int i = 1; i < list.size(); i++)
	{
		if (list[i].second.refCount == 0)
		{
			queue.push(i);
			answer[i] = list[i].second.value;
		}
	}

	while (!queue.empty())
	{
		auto front = queue.front();
		queue.pop();
		int value = answer[front];
		
		for (const auto i : list[front].second.paths)
		{
			int newValue = value + list[i].second.value;
			if (answer[i] < newValue)
			{
				queue.push(i);
				answer[i] = newValue;
					
			}
		}
	}
}

int main()
{
	// input�� ��� ��ġ�� 1���� �����̹Ƿ� N+1 ����.
	int N;
	std::cin >> N;
	list.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int input;
		std::cin >> input;
		
		list[i].second.value = input;
		while (std::cin >> input)
		{
			if (input == -1)
				break;
			list[input].second.paths.push_back(i);
			list[i].second.refCount++;
		}
	}

	answer.resize(N + 1);
	bfs();

	for (int i=1;i<=N;i++)
		std::cout << answer[i] << '\n';
	return 0;
}