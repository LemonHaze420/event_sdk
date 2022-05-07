#ifndef _COMMON_H
#define _COMMON_H

#include "offsets.h"
//#include "event_fn_tbl.h"
#include <stdarg.h>

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

#define FOURCC(a,b,c,d)         (unsigned int)(d << 24 | c << 16 | b << 8 | a)
#define GEN_NOP                 __asm("nop\n\t")

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

typedef struct HLib_Task {
    undefined * taskCallback;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    undefined field5_0x8;
    undefined field6_0x9;
    undefined field7_0xa;
    undefined field8_0xb;
    int chara_type;
    undefined field10_0x10;
    undefined field11_0x11;
    undefined field12_0x12;
    undefined field13_0x13;
    undefined field14_0x14;
    undefined field15_0x15;
    undefined field16_0x16;
    undefined field17_0x17;
    undefined1 next_task; // Created by retype action
    undefined field19_0x19;
    undefined field20_0x1a;
    undefined field21_0x1b;
    undefined field22_0x1c;
    undefined field23_0x1d;
    undefined field24_0x1e;
    undefined field25_0x1f;
    undefined field26_0x20;
    undefined field27_0x21;
    undefined field28_0x22;
    undefined field29_0x23;
    undefined1 other_task; // Created by retype action
    undefined field31_0x25;
    undefined field32_0x26;
    undefined field33_0x27;
    undefined field34_0x28;
    undefined field35_0x29;
    undefined field36_0x2a;
    undefined field37_0x2b;
    undefined field38_0x2c;
    undefined field39_0x2d;
    undefined field40_0x2e;
    undefined field41_0x2f;
    undefined * field42_0x30;
    undefined * field43_0x34;
    undefined4 field44_0x38;
} HLib_Task;

// --------------------------------------------------------------------------------------------------------------------------------------------

static inline __attribute__((always_inline)) HLib_Task*       HLib_EnqueueTaskWithoutParameter(void *callbackFn, char _r8b, undefined nextFunctionIndex, unsigned int taskToken)   {
        return ((HLib_Task* (*)(void *, char, undefined, unsigned int))(void*)TBL_ADDR(279)) (callbackFn, _r8b, nextFunctionIndex, taskToken);
}
static inline __attribute__((always_inline)) int*       Shenmue_evl_AFS_Utils(undefined4 param_1,AFSUtilMode param_2,char *param_3,uint *param_4,undefined4 param_5)   {
        return ((int* (*)(undefined4 ,AFSUtilMode ,char *,uint *,undefined4 ))(void*)TBL_ADDR(254)) (param_1,param_2,param_3,param_4,param_5);
}
static inline __attribute__((always_inline)) char*       Shenmue_Filepath_Generator(FilepathGenMode path_type)   {
        return ((char* (*)(FilepathGenMode))(void*)TBL_ADDR(423)) (path_type);
}
static inline __attribute__((always_inline)) void*       HLib_GetTaskParameterPointer(int* p1)   {
        return ((void* (*)(int*))(void*)TBL_ADDR(283)) (p1);
}
static inline __attribute__((always_inline)) void       CleanupCurrentTask()   {
        ((void (*)(void))(void*)TBL_ADDR(282)) ();
}
static inline __attribute__((always_inline)) ushort       EVT_GetControllerInput(uint param_1,undefined4 param_2)   {
        return ((ushort (*)(uint ,undefined4 ))(void*)TBL_ADDR(50)) (param_1, param_2);
}
static inline __attribute__((always_inline)) void       FUN_0c1329a0(int mode)   {
        ((void (*)(int))(void*)TBL_ADDR(67)) (mode);
}
static inline __attribute__((always_inline)) void       FUN_0c132f20(int mode)   {
        ((void (*)(int))(void*)TBL_ADDR(68)) (mode);
}
static inline __attribute__((always_inline)) void       FUN_0c1b0500(int mode)   {
        ((void (*)(int))(void*)TBL_ADDR(318)) (mode);
}
static inline __attribute__((always_inline)) void       FUN_0c1b0640(int mode)   {
        ((void (*)(int))(void*)TBL_ADDR(322)) (mode);
}
static inline __attribute__((always_inline)) void       FUN_0c1b0b40()   {
        ((void (*)(void))(void*)TBL_ADDR(320)) ();
}
static inline __attribute__((always_inline)) void       FUN_0c1220c0()   {
        ((void (*)(void))(void*)TBL_ADDR(14)) ();
}
static inline __attribute__((always_inline)) void       FUN_0c0949e0(HLib_Task* TASK)   {
        ((void (*)(HLib_Task*))(void*)TBL_ADDR(128)) (TASK);
}
static inline __attribute__((always_inline)) void       FUN_0c0c01c0(uint p1, uint p2)   {
        ((void (*)(uint,uint))(void*)TBL_ADDR(105)) (p1,p2);
}
static inline __attribute__((always_inline)) void       FUN_0c0c0020(uint p1, uint p2)   {
        ((void (*)(uint,uint))(void*)TBL_ADDR(104)) (p1,p2);
}
#endif