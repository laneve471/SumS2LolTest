#include "Knight.h"
#include <iostream>
using namespace std;

// [��缭] �⺻�� Hp=100, Attack=10
Knight::Knight() : _hp(100), _attack(10)
{

}

Knight::Knight(int hp) : _hp(hp)
{

}

Knight::~Knight()
{

}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATK: " << _attack << endl;
}