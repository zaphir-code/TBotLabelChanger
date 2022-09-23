#include <Windows.h>
#include <string>
#include <gdhm.hpp>
#include "NoTasBot_config.hpp"

#include "callbacks.hpp"

HANDLE tBotHandle;

DWORD WINAPI _dll_main(LPVOID lpParam)
{
	if (tBotHandle = LoadLibraryA(TASBOT_DLL)) {
		if (gdhm::is_loaded())
		{
			gdhm::gui::window("TASBOT Label Changer", "", nullptr, _main_callback, _header, _footer);
		}
		else
		{
			MessageBoxA(NULL, "GDHM was not found.", "Error!", NULL);
		}
	}
	else {
		MessageBoxA(NULL, "TASBOT was not found.", "Error!", NULL);
	}
	return TRUE;
}
