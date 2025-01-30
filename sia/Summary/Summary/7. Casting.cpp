#include <iostream>
#include <vector>

using namespace std;

//  ĳ���� : ����ȯ
// int -> char (uncomplete) cuz' bit size

// upcasting
// parent pointer -> son object

// downcasting
// parent object <- son pointer => uncomplete

// 1. static_cast : �������� ����Ǹ� ������
//  : ������ �߿� ���?
// 
// 2. dynamic case
//  : ��� �������� RTTI�� ������ ���
//  : RTTI = RunTime Type Information
//  : ���� �߿� ���?
//  : casting fail -> return nullptr
// 
// 3. const cast
//  : ��� -> ���� -> ���
// 
// 4. reinterpret_cast
//  : c-style 
class Player
{
public:
	// �����Լ��� �����ϸ� �����Լ� ���̺��� �����
	// ��ü�� �Ǿ� �ּҿ��� �����Լ����̺��� ����Ű�� �����Ͱ� ����� => ��Ÿ�ӿ� Ÿ���� �������� Ȯ���� �� �ִ�
	// RTTI
	virtual void Hello() { cout << "I'm player " << endl; }

	int _type;
	int _hp;
	int _atk;
};

class Knight : public Player
{
public:
	virtual void Hello() { cout << "I'm knight " << endl; }

	int _type = 1;
	int _stamina = 3;
};
int main()
{
	int aInt = static_cast<int>(1.0f); // 
	float aFloat = 1.0f;
	int* ptr = reinterpret_cast<int*>(&aFloat);
	aInt = 455555;
	char aChar = aInt;

	cout << aInt << endl;
	cout << *ptr << endl;

	Player* p = new Player();
	Player* k = new Knight(); // upcasting

	Knight* k2 = static_cast<Knight*>(new Player()); // c-style casting

	if (k->_type == 1) // dynamic cast�� ��ǻ� ����
	{
		static_cast<Knight*>(k);
	}

	k2->_stamina = 5; //memory contaminum

	//((Knight*)k)->Hello();

	Knight* dynamicK = dynamic_cast<Knight*>(k);
	if (dynamicK != nullptr)
	{
		dynamicK->Hello();
	}
	else
	{

	}

	const char* str = "Hello"; // rodata
	char* str2 = const_cast<char*>(str);
	//str2[0] = 'K' -> rodata violation


	return 0;
}