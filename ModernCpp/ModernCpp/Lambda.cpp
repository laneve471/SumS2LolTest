#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

class Pet
{
public:
	int _atk;
};
class Player
{
public:
	int _hp = 0;
	int _atk = 0;

	Pet* _pet = 0;
};

struct SortComparer
{
	bool operator()(Player* p1, Player* p2)
	{
		return p1->_pet->_atk > p2->_pet->_atk;
	}
};

bool ComparePetAtk(Player* p1, Player* p2)
{
	return p1->_pet->_atk > p2->_pet->_atk;
}

int main()
{
#pragma region �ǽ�
	vector<Player*> players;

	for (int i = 0; i < 10; i++)
	{
		// ���� : �����Լ�
		Player* p = new Player();
		p->_pet = new Pet();
		p->_pet->_atk = rand() % 50;

		players.push_back(p);
	}

	// players �迭�� ������ �ǵ� player �� ���� �����ִ� pet�� �������� ���� players�� �����϶�
	// std::sort(players.begin(), players.end(), &ComparePetAtk); => �Լ�������
	// std::sort(players.begin(), players.end(), SortComparer()); => �Լ� ��ü
#pragma endregion

	vector<int> v = { 1,25,6,23,4,5 };

	int compareNum = 20;
	// ���ٽ�
	// [ĸ��](�Ű�����)-> (��ȯ ����) { �Լ� ���Ǻ� }
	// 20���� ū ���� ����
	int c = std::count_if(v.begin(), v.end(), [&compareNum](const int& element) -> bool
		{
			if (element > compareNum)
				return true;
			return false;
		});

	std::cout << c << endl;

	// 25���� ū ���� ����
	compareNum = 25;
	c = std::count_if(v.begin(), v.end(), [&compareNum](const int& element) -> bool
		{
			if (element > compareNum)
				return true;
			return false;
		});

	std::cout << c << endl;

	//std::for_each()
	std::for_each(v.begin(), v.end(), [](const int& element) -> void { std::cout << "Hello World!" << endl; });

	auto func = []() {};
	// �Լ� ������, (�Լ� ��ü, ����) Callable ��ü
	// Callable ��ü�� �Ű������� �ѱ�� ���� '�ݹ��Լ�' => Delegate
	function<void(void)> fn; // fn�� �Լ� ������, �Լ� ��ü, ����
	fn = []() {};
	
	std::sort(players.begin(), players.end(), [](Player* left, Player* right)-> bool
		{
			if (left->_pet->_atk < right->_pet->_atk)
				return true;
			return false;
		});

	// delete p->_pet;
	// delete p;
	return 0;
}