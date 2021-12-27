#pragma once
#include <Windows.h>

class Vars {
public:
	bool noCountdown = false;
	bool bShowMenu = false;
	UINT menuKey = VK_INSERT;
};

extern Vars vars;