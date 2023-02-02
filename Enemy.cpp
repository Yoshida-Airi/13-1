#include "Enemy.h"
#include "Novice.h"

bool Enemy::isLive_ = TRUE;

Enemy::Enemy(int x, int y, int speed)
{
	pos_.x = x;
	pos_.y = y;
	speed_ = speed;
	radius_ = 16;
}

void Enemy::Update()
{
	pos_.x += speed_;
	if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280)
	{
		speed_ *= -1;
	}
}

void Enemy::Draw()
{
	if (isLive_ == TRUE)
	{
		Novice::DrawEllipse
		(
			pos_.x, pos_.y,
			radius_, radius_,
			0.0f, RED, kFillModeSolid
		);
	}
}

Enemy::~Enemy()
{

}

