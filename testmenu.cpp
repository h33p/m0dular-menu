#include "testmenu.h"
#include "menu.h"

static void AimbotTab();
static void VisualsTab();
static void AntiaimTab();
static void OtherTab();

const MenuTab tabs[] = {
	{"Aimbot", AimbotTab},
	{"Visuals", VisualsTab},
	{"Antiaim", AntiaimTab},
	{"Misc", nullptr},
	{"Other", OtherTab}
};

void TestMenu::Render()
{
	Menu::Render(tabs, sizeof(tabs) / sizeof(tabs[0]));
}

static void AimbotTab()
{

}

static void VisualsTab()
{

}

static void AntiaimTab()
{

}

static void OtherTab()
{

}
