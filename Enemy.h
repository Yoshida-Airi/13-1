#pragma once
#include"struct.h"
class Enemy
{
public:
	Enemy(int x, int y, int speed);
	void Update();
	void Draw();
	~Enemy();

	static bool isLive_;

	Vector2 GetPos() { return pos_; };
	int GetSpeedX() { return speed_; };
	int GetRadius() { return radius_; };



private:
	
	Vector2 pos_;
	int speed_;
	int radius_;
};

