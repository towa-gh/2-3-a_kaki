#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"MovePlayer.h"
#include"Main.h"

MovePlayer moveplayer;
void MovePlayer::PlayerInit() {
	player.flg = TRUE;
	player.x = 320;
	player.y = 380;
	player.w = 60;
	player.h = 100;
	player.angle = 0.0;
	player.count = 0;
	player.speed = 5;
}
MovePlayer::MovePlayer() {
	PlayerInit();
	saigo = 0;

	//kasoku = 0.43f; // 加速

	////speed = 0;  // 速度

	//moobX = 0.0f; // 移動量	  

	//angle = 0;  // 範囲

	//cosT[360] = 0;  // 円範囲
}

void MovePlayer::PlayerControl(int a, int b)
{
	//DrawGraph(player.x, player.y, a, TRUE);

	//移動範囲
	//for (moob = 0; moob < 360; moob++) {
	//	//円周率
	//	cosT[moob] = (float)cos(moob * M_PI / 180);  //３６０度から１８０度の間の移動変更
	//}

	//angle = -1; //とりあえず角度を-1にしておく

	//左右移動
	if (player.flg == TRUE) {
		saigo = a;
		//左移動
		if (applegame.getNowKey() & PAD_INPUT_LEFT) {
			//angle = 180;
			saigo = b;
			DrawGraph(player.x, player.y, saigo, TRUE);
			player.x -= player.speed;
		}
		//右移動
		if (applegame.getNowKey() & PAD_INPUT_RIGHT) {
			//angle = 0;
			saigo = a;
			DrawGraph(player.x, player.y, saigo, TRUE);
			player.x += player.speed;
		}
		else
			DrawGraph(player.x, player.y, saigo, TRUE);
	}
	//	if (angle != -1) {//移動判断 angleの値が変わっていたら移動量を変更する
	//		moobX += cosT[angle + 1] * kasoku;
	//	}
	//	if (angle == -1) {   //angleの値が変わっていたら移動量を変更する
	//		moobX -= cosT[angle - 1] * kasoku;
	//	}
	//	player.x += moobX;
	//}

	//プレイヤーの表示
	//左右移動

	//画面をはみ出さないようにする
	if (player.x < -30)  player.x = -30;
	if (player.x > applegame.getSCREEN_WIDTH() - 90)  player.x = applegame.getSCREEN_WIDTH() - 90;
}