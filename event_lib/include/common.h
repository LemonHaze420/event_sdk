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
        
        HLib_Task_t * TASK = EnqueueTaskWithoutParameter(callbackFn, 0x04, 0xb, EVNT);
        if (bDevelopment)
        {
                FUN_0c0c01c0(0,2);                      
                FUN_0c0c0020(0,1);                      
        }
        FUN_0c0949e0(TASK);
        EV_FinishLoading();                       
}

/* Loads up the given AFS, provided by name, mounting it into the 'active AFS partition space' */
__FORCEINLINE void LoadAfsPartition(char* szName) {
    char* path = Filepath_Generator(SceneDirectory);
    LOG("evl_AFS_Utils returned 0x%X\n", evl_AFS_Utils(0, MOUNT_AFS_PARTITION, path, (uint *)szName, 0));
}

/* Plays an animation on a given character, provided by ID. */
/*

        ReadMotiFromDirectory(GetCurrentScene(), GetCurrentArea(), "0004A.MOT");
        PlayAnimationForCharacterByID(CHAR, motion_id, 0);
        PreLoadMotion(motion_id & 0xffff);
*/
__FORCEINLINE void PlayAnim(unsigned int chara_id, short anim_id)
{
        astruct_51* CHAR = FindMTWK_ForCEWP(chara_id);
        PlayAnimationForCharacterByID(CHAR, anim_id, 0);
}

/*   
     Returns a string pointer of the build's TAKE.
*/
__FORCEINLINE char* GetCurrentTake() {
        return &*(char*)(GLOBAL_TAKE_OFFSET);
}

/*
     Returns the current task name.
*/
__FORCEINLINE unsigned int GetCurrentTaskName() {
        return *(int*)(GLOBAL_CURR_TASK_OFFSET);
}

/*
     Returns the current scene.
*/
__FORCEINLINE unsigned int GetCurrentScene() {
        return *(int*)(GLOBAL_SCENE_OFFSET);
}

/*
     Returns the current directory entry.
*/
__FORCEINLINE char* GetCurrentDirectoryEntry() {
        return &*(char*)(GLOBAL_CURR_DIRE_OFFSET);
}

/*
     Returns the currently opened file name.
*/
__FORCEINLINE char* GetCurrentOpenedFile() {
        return &*(char*)(GLOBAL_CURR_FILE_OFFSET);
}

/*
     Returns the current disk number.
*/
__FORCEINLINE unsigned int GetCurrentDiskNum() {
        return *(int*)(GLOBAL_DISKNUM_OFFSET);
}

/*
     Returns the current area.
*/
__FORCEINLINE unsigned int GetCurrentArea() {
        return *(int*)(GLOBAL_AREA_OFFSET);
}

/*
     Returns the current entry of the current area.
*/
__FORCEINLINE unsigned int GetCurrentEntry() {
        return *(int*)(GLOBAL_ENTRY_OFFSET);
}

/*
     Returns the current step value.
*/
__FORCEINLINE unsigned int GetCurrentStep() {
        return *(int*)(GLOBAL_STEP_OFFSET);
}

#endif