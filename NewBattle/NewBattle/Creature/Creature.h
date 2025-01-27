#pragma once
class Creature
{
public:
	Creature(int hp, int atk);
	virtual ~Creature(); // �ڽ� Ŭ���� ��ü�� �θ� �����͸� ���� ������ �� �ڽ� Ŭ������ �Ҹ��ڵ� ȣ��

	virtual void Attack(Creature* other);
	virtual void TakeDamage(int amount, Creature* attacker);

	bool IsDead();

	// C# getset
	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

protected:
	int _hp;
	int _atk;
	string _name;
};