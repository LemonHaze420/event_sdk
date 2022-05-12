#ifndef _COMMON_H
#define _COMMON_H
#include "mem.h"
#include "event_tbl.h"

#define _entry                  __attribute__((section(".text.main"))) 

#define FOURCC(a,b,c,d)         (unsigned int)(d << 24 | c << 16 | b << 8 | a)
#define LOG(...)                debug_log_to_file_REMOVED(__VA_ARGS__);  \
                                debug_log_to_screen(__VA_ARGS__)

// --------------------------------------------------------------------------------------------------------------------------------------------

/* These functions cannot be inlined, by nature. */
static void debug_log_to_file_REMOVED(char* szFormat, ...)   
{
        void *arg = __builtin_apply_args();
        void *ret = __builtin_apply((void*)TBL_ADDR(38), arg, 100);
        __builtin_return(ret);
}

static void debug_log_to_screen(char* szFormat, ...)   
{
        void *arg = __builtin_apply_args();
        void *ret = __builtin_apply((void*)TBL_ADDR(40), arg, 100);
        __builtin_return(ret);
}

/* Initializes the currently loaded scene and completes loading, then queues up a task with 
   no parameter, using the callback function provided to this function. */
__FORCEINLINE void load_scene(void* callbackFn, char bDevelopment)
{
        LOG("Reverse engineered, designed, developed and created by LemonHaze - 2022\n");
        EV_SetPlayerControlFlags(1);
        if (bDevelopment)
        {
                FUN_0c132f20(0);                        
                FUN_0c1b0500(1);                        
                FUN_0c1b0640(0);
                FUN_0c1b0b40();                         
        }
        
        HLib_Task_t * p_controller_input_task = EnqueueTaskWithoutParameter(callbackFn, 0x04, 0xb, FOURCC('E','V','N','T'));
        if (bDevelopment)
        {
                FUN_0c0c01c0(0,2);                      
                FUN_0c0c0020(0,1);                      
        }
        FUN_0c0949e0(p_controller_input_task);
        EV_FinishLoading();                       
}

/* Loads up the given AFS, provided by name, mounting it into the 'active AFS partition space' */
__FORCEINLINE void LoadAfsPartition(char* szName) {
    char* path = Filepath_Generator(SceneDirectory);
    LOG("evl_AFS_Utils returned 0x%X\n", evl_AFS_Utils(0, MOUNT_AFS_PARTITION, path, (uint *)szName, 0));
}

/* Returns the task parameter pointer for the map control task. 
   NOTE: Only supports GameJam version as of now.
*/
__FORCEINLINE void* GetMapControlTaskParameterPointer() {
        unsigned int MapControlTask = *(int*)(0x0c2d4e54);
        return GetTaskParameterPointer(&MapControlTask);
}

#endif