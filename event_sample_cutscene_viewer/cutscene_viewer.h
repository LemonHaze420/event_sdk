#ifndef _CUTSCENE_VIEWER_H
#define _CUTSCENE_VIEWER_H

#define MIN_CUTSCENE_ID         0
#define MAX_CUTSCENE_ID         4

#define KWQA                    FOURCC('K', 'W', 'Q', 'A')

#define l141                    FOURCC('l','1','4','1')
#define l151                    FOURCC('l','1','5','1')

#define a988                    FOURCC('a','9','8','8')
#define a990                    FOURCC('a','9','9','0')
#define a992                    FOURCC('a','9','9','2')
#define a994                    FOURCC('a','9','9','4')
#define a840                    FOURCC('a','8','4','0')
#define a842                    FOURCC('a','8','4','2')
#define a844                    FOURCC('a','8','4','4')
#define a848                    FOURCC('a','8','4','8')

#define MAP1_NAME               "KWW1"
#define MAP2_NAME               "KWA1"
#define MAP3_NAME               "KWA2"

#define MOT_NAME                "0517A.MOT"
#define SEQ_NAME                "0517"
#define W_COND_N                "W_COND.BIN"

#define CVWR_NAME               FOURCC('C','V','W','R')
#define DBGT_NAME               FOURCC('D','B','G','T')
#define LOAD_NAME               FOURCC('l','o','a','d')

static unsigned int character_tbl[2] = {
        SIN_,
        ID_END
};

enum State {
        SELECT_CUTSCENE         = 0,
        START_CUTSCENE          = 1,
        UNK_STATE               = 2,
        LOAD_STATE              = 3,
        END,
};

static void init_cutscene_viewer(void);

static void MainStateHandler(astruct_86 *evt_ctx);
static void CutscenePlayStateHandler(astruct_86 *evt_ctx);
static void CutsceneHandler(astruct_86 *evt_ctx);
static void AllocateEventStorageWrapper(astruct_86 * ctx);

static void InitCutscene(int scene_num);
static void FUN_0517_runtime__0c348760_fsca_wrapper3(ulonglong param_1);
static void LoadWCONDBin(void);

static void SetCEWP_MTWK_FlagTo2(int param_1);
static void SetCEWP_MTWK_FlagTo2_Wrapper(void);

static void SetCEWP_MTWK_FlagTo0(int param_1);
static void SetCEWP_MTWK_FlagTo0_Wrapper(void);

static void EnqueueLoad(undefined4 chara_tbl, HLib_Task_t* TASK);
static void LOAD_Callback(void);

static astruct_193 unk_struct;

static void ToggleUI(void);

// Defaults and variables

static undefined4       global_init                                     = 0;
static undefined4       global_has_loaded_flag                          = 0;
static undefined4*      global_chara_tbl_ptr                            = 0;
static HLib_Task_t*     global_load_task_ptr                            = 0;
static int              global_should_load_hi_poly_hands_flag           = 1;

static char             bDisplay                                        = 1;

#endif