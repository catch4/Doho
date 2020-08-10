#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool isFind(deque<string>& caches, const string str)
{
	for (auto i = caches.begin(); i != caches.end(); i++)
	{
		if (*i != str) continue;
		caches.erase(i);
		caches.push_front(str);
		return true;
	}
	return false;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	if (cacheSize == 0)
		return 5 * cities.size();
	deque<string> caches;
	for (const auto& i : cities)
	{
		transform(i.begin(), i.end(), i.begin(), [](unsigned char c) -> unsigned char {return toupper(c); });
		if (isFind(caches, i))
			answer += 1;
		else
		{
			if (caches.size() < cacheSize)
				caches.push_front(i);
			else
			{
				caches.pop_back();
				caches.push_front(i);
			}
			answer += 5;
		}
	}

	return answer;
}

int main()
{

	return 0;
}