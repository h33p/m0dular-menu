#include "menuimpl.h"
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

void MenuImpl::Render()
{
	Menu::Render(tabs, sizeof(tabs) / sizeof(tabs[0]));
}

float globalFloat = 43;
float anotherGlobalFloat = 43;
int globalInt = 3;
float globalVec[4];

static void AimbotTab()
{
	ImGui::Columns(2, nullptr, true);
	ImGui::BeginChild("C1", ImVec2(0, 0), true);
	{
		Slider<float, globalFloat>::Run();
		Slider<float, anotherGlobalFloat>::Run(-12, 12);
	}
	ImGui::EndChild();

	ImGui::NextColumn();

	ImGui::BeginChild("C2", ImVec2(0, 0), true);
	{
		Slider<int, globalInt>::Run(0, 100);
		SliderVec<float, 4, globalVec>::Run(0, 100);
	}
	ImGui::EndChild();


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
