/*
        Shenmue II Event Script SDK
        
        Name:           Bicycle function calling script
        Description:    Calls a bicycle-related function found only within the "GameJam" beta of Shenmue II - DC.
                        
        !!NOTE:         As this script makes use of a function only found within the "GameJam" beta, this script currently
                        does not work on any other build of Shenmue II.
*/
#include "common.h"

typedef struct tmp_t {
    char pad[0x1a3];        
    int* ptr;                                   
} tmp_t;
static tmp_t data;

static void (*MysteryBicycleFunction)(tmp_t*) = (void*) 0x0c133f20;
static int (*get_ctrl_param_ptr)(void) = (void*) 0x0c1321c0;

static void CallBicycleFunction(void)
{
        data.ptr = (int*)(get_ctrl_param_ptr());
        MysteryBicycleFunction(&data);
        sleep(1);
        return;
}
static void controller_input_task(void) 
{
        uint controller_input = EVT_GetControllerInput(0, 0);
        if (controller_input & A_BTN) 
        {
                CallBicycleFunction();
        }
        else 
        {        
                set_debug_screen_text_position(1,1);
                LOG("Press A to create a bicycle!\n");
        }
        return;
}
void _entry start(void) 
{
        load_scene(controller_input_task, 1);
        return;
}