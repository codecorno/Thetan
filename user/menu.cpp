#pragma once
#include "menu.h"
#include "functions.h"
#include "custom.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include "pch-il2cpp.h"

using namespace app;

void Menu::renderMainMenu() {
	ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoCollapse);

	if (ImGui::Button("No Countdown"))
		Functions::noCountdownFunction();


	if (ImGui::Button("Hmmmmmmmmmmm")) {
		if (Custom::GetClientState() == app::ClientState__Enum::Joined) {
			auto b = MonoSingleton_1_NewGameController__get_Instance(*MonoSingleton_1_NewGameController__get_Instance__MethodInfo);
			auto* playerVector = (CharacterView_GetListPlayerEntity(NULL));

			for (int i = 0; i < List_1_PlayerEntity__get_Count(playerVector, NULL); i++) {
				PlayerEntity* player = List_1_PlayerEntity__get_Item(playerVector, i, NULL);
			}
		}
	}
	ImGui::End();
}