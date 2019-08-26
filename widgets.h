#ifndef WIDGETS_H
#define WIDGETS_H

#include "templated_data_types.h"

struct TabPad
{
	const int pad;

	TabPad(const int& p = 10)
		: pad(p)
	{
		ImGui::Dummy(ImVec2(0.0f, pad));
		ImGui::Indent(pad);
	}

	~TabPad()
	{
		ImGui::Unindent(pad);
	}
};

template<typename T>
struct Slider
{
	static constexpr ImGuiDataType dataType = GetImGuiDataType<T>::value;

	template<typename F>
	static void Run(F& V, T min = 0, T max = 1, const char* label = "", const char* format = "%.3f", float power = 1.f)
	{
		T tv = V;//, ov = tv;

		//You are not expected to have multiple sliders for the same option.
		ImGui::PushID((void*)&V);
		ImGui::SliderScalar(label, dataType, &tv, &min, &max, format, power);
		ImGui::PopID();

		V = tv;
	}
};

template<typename T, size_t N>
struct SliderVec
{
	static constexpr ImGuiDataType dataType = GetImGuiDataType<T>::value;

	template<typename F>
	static void Run(F& V, T min = 0, T max = 1, const char* label = "", const char* format = "%.3f", float power = 1.f)
	{
		T tv[N], ov[N];

		for (size_t i = 0; i < N; i++)
			tv[i] = ov[i] = V[i];

		//You are not expected to have multiple sliders for the same option.
		ImGui::PushID((void*)&V);
		ImGui::SliderScalarN(label, dataType, tv, N, &min, &max, format, power);
		ImGui::PopID();

		for (size_t i = 0; i < N; i++)
			V[i] = tv[i];
	}
};

struct CheckBox
{
	template<typename T>
	static void Run(T& V, const char* label)
	{
		bool tv = V;
		ImGui::Checkbox(label, &tv);
		if (tv != !!V)
			V = tv;
	}
};

#endif
