#pragma once
#include"BaseAP.h"
class MovePlayer : public BasePlayer {

private:
	////自機の初期値
	int saigo;
public:
	MovePlayer();
	void getPlayer();
	void PlayerControl(int a, int b);
};

extern MovePlayer moveplayer;