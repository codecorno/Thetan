#pragma once
#include "D3D11.h"
#include <D3Dcompiler.h>
#include <winuser.h>
#include "vars.h"

#pragma comment (lib, "D3DCompiler.lib")
#pragma comment (lib, "D3D11.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "user/detours.lib")

#include "dxIndex.h"
#include "helpers.h"

HWND window = nullptr;
WNDPROC originWndProcHandler = nullptr;
bool bShowMenu = false;
bool bPresentInitialized = false;
bool bCreateThread = true;
UINT menuKey = VK_INSERT;

bool noCountdown = false;

ID3D11Device* pDevice;
ID3D11DeviceContext* pDeviceContext;
ID3D11RenderTargetView* pTargetRT;
IDXGISwapChain* pSwapChain;



DWORD_PTR* pDeviceContextVTable = nullptr;
DWORD_PTR* pSwapChainVTable = nullptr;

ImFont* m_default = nullptr;
ImFont* g_font;
ImFont* t_font;
typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* pSwapChain, UINT syncInterval, UINT flags);
IDXGISwapChainPresent fnIDXGISwapChainPresent;


namespace Main {

	HRESULT __fastcall onPresent(IDXGISwapChain* _chain, UINT syncInterval, UINT flags) noexcept;

	bool InitializePresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);
	LRESULT CALLBACK hWndProc(HWND hwnd, UINT uMessage, WPARAM wParam, LPARAM lParam);
	typedef void(__stdcall* ID3D11DrawIndexed)(ID3D11DeviceContext* pDeviceContext, UINT indexCount, UINT startIndexLocation, INT baseVertexLocation);
	void Run();
}
#define SleepUntil(STATE, INTERVAL) while (!##STATE##) { Sleep(##INTERVAL##); }