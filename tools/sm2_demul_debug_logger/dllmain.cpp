// LemonHaze - 20/04/2022 - 1:00AM
#include "pch.h"

// Base address used to peek/poke with offsets
auto executableBase = DEMUL_EXEC_BASE;

// Previous log entry
std::string previous_log;

// Whether this is the US or GameJam build
static bool bUSBuild = false;

void init()
{
	AllocConsole();
	freopen("CON", "w", stdout);
	SetConsoleTitle(APP_STR);
}

void main_loop()
{	
	if (CHECK(US_TIMESTAMP_ADDR, int, US_TIMESTAMP)) {
		bUSBuild = true;
		printf("US - Sep 12 2001 11:29:25\n");
	}
	else if (CHECK(GAMEJAM_TIMESTAMP_ADDR, int, GAMEJAM_TIMESTAMP)) {
		bUSBuild = false;
		printf("GameJam - Nov  6 2000 13:05:30\n");

		// enable debug menu at main menu asap..
		CHECK_AND_PATCH(GAMEJAM_DEBUG_ENABLE_PATCH_OFFSET, short, GAMEJAM_DEBUG_ENABLE_PATCH);

	} else {
		// thread ends here cause we return
		MessageBox(NULL, L"Unsupported executable.", APP_STR, MB_OK);
		return;
	}

	while (true) {		
		// init
		char* curr_msgbuf = (char*)(executableBase + (bUSBuild ? SM2_SCREEN_DEBUG_TEXT_BUFFER_US : SM2_SCREEN_DEBUG_TEXT_BUFFER_GAMEJAM));
		char* msg_buffer = new char[LOG_BUFFER_SIZE];
		memset(msg_buffer, 0x00, LOG_BUFFER_SIZE);

		// read in the string until we reach 0x00..
		int idx = 0;
		while (*curr_msgbuf != 0x00) {
			msg_buffer[idx] = *curr_msgbuf; ++idx; *curr_msgbuf++;
		}
		
		// set to the latest log string and print if different..
		if (previous_log != std::string(msg_buffer)) {
			previous_log = std::string(msg_buffer);

			// print with timestamp
			std::time_t t_t = time(NULL);																														
			struct tm timeInfo;																																	
			localtime_s(&timeInfo, &t_t);																														
			char* t = new char[128];
			memset(t, 0x00, 128);
			sprintf_s(t, 128, "[%02d:%02d %02d/%02d/%04d]", timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_mday, timeInfo.tm_mon + 1, 1900 + timeInfo.tm_year);
			printf("%s %s\n", t, previous_log.c_str());

			// print to logfile..
			std::ofstream outputLog("sm2.debug.log", std::ios::app);
			if (outputLog.good()) {
				if (bUSBuild)	outputLog << "[US_Build]";
				else			outputLog << "[GameJam_Build]";

				outputLog << t << " " << previous_log << std::endl;
				outputLog.close();
			}

			delete[] msg_buffer;
		}
		
		// patch ShenmueScript table of functions
		CHECK_AND_PATCH(SM2_DEBUG_LOG_TO_CONSOLE_TABLE_ENTRY,	 int,	(bUSBuild ? SM2_DEBUG_LOG_TO_SCREEN_ADDRESS_US : SM2_DEBUG_LOG_TO_SCREEN_ADDRESS_GAMEJAM));
		CHECK_AND_PATCH(SM2_DEBUG_LOG_TO_CONSOLE_TABLE_ENTRY_2,  int,	(bUSBuild ? SM2_DEBUG_LOG_TO_SCREEN_ADDRESS_US : SM2_DEBUG_LOG_TO_SCREEN_ADDRESS_GAMEJAM));
		
		if (!bUSBuild) {
			// enable debug menu at main menu
			CHECK_AND_PATCH(GAMEJAM_DEBUG_ENABLE_PATCH_OFFSET, short, GAMEJAM_DEBUG_ENABLE_PATCH);
		}

		delete[] msg_buffer;
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    DisableThreadLibraryCalls(hModule);
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
		init();
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&main_loop, NULL, 0, NULL);
		break;
	case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}