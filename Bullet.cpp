#include "Bullet.h"
#include"Novice.h"
Bullet::Bullet()
{
	pos_.x = 500;
	pos_.y = 400;
	radius_ = 32;
	speed_ = 10;
	isShot_= FALSE;
}

void Bullet::Update()
{
	if (isShot_ == TRUE)
	{
		pos_.y -= speed_;
	}

	if (pos_.y <= 0)
	{
		isShot_ = FALSE;
	}
}

void Bullet::Draw()
{
	if (isShot_ == TRUE)
	{
		Novice::DrawEllipse
		(
			pos_.x, pos_.y,
			radius_, radius_,
			0.0f, WHITE, kFillModeSolid
		);
	}
}

void Bullet::SetShot(bool isShot)
{
	isShot_ = isShot;
}

void Bullet::SetPos(float x, float y)
{
	pos_.x = x;
	pos_.y = y;
}
