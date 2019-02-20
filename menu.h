#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <stddef.h>

struct MenuTab
{
	const char* name;
	void (*Callback)(void);
};

namespace Menu
{
	void InitializeStyle();
	void InitializeFonts();
	void Render(const MenuTab* tabs, size_t tabCount);
}

#endif
