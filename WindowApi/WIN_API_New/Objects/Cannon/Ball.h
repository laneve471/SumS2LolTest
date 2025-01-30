#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _circle->SetCenter(pos); } // ¿ßƒ°∫§
	Vector GetPos() { return _circle->GetCenter(); }
	void AddForce(Vector v); // πÊ«‚∫§

	bool isActive = false;

private:
	shared_ptr<CircleCollider> _circle;

	float _ballSpeed = 3;

	Vector _ballDir;
	Vector _gravity = Vector(0, 1.0f);
};

