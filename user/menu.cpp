#include "pch-il2cpp.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include "vars.h"
#include "memory.h"
#include "menu.h"
#include "functions.h"

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

	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void Menu::Main() {

	if (vars.noCountdown)
		ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);

	if (ImGui::Button("No Countdown"))
		functions.NoCountdown();

	if (vars.noCountdown)
		ImGui::PopStyleVar();

	ImGui::Checkbox("Always Visible", &vars.alwaysVisible);
	ImGui::Checkbox("Full EXP", &vars.fullEXP);
	ImGui::Checkbox("Draw Line", &vars.drawLine);
	if (ImGui::Button("Start")) {
		vars.updateVars();
	}
}

void Menu::DrawList() {

}