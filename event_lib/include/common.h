#ifndef _COMMON_H
#define _COMMON_H

#include "offsets.h"
#include "mem.h"

// Button input values
#define UP      0x1000
#define DOWN    0x2000

#define LEFT    0x4000
#define RIGHT   0x8000

#define A_BTN   0x400
#define B_BTN   0x200
#define X_BTN   0x4
#define Y_BTN   0x2

#define START   0x800

#define LB      0x41
#define RB      0x180

#define RT      0x8

typedef unsigned char           undefined;
typedef unsigned char           bool;
typedef unsigned char           byte;
typedef long long               longlong;
typedef unsigned char           uchar;
typedef unsigned int            uint;
typedef unsigned long long      ulonglong;
typedef unsigned char           undefined1;
typedef unsigned short          undefined2;
typedef unsigned int            undefined4;
typedef unsigned long long      undefined8;
typedef unsigned short          ushort;
typedef unsigned short          word;
typedef char                    string;

#define _entry                  __attribute__((section(".text.main"))) 

#define FOURCC(a,b,c,d)         (unsigned int)(d << 24 | c << 16 | b << 8 | a)
#define LOG(...)                debug_log_to_file_REMOVED(__VA_ARGS__);  \
                                debug_log_to_screen(__VA_ARGS__)

typedef enum AFSUtilMode {
    MOUNT_AFS_PARTITION=0,
    UNMOUNT_AFS_PARTITION=1,
    WAIT_PAK_LOAD=2,
    Unk3=3,
    Unk4=4,
    IsLoaded=5,
    IsLoaded_6=6,
    NewLoadPAK=7,
    IsLoaded_8=8,
    IsLoaded_9=9,
    IsLoaded_A=10,
    IsLoaded_B=11,
    FREE_PAKFILE_AFS=12,
    DESTROY_PAKFILE_AFS=13
} AFSUtilMode;

typedef enum FilepathGenMode {
    SceneDirectory=0,
    MiscDirectory=1,
    SoundDirectory=2,
    StreamDirectory=3,
    SpriteDirectory=4,
    ItemDirectory=5,
    CharaDirectory=6,
    PackDirectory=7
} FilepathGenMode;

#include "event_tbl.h"

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

#endif