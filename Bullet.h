#pragma once
#include"struct.h"
class Bullet
{
public:
	Bullet();
	void Update();
	void Draw();

public:
	bool GetShot() { return isShot_; };
	void SetShot(bool isShot);

	Vector2 GetPos() { return pos_; };
	void SetPos(float  x, float y);

	int GetRadius() { return radius_; };
	
private:
	Vector2 pos_;
	int speed_;
	int radius_;
	bool isShot_;
};

