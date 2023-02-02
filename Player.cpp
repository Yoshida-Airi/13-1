#include "Player.h"
#include"Novice.h"

Player::Player()
{
	pos_.x = 400;
	pos_.y = 500;
	speed_ = 6;
	radius_ = 32;

	Player* player;

}

void Player::Update(char* keys, char* preKeys)
{
	//移動処理
	if (keys[DIK_W] || keys[DIK_UP])
	{
		pos_.y -= speed_;
	}
	if (keys[DIK_S] || keys[DIK_DOWN])
	{
		pos_.y += speed_;
	}
	if (keys[DIK_A] || keys[DIK_LEFT])
	{
		pos_.x -= speed_;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT])
	{
		pos_.x += speed_;
	}

	//発射処理
	if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0 && Bullet_.GetShot() == FALSE)
	{
		Bullet_.SetShot(TRUE);
		//弾の位置をプレイヤーの位置に持ってくる
		Bullet_.SetPos(pos_.x, pos_.y);
	}
	//弾の更新処理
	Bullet_.Update();
	
}

void Player::Draw()
{
	//弾の描画
	Bullet_.Draw();

	//プレイヤーの描画
	Novice::DrawEllipse
	(
		pos_.x, pos_.y,
		radius_, radius_,
		0.0f, GREEN, kFillModeSolid
	);
}

