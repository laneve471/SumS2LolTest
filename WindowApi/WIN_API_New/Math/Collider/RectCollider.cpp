#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
	: Collider(center), _halfSize(size * 0.5f) {}

RectCollider::~RectCollider() {}

void RectCollider::Update()
{
	//_center = LERP(_center, mousePos, 0.03f);
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);
	// ���μ��� 50 50�� �簢�� �׸���
	Rectangle(hdc, _center.x - _halfSize.x, _center.y - _halfSize.y, _center.x + _halfSize.x, _center.y + _halfSize.y);
}

// Rect ȸ�� ���Ѵٴ� ����
bool RectCollider::IsCollision(const Vector& pos)
{
	/*Vector rectCenter = GetCenter();
	float direction_x = pos.x - rectCenter.x;
	float direction_y = pos.y - rectCenter.y;

	if (abs(direction_x) < _halfSize.x && abs(direction_y) < _halfSize.y)
		return true;*/

	if (pos.x > Left() && pos.x < Right()) // x�� ����
		if (pos.y > Top() && pos.y < Bottom()) // y�� ����
			return true;

	return false;
}

bool RectCollider::IsCollision(shared_ptr<Collider> other)
{
	/*Vector rectCenter_1 = GetCenter();
	Vector rectCenter_2 = other->GetCenter();

	float direction_x = rectCenter_2.x - rectCenter_1.x;
	float direction_y = rectCenter_2.y - rectCenter_1.y;

	if (abs(direction_x) < _halfSize.x + other->_halfSize.x)
		if(abs(direction_y) < _halfSize.y + other->_halfSize.y)
			return true;*/

	shared_ptr<RectCollider> otherRect = dynamic_pointer_cast<RectCollider>(other);

	if (otherRect)
	{
		if (otherRect->Left() > Right())
			return false;
		if (otherRect->Right() < Left())
			return false;
		if (otherRect->Top() > Bottom())
			return false;
		if (otherRect->Bottom() < Top())
			return false;
		return true;
	}

	shared_ptr<CircleCollider> otherCircle = dynamic_pointer_cast<CircleCollider>(other);

	if (otherCircle)
	{
		Vector dir = otherCircle->GetCenter() - GetCenter();
		Vector rightV = Vector(1, 0);
		Vector upV = Vector(0, -1);

		// ���� ó��
		float length = dir.Length();
		float rectHalfLength = _halfSize.Length();
		float circleRadius = otherCircle->GetRadius();

		if (length > rectHalfLength + circleRadius)
			return false;

		// x�� ����
		float lengthX = abs(rightV.Dot(dir));
		if (lengthX > _halfSize.x + circleRadius)
			return false;

		// y�� ����
		float lengthY = abs(upV.Dot(dir));
		if (lengthY > _halfSize.y + circleRadius)
			return false;

		return true;
	}
}
//bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
//{
//	/*
//	Vector circleCenter = circle->GetCenter();
//	float radius = circle->GetRadius();
//
//	if (circleCenter.y > Top() && circleCenter.y < Bottom()) {
//		//if ((_center - circleCenter).Length() < _halfSize.x + radius)
//		if (circleCenter.x < Right() + radius && circleCenter.x > Left() - radius)
//			return true;
//	}
//	else if (circleCenter.x < Right() && circleCenter.x > Left()) {
//		//if ((_center - circleCenter).Length() < _halfSize.y + radius)
//		if (circleCenter.y > Top() - radius && circleCenter.y < Bottom() + radius)
//			return true;
//	}
//	else {
//		if (circle->IsCollision(LeftTop()))
//			return true;
//		if (circle->IsCollision(RightTop()))
//			return true;
//		if (circle->IsCollision(LeftBottom()))
//			return true;
//		if (circle->IsCollision(RightBottom()))
//			return true;
//	}
//
//	// TODO : �� �簢�� �浹 ����
//	return false;
//    */
//	// ������� �ڷ���, �Ű�����
//	// 1. ���� ����
//	// 2. ���� ����
//
//	Vector dir = circle->GetCenter() - GetCenter();
//	Vector rightV = Vector(1, 0);
//	Vector upV = Vector(0, -1);
//
//	// ���� ó��
//	float length = dir.Length();
//	float rectHalfLength = _halfSize.Length();
//	float circleRadius = circle->GetRadius();
//
//	if (length > rectHalfLength + circleRadius)
//		return false;
//
//	// x�� ����
//	float lengthX = abs(rightV.Dot(dir));
//	if (lengthX > _halfSize.x + circleRadius)
//		return false;
//
//	// y�� ����
//	float lengthY = abs(upV.Dot(dir));
//	if (lengthY > _halfSize.y + circleRadius)
//		return false;
//
//	return true;
//}