#pragma once
class Barrel;
class Ball;

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	//void PostInitialize(); // ��ó������?

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire();

	shared_ptr<CircleCollider> GetCollider() { return _body; }

private:
	shared_ptr<CircleCollider>	_body;

	float _delay = 0.0f;
	const float _attackSpeed = 3.0f;

	// ������Ʈ ����
	// 1. �ڵ��� ���뼺
	// 2. ����Ƽ �ٽɿ��, �𸮾� �߿���(���, ������Ʈ)
	shared_ptr<Barrel>			_barrel;

	// ������Ʈ Ǯ��(������?�� ����� ��)
	// �����Ҵ� Ŀ��?
	// �Ҵ� - ������ �ּ�ȭ �ϱ� ���ؼ�
	// => �̸� �������� ���߿� �� ���� ���� �� ����� ��
	UINT						_poolCount;
	vector<shared_ptr<Ball>>	_balls;
	Vector						_ballDir;
	float						_theta;

	float						_speed;	
	Vector						_gravity = Vector(0, 1);
};
