#include <iostream>
#include  <string>
#include <algorithm>

using namespace std;

int nameSize;

int changeChar(const string& name, string& str, const int index)
{
	int upCount = name[index] - 'A';
	int downCount = 'Z' + 1 - name[index];
	str[index] = name[index];
	return min(upCount, downCount);
}

int getIndex(const string& name, const string& str, const int nowPos, int* destPos)
{
	int leftCount =1, leftIndex = nowPos - 1, rightCount =1, rightIndex = nowPos + 1;
	if (leftIndex < 0)
		leftIndex += str.size();
	if (rightIndex >= str.size())
		rightIndex %= str.size();

	while (name[leftIndex] == 'A' && name[leftIndex] == str[leftIndex])
	{
		leftIndex--;
		leftCount++;
		if (leftIndex < 0)
			leftIndex += str.size();
	}
	while (name[rightIndex] == 'A'&& name[rightIndex] == str[rightIndex])
	{
		rightIndex++;
		rightCount++;
		if (rightIndex >= str.size())
			rightIndex %= str.size();
	}
	if (leftCount < rightCount)
	{
		*destPos = leftIndex;
		return leftCount;
	}
	else
	{
		*destPos = rightIndex;
		return rightCount;
	}
}

int solution(string name) {

	string str;
	
	for (int i = 0; i < name.size(); i++)
		str.push_back('A');
	
	int nowPos = 0, destPos = 0;
	int answer = 0;

	if (name[0] != 'A')
		answer += changeChar(name, str, 0);

	while (str != name)
	{
		answer += getIndex(name, str, nowPos,&destPos);
		answer += changeChar(name, str, destPos);
		nowPos = destPos;
	}

	return answer;
}

int main()
{
	cout << solution("AAAAAAAAAAAAAAAAAAAA")<<endl;
	cout << solution("JAZ") << endl;
	cout << solution("JEROEN") << endl;

	return 0;
}