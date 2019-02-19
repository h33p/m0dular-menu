#include "dx9menu.h"

#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_dx9.h"
#include "imgui/examples/imgui_impl_win32.h"

#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

IMGUI_IMPL_API LRESULT  ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void DX9Menu::InitializeContext(IDirect3DDevice9* device, HWND window)
{
    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX9_Init(device);
}

bool DX9Menu::WndProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return ImGui_ImplWin32_WndProcHandler(window, msg, wParam, lParam);
}
