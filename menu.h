#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <stddef.h>
#include "imgui/imgui.h"
#include "templated_data_types.h"

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

template<typename T, auto& V>
struct Slider
{
	static constexpr ImGuiDataType dataType = GetImGuiDataType<T>::value;

	static void Run(T min = 0, T max = 1, const char* format = "%.3f", float power = 1.f)
	{
		//You are not expected to have multiple sliders for the same option.
		T tv = V, ov = tv;
		ImGui::PushID((void*)&V);
		ImGui::SliderScalar("", dataType, &tv, &min, &max, format, power);
		ImGui::PopID();
		if (tv != ov)
			V = tv;
	}
};

template<typename T, size_t N, auto& V>
struct SliderVec
{
	static constexpr ImGuiDataType dataType = GetImGuiDataType<T>::value;

	static void Run(T min = 0, T max = 1, const char* format = "%.3f", float power = 1.f)
	{
		//You are not expected to have multiple sliders for the same option.
		T tv[N], ov[N];

		for (size_t i = 0; i < N; i++)
			tv[i] = ov[i] = V[i];

		ImGui::PushID((void*)&V);
		ImGui::SliderScalarN("", dataType, tv, N, &min, &max, format, power);
		ImGui::PopID();
		for (size_t i = 0; i < N; i++)
			if (tv[i] != ov[i])
				V[i] = tv[i];
	}
};


#endif
