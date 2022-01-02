#pragma once
#include <Windows.h>

class Vars {
public:
	bool noCountdown = false;
	bool drawLine = false;
	bool bShowMenu = false;
	bool alwaysVisible = false;
	bool fullEXP = false;
	bool dmKillMultiplier = false;

	UINT menuKey = VK_INSERT;
	app::GameState__Enum gameState;
	app::PlayerEntity* localPlayer;

	struct Players {
		int count;
		struct app::PlayerEntity* allPlayers[32];
	}players;

	void updateVars(app::NewGameController* newGameController);
	void updatePlayers();
};

extern Vars vars;