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

		ImGui::Begin("Root", nullptr, ImGuiWindowFlags_NoCollapse);
		this->Main();
		ImGui::End();
	}
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
	if (ImGui::Button("Bring Safezone"))
		SafezoneMarker_SetCurSafezonePosition(vars.safe.__this, vars.localPlayer->fields.MyPosition, NULL);
}
void Menu::DrawList() {

}