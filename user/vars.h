#pragma once
#include <Windows.h>

class Vars {
public:
	bool noCountdown = false;
	bool bShowMenu = false;
	UINT menuKey = VK_INSERT;
	app::PlayerEntity* localPlayer;
	struct app::PlayerEntity* allPlayers[32];
	void updateVars();
};

extern Vars vars;