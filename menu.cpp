#include "menu.h"

#include "imgui/imgui.h"

void Menu::InitializeStyle()
{
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	style.WindowPadding = ImVec2(8, 8);
	style.FramePadding = ImVec2(4, 4);
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 5);
	style.ScrollbarSize = 16;
	style.GrabMinSize = 18;
	style.WindowBorderSize = 0;
	style.ChildBorderSize = 0;
	style.PopupBorderSize = 0;
	style.FrameBorderSize = 0;
	style.TabBorderSize = 0;
	style.WindowRounding = 0;
	style.ChildRounding = 0;
	style.FrameRounding = 0;
	style.PopupRounding = 0;
	style.ScrollbarRounding = 12;
	style.GrabRounding = 0;
	style.TabRounding = 4;

	static constexpr ImGuiCol_ colorsStandard[] = {
		ImGuiCol_Button,
		ImGuiCol_Header,
		ImGuiCol_ResizeGrip,
		ImGuiCol_Tab,
		ImGuiCol_FrameBg,

		ImGuiCol_ScrollbarGrabActive,
	};

	static constexpr ImGuiCol_ colorsHovered[] = {
		ImGuiCol_ButtonHovered,
		ImGuiCol_HeaderHovered,
		ImGuiCol_ResizeGripHovered,
		ImGuiCol_TabHovered,
		ImGuiCol_FrameBgHovered,

		ImGuiCol_ScrollbarGrabHovered,
	};

	static constexpr ImGuiCol_ colorsActive[] = {
		ImGuiCol_ButtonActive,
		ImGuiCol_HeaderActive,
		ImGuiCol_ResizeGripActive,
		ImGuiCol_TabActive,
		ImGuiCol_FrameBgActive,

		ImGuiCol_ScrollbarGrab,
	};

	ImVec4 mainColor = ImVec4(0.08f, 0.42f, 0.70f, 1.00f);
	ImVec4 mainColorHovered = ImVec4(0.1f, 0.5f, 0.84f, 1.00f);
	ImVec4 mainColorActive = ImVec4(0.05f, 0.64f, 0.99f, 1.00f);

	colors[ImGuiCol_WindowBg] = ImVec4(0.16f, 0.16f, 0.16f, 0.95f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.16f, 0.16f, 0.16f, 0.90f);
	colors[ImGuiCol_Border] = ImVec4(0.13f, 0.13f, 0.13f, 0.90f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.51f, 0.84f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.05f, 0.64f, 0.99f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.08f, 0.42f, 0.70f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.23f, 0.24f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.68f, 0.99f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.07f, 0.44f, 0.75f, 1.00f);
	colors[ImGuiCol_PlotLines]= ImVec4(0.39f, 0.71f, 1.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.39f, 0.71f, 1.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.89f, 0.50f, 0.19f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.55f, 0.78f, 0.98f, 1.00f);

	for (auto& i : colorsStandard)
		colors[i] = mainColor;

	for (auto& i : colorsHovered)
		colors[i] = mainColorHovered;

	for (auto& i : colorsActive)
		colors[i] = mainColorActive;
}

void Menu::InitializeFonts()
{
	ImGuiIO& io = ImGui::GetIO();
	ImFont* font = io.Fonts->AddFontFromFileTTF("OpenSans-Regular.ttf", 40.0f);
	IM_ASSERT(font != NULL);
	font->Scale *= 0.5f;

	//TODO: Put this somewhere else
	io.IniFilename = nullptr;
}

size_t selectedTab = 0;

void Menu::Render(const MenuTab* tabs, size_t tabCount)
{
	ImGuiIO& io = ImGui::GetIO();

	float scale = io.FontGlobalScale;

	ImGui::SetNextWindowSize(ImVec2(1000 * scale, 700 * scale), ImGuiSetCond_Always);

	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(6, 8));

	if (ImGui::Begin("m0dular.cc Genesis", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize)) {

		//Pop FramePadding
		ImGui::PopStyleVar(1);

		for (size_t i = 0; i < tabCount; i++) {
			if (i)
				ImGui::SameLine();
			ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyle().Colors[i == selectedTab ? ImGuiCol_ButtonActive : ImGuiCol_Button]);
			if (ImGui::Button(tabs[i].name, ImVec2(scale * 1000 / tabCount, 0)))
				selectedTab = i;
			ImGui::PopStyleColor();
		}

		ImGui::PopStyleVar(2);

		if (selectedTab < tabCount && tabs[selectedTab].Callback)
			tabs[selectedTab].Callback();

		ImGui::End();
	} else
		ImGui::PopStyleVar(3);

}
