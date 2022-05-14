/*
        Shenmue II Event Script SDK
        
        Name:           Simple Example
        Description:    Loads the area and creates a task which draws the controller_input data to the screen.
        
                        Pressing Left/Right increases/decreases `user_anim_id`. (Holding LB increases/decreases by 2, instead of 1)
                        Pressing the A button plays the animation with the ID from `user_anim_id`
                        Pressing the START button destroys the task and stops execution.
                        
                        Additionally, when built for & used on the Game Jam build, the UP button toggles UI rendering.
*/
#define GAME_JAM
#include "common.h"

static void controller_input_task(void);
static unsigned int task_executed = 0;
static short user_anim_id = 0x0;

void _entry start(void) 
{
        task_executed = 0;
        user_anim_id = 0;
        
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
        debug_log_to_screen("task_executed      = 0x%x\n",      task_executed);
        debug_log_to_screen("controller_input   = 0x%x\n",      controller_input);
        debug_log_to_screen("user_anim_id       = %d\n",        user_anim_id);
        
        if (controller_input & START)
                TaskCleanupCurrentTask();
#ifdef GAME_JAM        
        else if (controller_input & UP) {
                ToggleUI();
                sleep(1);
        } 
#endif
        else if (controller_input & LEFT) {
                controller_input & LB ? user_anim_id = user_anim_id - 2 : user_anim_id--;
                if (user_anim_id == 0xFFFF)
                        user_anim_id = 0;
                sleep(1);
        } else if (controller_input & RIGHT) {
                controller_input & LB ? user_anim_id = user_anim_id + 2 : user_anim_id++;
                if (user_anim_id == 0xFFFF)
                        user_anim_id = 0;
                sleep(1);
        } else if (controller_input & A_BTN) {
                PlayAnim(RYO_, user_anim_id);
                sleep(1);
        }
        task_executed++;
        return;
}
