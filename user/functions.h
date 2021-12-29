#pragma once
#include <Windows.h>

class Functions {
public:
	void AntiInvisible(app::PlayerEntity* player);
	void LoopPlayers();
	void FullEXP();
	void Setup();
	void NoCountdown();
};

extern Functions functions;