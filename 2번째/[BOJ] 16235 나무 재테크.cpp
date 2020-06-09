#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

struct treeData
{
	int age;
	int x;
	int y;
};

auto cmp = [](treeData& a, treeData& b) -> bool {return a.age < b.age; };

typedef std::deque<treeData> treeVec;		// vector���� deque�� �޸� �ʱ� �޸� ��뷮�� ������ �������� �߰�,������ vector���� ������.

int yPos[8] = { -1,-1,-1,0,0,1,1,1 };
int xPos[8] = { -1,0,1,-1,1,-1,0,1 };

int N, M, K;

/*
push������ �ϴ� ���� ���� (������ ���� x�� ����)
trees : 5 5
		��	(����)
trees : 1 1 1 5 5 (����)
		�� (�� * 4)
trees : 5 5 5 9 9 : push_front(1)
		�� (����)
trees : 1 1 1 5 5 5 9 9 (����)
*/

void mealTime(std::vector<std::vector<int>>& meals, treeVec& trees)
{
	std::deque<treeData> liveTrees, deadTrees;

	// ���� ��� �Ա�
	for (auto& tree : trees)
	{
		if (meals[tree.y][tree.x] >= tree.age)
		{
			meals[tree.y][tree.x] -= tree.age;
			tree.age += 1;
			liveTrees.push_back(tree);	// ���� ���� ������ �ڷ� �´�.
		}
		else
			deadTrees.push_back(tree);
	}

	trees.swap(liveTrees);

	// ���� ���� ���̸�ŭ ��� �߰�
	for (const auto tree : deadTrees)
		meals[tree.y][tree.x] += (tree.age / 2);
}

void breeding(treeVec& trees)
{
	treeVec temp(trees);
	int endIndex = trees.size();
	for (int i = 0; i<endIndex; i++)
	{
		if (trees[i].age % 5 != 0)
			continue;

		for (int j = 0; j < 8; j++)
		{
			int newX = trees[i].x + xPos[j];
			int newY = trees[i].y + yPos[j];
			if (newX >= 0 && newX < N && newY >= 0 && newY < N)
				temp.push_front({ 1,newX,newY });	// push_front ���ֹǷν� ������ ���ص� �տ��� � �������� �´�.
		}
	}

	trees.swap(temp);
}

void addMeal(const std::vector<std::vector<int>>& addValue, std::vector<std::vector<int>>& foods)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			foods[i][j] += addValue[i][j];
	}
}

int main()
{
	std::cin >> N >> M >> K;
	std::vector<std::vector<int>>meals(N, std::vector<int>(N, 5));	// ���� ������ ���
	std::vector<std::vector<int>>addData(N, std::vector<int>(N));	// A�迭

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cin >> addData[i][j];
	}

	treeVec trees;
	for (int i = 0; i < M; i++)
	{
		treeData data;
		std::cin >> data.y >> data.x >> data.age;		//  ��������. x,y�� ���������� x��ǥ, y��ǥ�� �ƴϴ�.
		data.x -= 1;
		data.y -= 1;
		trees.push_back(data);
	}

	for (int years = 0; years < K; years++)
	{
		mealTime(meals, trees);
		breeding(trees);
		addMeal(addData, meals);
	}

	std::cout << trees.size();
	return 0;
}

/*
5 2 7
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3

answer : 71
*/

// deque��� vector & sort : �ð��ʰ�
//		- vector ���� deque�� insert, delete���� ������. ������ �ʱ� �޸� �ʿ䷮�� ����. 
// priority_queue : �ð��ʰ�