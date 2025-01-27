#include "framework.h"
#include "Cannon.h"
#include "Barrel.h"
#include "Ball.h"

Cannon::Cannon()
{
	_speed = 10.0f;

	_body = make_shared<CircleCollider>(CENTER, 50);

	_barrel = make_shared<Barrel>(_body);
	
	_poolCount = 30;
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Ball> ball = make_shared<Ball>();
		_balls.push_back(ball);
	}
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	_body->Update();
	_barrel->Update();

	for (auto ball : _balls)
	{
		ball->Update();

		if (ball->isActive)
		{
			ball->AddForce(_ballDir * 3.0f);
			ball->AddForce(_gravity);
		}
	}
	
	// ball 움직임 구현
	// 발사 방향

	// 가속
	//_ballDir += _ballDir * 0.1f;
	
	// 중력가속도
	_gravity += _gravity * 0.0001f;
	
	// 진자 운동
	/*_theta += 0.05f;
	_ball->AddForce(Vector(0, 3 * sinf(_theta)));
	_ball->AddForce(Vector(1, 0));*/

	// 유도

	_delay += 0.1f;

	Fire();
	Move();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	
	for (auto ball : _balls)
	{
		ball->Render(hdc);
	}
}

void Cannon::Move()
{
	if (GetKeyState('A') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(-1, 0) * _speed);
	}
	if (GetKeyState('D') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(1, 0) * _speed);
	}
	if (GetKeyState('W') & 0x8000)
	{
		_barrel->SetAngle(_barrel->GetAngle() - 0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		_barrel->SetAngle(_barrel->GetAngle() + 0.1f);
	}
}

void Cannon::Fire()
{
	if (_delay < _attackSpeed)
		return;

	auto iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<Ball> ball)->bool 
		{
		if (ball->isActive == false)
			return true;
		return false;
		});
	
	if (iter == _balls.end()) return;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		(*iter)->SetPos(_barrel->GetMuzzle());
		_ballDir = _barrel->GetDir();
		(*iter)->isActive = true;
		
		_delay = 0.0f;
		_gravity = Vector(0, -1);

		// 진자운동하기 위한 용도
		_theta = 0.0f;
	}
}
