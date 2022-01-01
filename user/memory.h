#pragma once
#include <Windows.h>

class Memory {
public:
	DWORD64 GameAssembly = reinterpret_cast<DWORD64>(GetModuleHandleA("GameAssembly.dll"));
	DWORD64 NoCountdownAddr = GameAssembly + 0x6AFEA6;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
	unsigned char fiveBytesNOP[5] = {0x90, 0x90, 0x90, 0x90, 0x90};;
};

extern Memory memory;