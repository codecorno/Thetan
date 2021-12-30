#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "../imgui/imgui.h"

namespace Custom {
	app::Vector3 WorldToScreen(app::Vector3 position) noexcept;
	bool HookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName);
	bool UnhookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName);
	float RenderText(const std::string& text, const ImVec2& position, float size, uint32_t color, bool center = false);
	void RenderLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);
	void RenderCircle(const ImVec2& position, float radius, uint32_t color, float thickness = 1.0f, uint32_t segments = 16);
	void RenderCircleFilled(const ImVec2& position, float radius, uint32_t color, uint32_t segments = 16);
	void RenderRect(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All, float thickness = 1.0f);
	void RenderRectFilled(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All);
	void dNewGameController_Update(app::NewGameController* __this, MethodInfo* method);
	app::FP dFrame_get_DeltaTime(app::Frame* __this, MethodInfo* method);
};


