#include <Novice.h>
#include<Player.h>
#include<Enemy.h>

const char kWindowTitle[] = "LC1B_29_1ヨシダアイリ";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	Enemy* enemy1 = new Enemy(100,100,4);
	Enemy* enemy2 = new Enemy(100, 300, 7);
	Player* player = new Player;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///


		enemy1->Update();
		enemy2->Update();
		player->Update(keys, preKeys);

		//敵と弾の当たり判定
		int Ax = enemy1->GetPos().x - player->Bullet_.GetPos().x;
		int Ay = enemy1->GetPos().y - player->Bullet_.GetPos().y;
		int Ag = Ax * Ax + Ay * Ay;
		int Ar = (enemy1->GetRadius() + player->Bullet_.GetRadius()) * (enemy1->GetRadius() + player->Bullet_.GetRadius());

		int Bx = enemy2->GetPos().x - player->Bullet_.GetPos().x;
		int By = enemy2->GetPos().y - player->Bullet_.GetPos().y;
		int Bg = Bx * Bx + By * By;
		int Br = (enemy2->GetRadius() + player->Bullet_.GetRadius()) * (enemy2->GetRadius() + player->Bullet_.GetRadius());


		if (Ar == Ag || Ar > Ag || Br == Bg || Br > Bg) //重なってる時と接しているとき
		{
			enemy1->isLive_ = FALSE;
		}

		if (keys[DIK_R])
		{
			enemy1->isLive_ = TRUE;
		}


		///
		/// ↓描画処理ここから
		///

		enemy1->Draw();
		enemy2->Draw();
		player->Draw();


		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemy1->isLive_);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemy2->isLive_);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respaen : R");


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
