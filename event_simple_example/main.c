/*
        Shenmue II Event Script SDK
        
        Name:           Simple Example
        Description:    Loads the area and creates a task which draws the controller_input data to the screen.
                        Pressing the START button destroys the task and stops execution.
*/
#include "../event_lib/common.h"

static void my_task(void);

void start(void) 
{
        FUN_0c1329a0(1);
        FUN_0c132f20(0);
        FUN_0c1b0500(1);
        FUN_0c1b0640(0);
        FUN_0c1b0b40();
        HLib_Task* TASK = HLib_EnqueueTaskWithoutParameter(my_task, '\x04', 0xb, 0x544e5645);
        FUN_0c0c01c0(0,2);
        FUN_0c0c0020(0,1);
        FUN_0c0949e0(TASK);
        FUN_0c1220c0();
        return;
}

static void my_task(void) {
        uint controller_input = EVT_GetControllerInput(0,0);
        debug_log_to_screen("controller_input = 0x%x\n", controller_input);
        if (controller_input & START)
                CleanupCurrentTask();        
        return;
}