/*
        Shenmue II Event Script SDK
        
        Name:           Simple Example
        Description:    Loads the area and creates a task which draws the controller_input data to the screen.
                        Pressing the START button destroys the task and stops execution.
                        
                        Additionally, when built for & used on the Game Jam build, the UP button toggles UI rendering.
*/
//#define GAME_JAM
#include "common.h"

static void controller_input_task(void);
static unsigned int task_executed = 0;

void _entry start(void) 
{
        task_executed = 0;
        load_scene(controller_input_task, 1);
        return;
}

#ifdef GAME_JAM
static void ToggleUI()
{
        char curr_val = *(char*)(0x0C303D94);        
        if (curr_val != 255 && curr_val >= 0) {
            *(char*)(0x0C303D94) = 255;
            return;
        } else {
            *(char*)(0x0C303D94) = 0;     
            return;
        }
}
#endif

static void controller_input_task(void) {
        uint controller_input = EVT_GetControllerInput(0,0);
        set_debug_screen_text_position(4,4);
        LOG("task_executed      = 0x%x\n", task_executed);
        LOG("controller_input   = 0x%x\n", controller_input);
        if (controller_input & START)
                TaskCleanupCurrentTask();
#       ifdef GAME_JAM
        if (controller_input & UP) {
                ToggleUI();
                sleep(1);
        }
#       endif
        task_executed++;
        return;
}