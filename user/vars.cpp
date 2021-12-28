#include "pch-il2cpp.h"
#include "vars.h"
#include "custom.h"

Vars vars;

void Vars::updateVars() {
	if (Custom::GetClientState() != app::ClientState__Enum::Joined)
		return;

	auto instancia = app::MonoSingleton_1_NewGameController__get_Instance(*app::MonoSingleton_1_NewGameController__get_Instance__MethodInfo);
	vars.localPlayer = instancia->fields.localPlayer;

	vars.players.count = app::List_1_PlayerEntity__get_Count((app::CharacterView_GetListPlayerEntity(NULL)), NULL);

	for (int i = 0; i < vars.players.count; i++) {
		vars.players.allPlayers[i] = app::List_1_PlayerEntity__get_Item((app::CharacterView_GetListPlayerEntity(NULL)), i, NULL);
	}
}