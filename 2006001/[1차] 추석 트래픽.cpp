#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1s = 1000
// 1m = 60000
// 1h = 3600000
// 1d = 86400000

int solution(vector<string> lines) {
	
	// start time, end time
	// �ð� ���� ����		: �ʴ� int������ ��ȯ�Ѵ�.
	vector<pair<int, int>> timeLines;
	for (const auto& value : lines)
	{
		int hour = stoi(&value[11]);
		int minute = stoi(&value[14]);
		float tempSecond = stof(&value[17]);
		int second = static_cast<int>(roundf(tempSecond * 1000));
		float tempProcessTime = stof(&value[24]);
		int processTime = static_cast<int>(tempProcessTime * 1000);
		int endTime = second + (minute * 60000) + (hour * 3600000);
		int startTime = endTime - (processTime-1);

		timeLines.push_back(make_pair(startTime, endTime));
	}

	// �α״� �Ϸ�ð� ���� ������������ ���ĵǾ� �ִ�. = N+1��° �α׵��� ������ N���� �ʰ� ������.
	// N��° �α��� �Ϸ�ð� +1�� �ð����� N+i ��° �α��� ���۽ð��� �� ũ�ٸ� ó�� ������ ������ �ʴ� �α��̴�.
	int answer = 1;
	for (int i = 0; i < timeLines.size(); i++)
	{
		int Time = timeLines[i].second + 1000;
		int count = 1;
		for (int j = i + 1; j < timeLines.size(); j++)
		{
			if (timeLines[j].first < Time)
				count++;
		}
		answer = (count > answer) ? count : answer;
	}
	return answer;
}

void main()
{
	string str = "12";
	string str1 = "12.0";
	string str2 = "12.12";
	string str3 = "12.003";

	float f = stof(str);
	float f1 = stof(str1);
	float f2 = stof(str2);
	float f3 = stof(str3);

	int d = static_cast<int>(f * 1000);
	int d1 = static_cast<int>(f1 * 1000);
	int d2 = static_cast<int>(f2 * 1000);
	int d3 = static_cast<int>(f3 * 1000);

	cout << solution({ "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" });

}