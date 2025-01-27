#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <string>

using namespace std;

struct RefCountBlock
{
	int refCount = 1;
};

template<typename T>
class Shared_ptr
{
public:
	Shared_ptr() = default;
	Shared_ptr(T* ptr)
		: _ptr(ptr)
	{
		_block = new RefCountBlock();
		cout << "RefCount : " << _block->refCount << endl;
	}
	Shared_ptr(const Shared_ptr<T>& other)
	{
		_ptr = other._ptr;
		_block = other._block; // �ٽ�

		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}
	}

	Shared_ptr(std::nullptr_t)
	{
		_block->refCount--;
		_ptr = nullptr;

		cout << "RefCount : " << _block->refCount << endl;
	}

	~Shared_ptr()
	{
		if (_ptr != nullptr)
		{
			_block->refCount--;
			cout << "RefCount : " << _block->refCount << endl;

			if (_block->refCount <= 0)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
	}

	Shared_ptr<T>& operator=(const Shared_ptr<T>& other)
	{
		_block->refCount--;
		_ptr = nullptr;

		cout << "RefCount : " << _block->refCount << endl;
	
		return *this;
	}

	T& operator*() { return *_ptr; }
	T* Get() { return _ptr; }

private:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};

class Player
{
public:
	Player() { cout << "Player�� ������" << endl; }
	~Player() { cout << "Player�� �Ҹ���" << endl; }

	void Attack()
	{
		//target->_hp -= _atk;
		if (target.expired() == false)
		{
			target.lock()->_hp -= _atk;
			cout << "Attack" << endl;
		}
	}

public:
	weak_ptr<Player> target;
	int _hp = 1;
	int _atk = 2;
};

//void PrintPlayer(const Player& p)
//{
//	cout << p._hp << endl;
//	cout << p._atk << endl;
//}

void PrintPlayer(Shared_ptr<Player> p)
{
	cout << (*p)._hp << endl;
	cout << (*p)._atk << endl;
}

int main()
{
	// ����������
	// - ������ Ƚ��
	// => shared_ptr�� �Ҹ��ڰ� ȣ��� �� �׳� ����� �� �ƴ϶�, ������ Ƚ���� 0ȸ�� �� ���� ���� �ִ� ������ ����
	shared_ptr<Player> myShared1 = make_shared<Player>();
	shared_ptr<Player> myShared2 = make_shared<Player>();

	//PrintPlayer(*myShared.Get());

	//(*myShared1).target = myShared2;
	//(*myShared2).target = myShared1;

	//(*myShared1).target = nullptr;
	//(*myShared2).target = nullptr;

	myShared1->target = myShared2;
	myShared2->target = myShared1;

	 
	// shared_ptr�� ��ȯ���� ����
	/*myShared1->target = nullptr;
	myShared2->target = nullptr;*/

	// weak_ptr
	// shared_ptr�� ��ȯ���� ������ �ذ���
	// - ���� target���� ���� ���� �� ���� => ��������� �ٸ� �����͸� ����Ű�� �ִ� ��

	// unique_ptr
	unique_ptr<Player> uPtr = make_unique<Player>();

	return 0;
	// Shared_ptr �Ҹ���
}