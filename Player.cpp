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
	//�ړ�����
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

	//���ˏ���
	if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0 && Bullet_.GetShot() == FALSE)
	{
		Bullet_.SetShot(TRUE);
		//�e�̈ʒu���v���C���[�̈ʒu�Ɏ����Ă���
		Bullet_.SetPos(pos_.x, pos_.y);
	}
	//�e�̍X�V����
	Bullet_.Update();
	
}

void Player::Draw()
{
	//�e�̕`��
	Bullet_.Draw();

	//�v���C���[�̕`��
	Novice::DrawEllipse
	(
		pos_.x, pos_.y,
		radius_, radius_,
		0.0f, GREEN, kFillModeSolid
	);
}

