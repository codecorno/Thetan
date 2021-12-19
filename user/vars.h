#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include "pch-il2cpp.h"

using namespace app;

namespace Vars {
	DWORD64 GameAssembly = reinterpret_cast<DWORD64>(GetModuleHandleA("GameAssembly.dll"));
	DWORD64 NoCountdownAddr = GameAssembly + 0xB28CC6;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
	PlayerEntity* localPlayer;
};

void initializeVars() {
	Vars::localPlayer = MonoSingleton_1_NewGameController__get_Instance(*MonoSingleton_1_NewGameController__get_Instance__MethodInfo)->fields.localPlayer;
}