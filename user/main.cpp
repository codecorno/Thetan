#include "pch-il2cpp.h"
#pragma comment (lib, "D3DCompiler.lib")
#pragma comment (lib, "D3D11.lib")

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <unordered_set>
#include <mutex>
#include <D3D11.h>
#include <D3Dcompiler.h>
#include <winuser.h>
#include <DirectXMath.h>

#include "vars.h"
#include "memory.h"
#include "main.h"
#include "menu.h"
#include "custom.h"
#include "dxIndex.h"
#include "helpers.h"
#include "detours.h"
#include "functions.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"

#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "user/detours.lib")

using namespace app;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool InitializePresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);
#define UNHOOKFUNC(n) if (!Custom::UnhookFunction(&(PVOID&)n, d ## n, #n)) return;
#define HOOKFUNC(n) if (!Custom::HookFunction(&(PVOID&)n, Custom::d ## n, #n)) return;

void Run()
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	printf("Console Started\n");
    il2cpp_thread_attach(il2cpp_domain_get());
	printf("SDK Attached\n");
	GetSwapChainVTable();
	printf("SwapChan VTable Initialized\n");
	DetourTransactionBegin();
	printf("Detour Transaction Started\n");
	DetourUpdateThread(GetCurrentThread());
	HOOKFUNC(NewGameController_Update);
	HOOKFUNC(GameController_OnAddScore);
	HOOKFUNC(SkillButton_CanUseSkill);
	DetourAttach(&(LPVOID&)fnIDXGISwapChainPresent, (PBYTE)onPresent);
	printf("Present Loop Started\n");
	DetourTransactionCommit();
	printf("Detour Commited\n");

	while (!bPresentInitialized) {
		Sleep(100); 
	}

	Sleep(100);
}




LRESULT CALLBACK hWndProc(HWND hwnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	POINT mPos;

	GetCursorPos(&mPos);
	ScreenToClient(window, &mPos);

	ImGui::GetIO().MousePos.x = (float)mPos.x;
	ImGui::GetIO().MousePos.y = (float)mPos.y;

	if (uMessage == WM_KEYUP)
	{
		if (wParam == vars.menuKey)
		{
			vars.bShowMenu = !vars.bShowMenu;
		}
	}

	if (vars.bShowMenu)
	{
		ImGui_ImplWin32_WndProcHandler(hwnd, uMessage, wParam, lParam);
		return true;
	}

	return CallWindowProc(originWndProcHandler, hwnd, uMessage, wParam, lParam);
}


bool WINAPI GetSwapChainVTable()
{
	HRESULT result;

	WNDCLASSEX wc = {
		sizeof(WNDCLASSEX), CS_CLASSDC,
		[](const HWND hwnd, const UINT uMessage, const WPARAM wParam, const LPARAM lParam)
		{
			return DefWindowProc(hwnd, uMessage, wParam, lParam);
		},
		0L, 0L, GetModuleHandle(nullptr),
		nullptr, nullptr, nullptr, nullptr,
		L"DX", nullptr
	};

	RegisterClassEx(&wc);

	HWND hWnd = CreateWindow(L"DX", NULL, WS_OVERLAPPEDWINDOW,
		100, 100, 300, 300, NULL, NULL, wc.hInstance, NULL);

	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = 2;
	swapChainDesc.BufferDesc.Height = 2;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;

	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hWnd;

	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.Windowed = TRUE;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	D3D_FEATURE_LEVEL requestedFeatureLevel = D3D_FEATURE_LEVEL_11_0;
	const UINT nRequestedFeatureLevel = 1;

	D3D_FEATURE_LEVEL supportedFeatureLevel;
	IDXGISwapChain* swapChain = nullptr;
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* deviceContext = nullptr;

	result = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		&requestedFeatureLevel, nRequestedFeatureLevel, D3D11_SDK_VERSION,
		&swapChainDesc, &swapChain, &device, &supportedFeatureLevel, &deviceContext);

	if (FAILED(result))
		return false;


	pSwapChainVTable = (DWORD_PTR*)swapChain;
	pSwapChainVTable = (DWORD_PTR*)pSwapChainVTable[0];

	fnIDXGISwapChainPresent = (IDXGISwapChainPresent)(DWORD_PTR)pSwapChainVTable[SC_PRESENT];

	Sleep(2000);

	return true;
}

      

HRESULT __fastcall onPresent(IDXGISwapChain* _chain, UINT syncInterval, UINT flags) noexcept
{
	bool result;
	if (!bPresentInitialized)
	{
		result = InitializePresent(_chain, syncInterval, flags);
		if (!result)
		{
			return fnIDXGISwapChainPresent(_chain, syncInterval, flags);
		}
	}
	menu.Setup();
	
	pDeviceContext->OMSetRenderTargets(1, &pTargetRT, nullptr);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return fnIDXGISwapChainPresent(_chain, syncInterval, flags);
}

bool InitializePresent(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags)
{
	HRESULT result;

	result = pChain->GetDevice(__uuidof(ID3D11Device), (PVOID*)&pDevice);
	if (FAILED(result))
	{
		return false;
	}

	pDevice->GetImmediateContext(&pDeviceContext);
	pSwapChain = pChain;

	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	pSwapChain->GetDesc(&swapChainDesc);

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	window = swapChainDesc.OutputWindow;

	originWndProcHandler = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)hWndProc);

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pDeviceContext);

	ImGui::GetIO().ImeWindowHandle = window;

	ID3D11Texture2D* pBackBuffer;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	if (pBackBuffer != nullptr)
	{
		pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pTargetRT);
		pBackBuffer->Release();
	}

	bPresentInitialized = true;

	return true;
}

