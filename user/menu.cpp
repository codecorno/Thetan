#include "pch-il2cpp.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_internal.h"
#include "vars.h"
#include "memory.h"
#include "menu.h"
#include "functions.h"
#include "custom.h"
#include "helpers.h"

Menu menu;

void Menu::Setup(){
	ImGui::CreateContext();

	ImGui_ImplWin32_NewFrame();
	ImGui_ImplDX11_NewFrame();

	ImGui::NewFrame();

	ImGui::GetStyle().AntiAliasedFill = true;
	ImGui::GetStyle().AntiAliasedLines = true;

	if (vars.bShowMenu)
	{

		ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoCollapse);
		this->Main();
		ImGui::End();
	}
	this->DrawList();
	ImGui::EndFrame();
	ImGui::Render();
}

void Menu::Main() {


	ImGui::BeginDisabled(vars.noCountdown);
	if (ImGui::Button("No Countdown"))
		functions.NoCountdown();
	ImGui::EndDisabled();
	ImGui::SameLine(); Custom::Tooltip("Removes skill cooldown *Cannot be turned off*");

	ImGui::Checkbox("Always Visible", &vars.alwaysVisible);
	ImGui::SameLine(); Custom::Tooltip("Enemies will not be invisible when hiding in tall grass");
	ImGui::Checkbox("EXP Boost", &vars.fullEXP);
	ImGui::SameLine(); Custom::Tooltip("Makes you gain EXP above normal");
	ImGui::Checkbox("DM Kill Multiplier", &vars.dmKillMultiplier);
	ImGui::SameLine(); Custom::Tooltip("Changes Deathmatch kill multiplier, you instantly win after 45 seconds.");
}
void Menu::DrawList() {
	//ImGui::Begin("##DrawList", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoInputs);
	for (int i = 0; i < vars.players.count; i++) {
		//Custom::RenderText("Texto Teste 001", { 0,0 }, 72, 0xffff0000);
		Custom::RenderLine({ Custom::WorldToScreen(vars.localPlayer->fields.MyPosition).x, Custom::WorldToScreen(vars.localPlayer->fields.MyPosition).y }, { Custom::WorldToScreen(vars.players.allPlayers[i]->fields.MyPosition).x, Custom::WorldToScreen(vars.players.allPlayers[i]->fields.MyPosition).y}, 0xffff0000);
	}
	//ImGui::End();
}