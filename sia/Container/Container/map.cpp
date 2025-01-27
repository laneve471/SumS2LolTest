#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

// unordered_map : �ؽ� ���̺�
// �ؽ� :
// ü�̴� :
// Key - Value�� ������ �� ���ҷ� �̷���� ǥ
// => �ؽ��� �̿��Ͽ� Ž���ð��� '���', ����, ���� (���)
// ==> Key������ Ž���� �����ϴ�
// ===> ����, ��Ŭ����Ƽ�� �ε���

// map: �ڰ���������Ž��Ʈ��, �����Ʈ�� 
// Key - Value�� ������ �� ���ҷ� �̷���� ����Ž��Ʈ��
// => ����Ž���� Ȱ���Ͽ� Ž��, ����, ���� �ð��� 'log N'
// ==> Key������ Ž���� �����ϴ�.
// ===> Database �⺻key
// 

class Player
{
public:
	Player() {}
	Player(int id) : _id(id) {}

	int _id;
};
int main()
{
	/*
	// Player�� ID�� �����ؼ� �ִ� �۾�
	vector<Player> players;

	for (int i = 0; i < 1000; i++)
	{
		players.push_back(i + 1);
	}

	// id�� 500�� �÷��̾ ã�� �ʹ�. 
	//players[499];
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]._id == 500)
		{
			// ã��
		}
	}
	*/ //=> vector�� ��� Ž�� �ð� : �ð� ���⵵(N)

	/*
	unordered_map<int, Player> um;

	for (int i = 0; i < 1000; i++)
	{
		um[i + 1] = Player(i);
		// pair<int, Player> pair = make_pair<int, Player>(i + 1, Player(i));
		// auto result = um.insert(pair);
	}
	*/

	map<int, Player> m;

	m.erase(1);

	for (int i = 0; i < 1000; i++)
	{
		m[i + 1] = Player(i);
		// pair<int, Player> pair = make_pair<int, Player>(i + 1, Player(i));
		// auto result = um.insert(pair);
	}

	map<int, Player>::iterator m_iter;

	for (m_iter = m.begin(); m_iter != m.end(); m_iter++)
	{
		pair<int, Player> p = *m_iter;
		cout << p.first << endl;
	}
	return 0;
}