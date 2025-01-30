#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	: Collider(center), _radius(radius) {}

CircleCollider::~CircleCollider() {}

void CircleCollider::Update()
{
	//_center = LERP(_center, mousePos, 0.1f);
}

void CircleCollider::Render(HDC hdc)
{
	//float left = _center.x - _radius
	// 가로세로 50 50인 사각형 그리기
	SelectObject(hdc, _pens[_curPen]);

	Ellipse(hdc, _center.x - _radius, _center.y - _radius, _center.x + _radius, _center.y + _radius);
}

bool CircleCollider::IsCollision(const Vector& pos)
{
	Vector circleCenter = GetCenter();
	Vector direction = pos - circleCenter;

	return direction.Length() < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<Collider> other)
{
	shared_ptr<CircleCollider> otherCircle = dynamic_pointer_cast<CircleCollider>(other);

	if (otherCircle)
	{
		Vector dir = otherCircle->GetCenter() - GetCenter();
		return dir.Length() < _radius + otherCircle->_radius;
	}

	shared_ptr<RectCollider> otherRect = dynamic_pointer_cast<RectCollider>(other);

	if (otherRect)
	{
		if (otherRect->IsCollision(shared_from_this()))
			return true;
		return false;
	}
}
//bool CircleCollider::IsCollision(shared_ptr<class RectCollider> rect)
//{
//	Vector rectCenter = rect->GetCenter();
//	Vector halfSize = rect->GetHalfSize();
//
//	if (_center.y > rect->Top() && _center.y < rect->Bottom()) {
//		if (_center.x < rect->Right() + _radius && _center.x > rect->Left() - _radius)
//			return true;
//	}
//	else if (_center.x < rect->Right() && _center.x > rect->Left()) {
//		if (_center.y > rect->Top() - _radius && _center.y < rect->Bottom() + _radius)
//			return true;
//	}
//	else {
//		if (IsCollision(rect->LeftTop()))
//			return true;
//		if (IsCollision(rect->RightTop()))
//			return true;
//		if (IsCollision(rect->LeftBottom()))
//			return true;
//		if (IsCollision(rect->RightBottom()))
//			return true;
//	}
//	
//
//	//if (rect->IsCollision(shared_from_this()))
//	//	return true;
//
//	return false;
//}