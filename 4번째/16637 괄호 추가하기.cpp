/*
	[����]	16637		��ȣ �߰��ϱ�
	���� ��ó : https://www.acmicpc.net/problem/16637

	[Ǯ�� ���] - ���� ����
		1. ��ȣ�� ���� ���
		2. ��ȣ�� �ִ� ���
		�� ������ dfs����
*/


#include <iostream>
#include <string>
#include <algorithm>

int answer = -2147483647;		// �ִ� ���� ������ ��찡 ����.
int N;
std::string str;

int cal(const int left, const int right, const char op)
{
	switch (op)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left*right;
	default:
		break;
	}
}

void dfs(int value, int index)
{
	if (index >= N-1)
	{
		answer = std::max(answer, value);
		return;
	}
	// ��ȣ ���� ���
	if(index+2 < N)
		dfs(cal(value, str[index + 2]-'0', str[index + 1]), index + 2);
	// ��ȣ �ִ� ���
	if(index+4 < N)
		dfs(cal(value, cal(str[index + 2]-'0', str[index + 4] - '0', str[index + 3]), str[index + 1]), index + 4);
}

int main()
{

	std::cin >> N;
	std::cin >> str;

	dfs(str[0]-'0', 0);
	std::cout << answer;
}
