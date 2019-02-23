#ifndef TEMPLATED_DATA_TYPES_H
#define TEMPLATED_DATA_TYPES_H

#include "imgui/imgui.h"

template<typename T>
struct GetImGuiDataType
{

};

#define TEMPLATED_IMGUI_DATA_TYPE(type, data_type)						\
	template<>															\
	struct GetImGuiDataType< type >										\
	{																	\
		static constexpr ImGuiDataType value = ImGuiDataType_##data_type ;	\
	};

TEMPLATED_IMGUI_DATA_TYPE(int, S32);
TEMPLATED_IMGUI_DATA_TYPE(unsigned int, U32);
TEMPLATED_IMGUI_DATA_TYPE(long long, S64);
TEMPLATED_IMGUI_DATA_TYPE(unsigned long long, U64);
TEMPLATED_IMGUI_DATA_TYPE(float, Float);
TEMPLATED_IMGUI_DATA_TYPE(double, Double);

#endif
