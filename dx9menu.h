#ifndef DX9MENU_H
#define DX9MENU_H

#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

namespace DX9Menu
{
	void InitializeContext(struct IDirect3DDevice9* device, HWND window);
	void ShutdownContext();
    bool WndProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
}

#endif
