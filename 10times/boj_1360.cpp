/*
	[����] 1360 �ǵ�����
		���� ��ó : https://www.acmicpc.net/problem/1360

	[Ǯ�� ���] ����
		1. vector�� �ð� ������� ���ڿ��� ���¿� �ð����� push�Ѵ�.
			type -> vector.back().string + ���ڿ�
			undo -> time - t �� �ð����� ���� ���� �� �ִ밪�� ���ڿ�.

	[���� ����]
		???? ���� ������ ���� ®�� ���ε� ����� �ƴ�...?
			-> ��û�ߴ�... vector.size() == 0 || destTime < 0 �϶� continue�ߴµ�, vector�� undo push���� �����Ǿ���ȴ�.
*/

#include <iostream>
#include <vector>
#include <string>

struct node {
	int time;
	std::string str;
};

int main()
{
	int N;
	std::cin >> N;
	std::vector<node> sequences;

	while(N--)
	{
		std::string type, code;
		int time;
		std::cin >> type >> code >> time;
		if (type == "type")
		{
			if (sequences.empty())
				sequences.push_back({ time,code });
			else
				sequences.push_back({time, sequences.back().str + code });			
		}
		else
		{
			std::string newString;
			int destTime = time - stoi(code);
			for (const auto j : sequences)
			{
				if (j.time >= destTime)
					break;
				newString = j.str;
			}
			sequences.push_back({ time,newString });
		}
	}
	std::cout << sequences.back().str;
	return 0;
}

// TEST CASE
/*
4
type a 1
type b 2
type c 3
undo 3 4
output : ab

*/