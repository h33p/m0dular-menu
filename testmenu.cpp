#include "menuimpl.h"
#include "menu.h"
#include "widgets.h"

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
int anotherGlobalInt = 10;
float globalVec[4];

static void AimbotTab()
{
	TabPad pad;
	ImGui::Button("OWO");
	ImGui::Columns(2, nullptr, true);
	ImGui::BeginChild("C1", ImVec2(0, 0), true, ImGuiWindowFlags_NoBackground);
	{
		Slider<float>::Run(globalFloat);
		Slider<float>::Run(anotherGlobalFloat, -12, 12, "Floaty thing");
		CheckBox::Run(globalInt, "Bool");
	}
	ImGui::EndChild();

	ImGui::NextColumn();

	ImGui::BeginChild("C2", ImVec2(0, 0), true, ImGuiWindowFlags_NoBackground);
	{
		Slider<int>::Run(globalInt, 0, 100);
		Slider<float>::Run(anotherGlobalInt, 0, 100);
		SliderVec<float, 4>::Run(globalVec, 0, 100);
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
