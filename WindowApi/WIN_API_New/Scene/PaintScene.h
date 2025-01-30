#pragma once
// �߻�Ŭ���� ����
class PaintScene : public Scene
{
public:
	PaintScene();
	~PaintScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	vector<HPEN>			_pens;
	vector<HBRUSH>			_brushes;

	shared_ptr<CircleCollider>			_circle;
	shared_ptr<RectCollider>			_rect;
};

