#include <iostream>
#include <vector>

using namespace std;

struct Player
{
	int hp;
	int atk;
};

void PrintPlayerHp(Player* arr[], int size); // ���Ұ� �÷��̾� ������
//void PrintPlayerHp(Player** arr, int size);

int main()
{
	Player* arr[5];

	for (int i = 0; i < 5; i++)
	{
		arr[i] = new Player();
	}

	vector<vector<int>> v;

	return 0;
}