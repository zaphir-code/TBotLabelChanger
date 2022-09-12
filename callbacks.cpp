#include <gdhm.h>
#include <format>
#include <array>

#include <cstring>
#include <cstdint>

#include "NoTasBotLabel.hpp"
#include "TasBot_v34-18_offsets.hpp"

extern HANDLE tBotHandle;

char buffer[17];

static void on_release()
{
	memcpy_s(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(tBotHandle) + TASBOT_LABEL_1), 17, buffer, 17);
	memcpy_s(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(tBotHandle) + TASBOT_LABEL_2), 17, buffer, 17);
}

void _main_callback()
{
	gdhm::gui::label("");

	gdhm::gui::label("Change name of the");
	gdhm::gui::label("TASBOT label: ");
	gdhm::gui::input_text(
		gdhm_new_id(), 
		buffer,
		17,
		on_release);
}

void _footer()
{
	gdhm::gui::label("By GD Ephir");
}

void _header()
{
	gdhm::gui::label(std::format("Version: {}", NO_TASBOT_LABEL_VERSION).c_str());
}