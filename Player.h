#pragma once
#include"struct.h"
#include"Bullet.h"
#include"Enemy.h"

class Player
{
private:
	Vector2 pos_;
	int speed_;
	int radius_;

public:
	Bullet Bullet_;
	Player();
	void Update(char* keys, char* preKeys);
	void Draw();



};



