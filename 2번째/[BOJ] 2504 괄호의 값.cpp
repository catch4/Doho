#include <iostream>
#include <string>
#include <vector>

const char getDestChar(const char ch)
{
	switch (ch)
	{
	case '(':
		return ')';
	case '[':
		return']';
	default:
		return '-';
	}
}

int getValue(const char ch)
{
	switch (ch)
	{
	case '(':
		return 2;
	case '[':
		return 3;
	default:
		return 0;
	}
}

int cal(std::string& str )
{
	std::vector<int> values;	// 괄호의 값을 배열에 저장하고 문자열의 괄호 있던 자리를 배열의 인덱스로 교체해준다.
										// 처음엔 값을 바로 배열에 넣었지만 2^7 부터 signed char overflow발생.
										// 예시)		(()[[]])([]) -> (0[[]])([]) -> (0[1])([]) -> (0 2 )  -> 3([])
										//									  vec[0] : 2	  vec[1] : 3		vec[2] : 9		vec[3] = 22 (11*2)
	while (true)
	{
		int value = 0, startIndex = 0;
		char destChar = getDestChar(str[0]);
		if (destChar == '-')
			break;
		bool isFind = false;
		for (int i = 1; i < str.size(); i++)
		{
			if (destChar != str[i])
			{
				if (str[i] == '[' || str[i] == '(')
				{
					startIndex = i;
					value = 0;
					destChar = getDestChar(str[i]);
				}
				else if (str[i] != ')' && str[i] != ']')
					value += values[str[i]];
				else
					return 0;
			}
			else
			{
				int tempValue = getValue(str[startIndex]);
				if (value != 0) tempValue = value * tempValue;
				values.push_back(tempValue);
				str[startIndex] = values.size()-1;				// 괄호 자리에 배열 인덱스 삽입
				str.erase(startIndex + 1, (i - startIndex));	// 인덱스 삽입 후 여유공간 삭제 ) 같은 것.
				isFind = true;
				break;
			}
		}
		if (!isFind)
			return 0;
	}
	
	return (values.size() > 0) ? values.back() : 0;
}

int main()
{
	std::string str;
	std::cin >> str;

	int answer = 0;

	while (str.size() != 0)
	{
		// 괄호를 덩어리로 나눠서 계산한다
		// ex) (()[[]])([]) -> 1번 : (()[[]])  && 2번 : ([])
		int retval = cal(str);
		if (retval == 0)
		{
			answer = 0;
			break;
		}
		answer += retval;
		str.erase(str.begin());	// str.front에는 vec의 index값이 들어있다. 자세한 설명은 cal함수 참고.
	}

	std::cout << answer;
	return 0;
}

/*
testcase
(()[[]])([]) : 28
([)] : 0
(([)]) : 0
(()[[]])(([)]) : 0
(((((((((((((()))))))))))))) : 0
(())[[]]) : 0
*/