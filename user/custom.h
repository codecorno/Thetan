#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "../imgui/imgui.h"

using namespace app;

namespace Custom {
	app::Vector2 WorldToScreen(app::Vector3 position) noexcept;
	bool HookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName);
	bool UnhookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName);
	float RenderText(const std::string& text, const ImVec2& position, float size, uint32_t color, bool center = false);
	void RenderLine(ImVec2 from, ImVec2 to, uint32_t color, float thickness = 1.0f);
	void RenderCircle(const ImVec2& position, float radius, uint32_t color, float thickness = 1.0f, uint32_t segments = 16);
	void RenderCircleFilled(const ImVec2& position, float radius, uint32_t color, uint32_t segments = 16);
	void RenderRect(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All, float thickness = 1.0f);
	void RenderRectFilled(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All);
	void dNewGameController_Update(app::NewGameController* __this, MethodInfo* method);
	void dGameController_OnAddScore(app::GameController__Boxed* __this, app::Frame* f, app::TeamId__Enum teamId, int32_t Score, MethodInfo* method);
	void dTeamSuperStarWinByScoreGameData_GameLogicUpdate(TeamSuperStarWinByScoreGameData* __this, Frame* f, MethodInfo* method);
	void Tooltip(const char* desc);
};


