#ifndef _OFFSETS_H
#define _OFFSETS_H

#define ENQUEUETASK_OFFS        0x0c053e80
#define GETTASKPARAM_OFFS       0x0c0549a0

#define EVL_AFS_UTILS_OFFS      0x0c092100
#define FILEPATH_GEN_OFFS       0x0c097b60

#define CLEANUP_CURTASK_OFFS    0x0c0540c0
#define COMPLETE_LOAD_OFFS      0x0c1220c0

#define DEBUG_LOG_TO_FILE_OFFS  0x0c14efc0
#define DEBUG_LOG_TO_SCR_OFFS   0x0c1dc400

#define EVT_GetControllerInput_OFFS     0x0c094040

#define MAPCONTROLTASK_OFFS     0x0c2d4e54


// valid for all Dreamcast builds of Shenmue II (static function table)
#define g_task_context_OFFS     0x0c020200-0xC
#define EV_SCRIPT_FUNC_TBL_OFFS 0x0c020200

// offsets into the above defined table of fn's
#define EV_NPC_NewLoadSw_tbloffs                                0x14
#define EV_GetPlayerStats_tbloffs                               0x5C
#define EV_debug_log_tbloffs                                    0x98
#define Filepath_Gen_tbloffs                                    0x69C

#define EnqueueTaskWithoutParameter_tbloffs                     0x45C
#define EnqueueTaskWithoutParameterForCurrentTask_tbloffs       0x460
#define TaskCleanupCurrentTask_tbloffs                          0x468

#define CALL(f,...)             *(void*)(EV_SCRIPT_FUNC_TBL_OFFS + f)(__VA_ARGS__)

#endif