#include "pch-il2cpp.h"
#include "vars.h"

Vars vars;

void Vars::updateVars() {
	vars.localPlayer = app::MonoSingleton_1_NewGameController__get_Instance(*app::MonoSingleton_1_NewGameController__get_Instance__MethodInfo)->fields.localPlayer;
}