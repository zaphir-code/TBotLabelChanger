#include <gdhm.hpp>
#include <format>

#include <cstring>
#include <cstdint>

#include "tbot_label_changer_config.hpp"

#include "TasBot_v34-18_offsets.hpp"

extern HANDLE tBotHandle;

void _footer()
{
	char buffer[17];

	gdhm::gui::label("");

	gdhm::gui::label("Change name of the");
	gdhm::gui::label("TASBOT label: ");
	gdhm::gui::input_text(
		gdhm::new_id,
		buffer,
		sizeof(buffer),
		[buffer](void) -> void 
		{
			memcpy_s(reinterpret_cast<void*>(
				reinterpret_cast<std::uintptr_t>(tBotHandle) + TASBOT_LABEL_1), 
				17, 
				reinterpret_cast<const void*>(buffer), 
				16);
			memcpy_s(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(tBotHandle) + TASBOT_LABEL_2), 
				17,
				reinterpret_cast<const void*>(buffer),
				16);
		}
		);
	gdhm::gui::label("");


	gdhm::control reset_button_control("Reset");
	gdhm::gui::button(
		gdhm::new_id,
		&reset_button_control,
		[](void) -> void 
		{
			std::memset(
				reinterpret_cast<char*>(reinterpret_cast<std::uintptr_t>(tBotHandle) + TASBOT_LABEL_1), 
				0, 
				16);
			std::memset (
				reinterpret_cast<char*>(reinterpret_cast<std::uintptr_t>(tBotHandle) + TASBOT_LABEL_2), 
				0, 
				16);
		}
		);
}

void _header()
{
	gdhm::gui::label(std::format("Version: {}", NO_TASBOT_LABEL_VERSION).c_str());
}
