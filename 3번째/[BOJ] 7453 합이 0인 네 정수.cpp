/*
	[����] 7453. ���� 0�� �� ����
		���� ��ó : https://www.acmicpc.net/problem/7453
		Ǯ�� : 2020.06.16
		��� : sloved.
*/

/*
	[Ǯ�� ���] - DP
		1. AB/CD�� ���� vector�� ���� �� �����ؼ� �̺�Ž������ �� ����� 0�� ���� ã�´�.
		2. vector�ȿ� ���� ���� ������ ���� �� �����Ƿ� upper-lower�ؼ� ������ ã�´�.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	int a = 0, b = 0, c = 0, d = 0;

	vector<int> A, B, C, D;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	vector<int> AB, CD;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(CD.begin(), CD.end());

	long long answer = 0;
	for (int i = 0; i < AB.size(); i++)
	{
		int min = 0, max = CD.size() - 1, mid = 0;
		int value = AB[i] * -1;
		while (min <= max)
		{
			mid = (min + max) / 2;
			if (CD[mid] > value)
				max = mid - 1;
			else if (CD[mid] < value)
				min = mid + 1;
			else
			{
				auto lower = lower_bound(CD.begin(), CD.end(), value);
				auto upper = upper_bound(CD.begin(), CD.end(), value);

				answer+= upper - lower;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}