#include <string>
#include <vector>

using namespace std;

char getChar(int n, int number)
{
	char retVal = number % n;
	if (retVal >= 10)
		retVal += 55;
	else
		retVal += '0';
	return retVal;
}

string makeN(int n, int number)
{
	string str = "";
	str.push_back(getChar(n, number));
	while (number >= n)
	{
		number /= n;
		str.push_back(getChar(n, number));

	}
	return str;
}

string solution(int n, int t, int m, int p) {
	p -= 1;
	int tubeCount = 0, loopCount = 0;
	int number = 0;
	string answer = "";

	while (tubeCount < t)
	{
		string str = makeN(n, number);
		number++;
		for (auto i = str.rbegin(); i != str.rend(); i++)
		{
			if (loopCount % m == p)
			{
				answer += *i;
				tubeCount++;
				if (tubeCount == t)
					break;
			}
			loopCount++;
		}
	}

	return answer;
}