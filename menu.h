#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <stddef.h>
#include "imgui/imgui.h"

struct MenuTab
{
	const char* name;
	void (*Callback)(void*);
	void* passData;
};

namespace Menu
{
	void InitializeStyle();
	void InitializeFonts();
	void Render(const MenuTab* tabs, size_t tabCount);
}

#endif
