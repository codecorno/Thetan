#include <Windows.h>
#include "functions.h"
#include "vars.h"

void Functions::noCountdownFunction() noexcept
{
	unsigned char z[] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
	WriteProcessMemory(Vars::hProcess, (LPVOID)Vars::NoCountdownAddr, z, sizeof(z), NULL);
}