#pragma once

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
IDXGISwapChainPresent fnIDXGISwapChainPresent;
HRESULT __fastcall onPresent(IDXGISwapChain* _chain, UINT syncInterval, UINT flags) noexcept;

bool InitializePresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK hWndProc(HWND hwnd, UINT uMessage, WPARAM wParam, LPARAM lParam);
typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* pSwapChain, UINT syncInterval, UINT flags);
typedef void(__stdcall* ID3D11DrawIndexed)(ID3D11DeviceContext* pDeviceContext, UINT indexCount, UINT startIndexLocation, INT baseVertexLocation);
#define SleepUntil(STATE, INTERVAL) while (!##STATE##) { Sleep(##INTERVAL##); }

void Run();