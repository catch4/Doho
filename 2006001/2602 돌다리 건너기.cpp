#include <iostream>
#include <array>
#include <string>

std::string rolls;
std::array<std::string,2> bridges;
unsigned int caches[101][2][21];	// [bridges index] [bridges type] [rolls index]

int bridgeSize;

unsigned int dfs(int startIndex, int bridgeType, int rollsIndex)
{
	auto& ref = caches[startIndex-1][bridgeType][rollsIndex];

	if (ref != 0) return ref;
	
	if (rollsIndex >= rolls.size())				// ������ �η縶�� ������� �� �ǳ� ��� 
		return ref = 1;
	if (startIndex >= bridgeSize)				// ������ �η縶�� ������� �ǳ��� ���ߴµ� �ٸ��� ���� ���
		return ref = 0;

	unsigned int count = 0;
	for (int i = startIndex; i < bridgeSize; i++)
	{
		if (bridges[bridgeType][i] == rolls[rollsIndex])
			count += dfs(i + 1, (bridgeType + 1) % 2, rollsIndex + 1);
	}

	return ref = count;
}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	std::cin >> rolls;


	std::cin >> bridges[0];	// devil bridge
	std::cin >> bridges[1];	// engel bridge

	bridgeSize = bridges[0].size();

	std::cout << dfs(0,0,0) + dfs(0,1,0);

	return 0;
}

/*
2���� DP�� x ������?
*/