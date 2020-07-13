/*
	[���α׷��ӽ�] 17677 ���� Ŭ�����͸�
		���� ��ó : https://programmers.co.kr/learn/courses/30/lessons/17677

	[Ǯ�� ���]
		1. �Ű������� ���� �� ���ڿ��� �빮�ڷ� �����Ѵ�.
		2. �Ű������� ���� ���ڿ��� �� ���ھ� ��� multiset�� �־��ش�.
			- set�� ����� ������ �������� ã�� �� �̺�Ž������ ������ ã�� ���ؼ� ���.
			- ���� �����̹Ƿ� �ߺ��� ����Ѵ� -> multiset���
		3. str1 ���� ������ ���� �� str2 ���� ������ �����ϰ� �ִ� ���Ҵ� �������̴�.
			- ���� �����̱� ������ �ߺ��� �ִ�. ���� str2�� �����Ѵٸ� str2���� �� ���Ҹ� �������ش�.
			- �̶� erase�� ����Ѵٸ� ���� Ű�� ���� �������� ���ҵ��� ���ÿ� ������� ��������.
		4. �������� ������ �������� ������ ������.
			- size()�Լ��� size_t �ڷ����̴�. �̴� 8����Ʈ int���� �����Ƿ� double����ȯ�� ���ش�.

*/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {

	multiset<string> str1Group, str2Group;

	transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) -> unsigned char {return toupper(c); });
	transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) -> unsigned char {return toupper(c); });
	for (int i = 0; i < (str1.size()-1); i++)
	{
		if (str1[i] >= 'A' && 'Z' >= str1[i] && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
		{
			str1Group.insert(str1.substr(i, 2));
		}
	}
	for (int i = 0; i < (str2.size() - 1); i++)
	{
		if (str2[i] >= 'A' && 'Z' >= str2[i] && str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')
		{
			str2Group.insert(str2.substr(i, 2));
		}
	}

	double answer = 1;
	if (str1Group.size() != 0 || str2Group.size() != 0)
	{
		multiset<string>  unionSection;
		multiset<string>  interSection;
		for (const auto& i : str1Group)
		{
			unionSection.insert(i);
			auto retval = str2Group.find(i);
			if (retval != str2Group.end())
			{
				interSection.insert(i);
				str2Group.erase(retval);
			}
		}
		for (const auto& i : str2Group)
			unionSection.insert(i);
		
		answer = (double)interSection.size() / (double)unionSection.size();
	}
	return answer * 65536;
}

int main()
{
	//cout << solution("FRANCE", "french");
	cout << solution("aa1+aa2", "AAAA12");
	return 0;
}