#include "pch-il2cpp.h"
#include "vars.h"
#include "custom.h"
#include "functions.h"
#include "memory.h"

Functions functions;

void Functions::AntiInvisible(app::PlayerEntity* player) {
	app::PlayerEntity_OnInvisibleAlphaUpdate(player, 1, NULL);
	app::PlayerEntity_OnInvisible(player, false, NULL);
}

void Functions::FullEXP() {
	app::PlayerEntity_OnAddExp(vars.localPlayer, 100, NULL);
}

void Functions::Setup() {

	if (vars.gameState != app::GameState__Enum::PLAYING)
		return;

	if (vars.fullEXP)
		this->FullEXP();

	if (!vars.alwaysVisible)
		return;

	this->LoopPlayers();
}

void Functions::LoopPlayers() {

	for (int i = 0; i < vars.players.count; i++) {
		if (vars.alwaysVisible)
			this->AntiInvisible(vars.players.allPlayers[i]);
		app::PlayerEntity_set_PositionSpawn(vars.players.allPlayers[i], vars.localPlayer->fields.MyPosition, NULL);
	}
}

void Functions::NoCountdown() {
	vars.noCountdown = true;
	WriteProcessMemory(memory.hProcess, (LPVOID)memory.NoCountdownAddr, memory.fiveBytesNOP, sizeof(memory.fiveBytesNOP), NULL);
}
