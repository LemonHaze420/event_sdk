/*
        Shenmue II Event Script SDK
        
        Name:           Simple Example
        Description:    Loads the area and creates a task which draws the controller_input data to the screen.
                        Pressing the START button destroys the task and stops execution.
*/
#include "../event_lib/common.h"

#define LOG(...)        debug_log_to_file_REMOVED(__VA_ARGS__);  \
                        debug_log_to_screen(__VA_ARGS__)

void debug_log_to_file_REMOVED(char* szFormat, ...);
void debug_log_to_screen(char* szFormat, ...);

static void controller_input_task(void);

void start(void) 
{
        LOG("Reverse engineered, designed, developed and created by LemonHaze - 2022\n");
        
        FUN_0c1329a0(1);
        FUN_0c132f20(0);
        FUN_0c1b0500(1);
        FUN_0c1b0640(0);
        FUN_0c1b0b40();
 
        HLib_Task* p_controller_input_task = HLib_EnqueueTaskWithoutParameter(controller_input_task, 0x04, 0xb, FOURCC('E','V','N','T'));
        FUN_0c0c01c0(0,2);
        FUN_0c0c0020(0,1);
        FUN_0c0949e0(p_controller_input_task);
        FUN_0c1220c0();
        return;
}
static void controller_input_task(void) {
        uint controller_input = EVT_GetControllerInput(0,0);
        LOG("controller_input = 0x%x\n", controller_input);
        if (controller_input & START)
                CleanupCurrentTask();        
        return;
}
void debug_log_to_file_REMOVED(char* szFormat, ...)   
{
        void *arg = __builtin_apply_args();
        void *ret = __builtin_apply((void*)TBL_ADDR(38), arg, 100);
        __builtin_return(ret);
}
void debug_log_to_screen(char* szFormat, ...)   
{
        void *arg = __builtin_apply_args();
        void *ret = __builtin_apply((void*)TBL_ADDR(40), arg, 100);
        __builtin_return(ret);
}