#include "pch-il2cpp.h"
#include "vars.h"
#include "custom.h"

Vars vars;

void Vars::updateVars(app::NewGameController* newGameController) {
	vars.gameState = newGameController->fields.gameState;
	if (vars.gameState != app::GameState__Enum::PLAYING)
		return;

	vars.localPlayer = newGameController->fields.localPlayer;
	this->updatePlayers();
}

void Vars::updatePlayers() {
	vars.players.count = app::List_1_PlayerEntity__get_Count((app::CharacterView_GetListPlayerEntity(NULL)), NULL);

	if (vars.players.count < 2)
		return;

	for (int i = 0; i < vars.players.count; i++) {
		vars.players.allPlayers[i] = app::List_1_PlayerEntity__get_Item((app::CharacterView_GetListPlayerEntity(NULL)), i, NULL);
	}
}