#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int min;
std::vector<std::set<int>> vec;

void cal(const int N, const int number, const int count)
{
	// min ���� count�� ũ�� ���ǹ��� Ž���̴�.
	if (count > min || count > 7)	return;	

	/*
		- ��Ģ���� ����� ���� & 0�� ������ �ȵȴ�. 
			A. 0�� ���� �� �ִ� ��� : -, /
			B. ������ ���� �� �ִ� ��� : -

		- N�� i�� ����ϴ� ��� ���� ���
			A. �� ������ ������ �� i�� ������ �ȴ�. 
			B. �̹� ��Ģ������ ������ ���� �ߺ��ǹǷ� �����Ѵ�.
				1. (0,1), (1,0)�� �ߺ��̴�. ������ - �� / ������ ���ǰ� �ʿ��ϴ�. 
				2. (0,1)���� - ������ ������ ������ (1,0)�� - ����� ����.
				3. (0,1)���� / ������ ����� 0 �̶�� (1,0)�� / �������� ��ü�Ѵ�.
	*/
	for (int i = 0; i < (count + 1) / 2; i++)		
	{
		int j = count - (i + 1);			// ex) count 3�̰� i = 0�̸� 2�� ��Ģ������ �����ؾ��ϹǷ� 2�� ���Ѵ�.
		for (const auto value : vec[i])
		{
			for (const auto secondValue : vec[j])
			{
				vec[count].insert(value + secondValue);
				if(value - secondValue != 0)
					vec[count].insert(abs(value - secondValue));		
				vec[count].insert(value * secondValue);
				vec[count].insert((value > secondValue) ? value / secondValue : secondValue/value);				
			}
		}
	}

	if (vec[count].count(number) != 0)
		min = std::min(min, count);
}

int solution(int N, int number) {
	min = 8;			
	vec.resize(8);

	// N�� i+1�� ����ϴ� ��� ���
	int temp = N;
	for (int i = 0; i < 8; i++, temp = (temp*10)+N)
	{
		vec[i].insert(temp);		// N�� i+1�� ����ϴ� ��� ex) 5, 55, 555 ~
		cal(N, number, i);
	}

	return (min == 8) ? -1 : min+1;
}

/*
���� ����Ʈ : 
https://gurumee92.tistory.com/164

*/