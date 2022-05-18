// We need to define this (or compile with `make TYPE=EV3P RETAIL=1`), so that the library uses the proper addressing
#define RETAIL_MEMORY

#include "common.h"

#define AR01                    FOURCC('A','R','0','1')
#define VIEW                    FOURCC('V','I','E','W')

static void my_callback(void)
{
        set_debug_screen_text_position(10, 10);
        debug_log_to_screen("Press START to load AR01\n");
        debug_log_to_screen("Press A to load VIEW\n");
        
        uint controller_input = get_controller_input(1);
        if (controller_input & START) {
                LoadScene(1, AR01, 0);
        } else if (controller_input & A_BTN) {
                LoadScene(1, VIEW, 0);
        }
}

void _entry start(void) 
{
        // This is also needed, unless 1ST_READ has been patched, or sm2_demul_logger is used.
        #ifdef RETAIL_MEMORY
                *(int*)(addr)0x8c020298 = 0x8c1e4220;            // patch in debug_log_to_file_REMOVED, replacing it for the screen func
                *(int*)(addr)0x8c0202a0 = 0x8c1e4220;            // patch back in debug_log_to_screen
                *(int*)(addr)0x8c02029c = 0x8c1e4120;            // patch back in set_debug_screen_text_position
        #endif

        LOG("LemonHaze - 2022\n");
        EV_SetPlayerControlFlags(1);
        EV_FinishLoading();
        EnqueueTaskWithParameter(my_callback, 4, 0xb, 8, EVNT);
        return;
}