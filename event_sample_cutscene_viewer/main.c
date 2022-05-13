/*
        Shenmue II Event Script SDK
        
        Name:           Cutscene Viewer
        Description:    A sample debug cutscene viewer based on 0517.EV3.
*/
#include "common.h"
#include "cutscene_viewer.h"

#define MIN_CUTSCENE_ID         0
#define MAX_CUTSCENE_ID         4

static void entrypoint(void);

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

static void EnqueueLoad(undefined4 param_1, astruct_166 *param_2);
static void LOAD_Callback(void);

static astruct_193 unk_struct;

static void SetCEWP_MTWK_FlagTo0(int charaID)
{
	astruct_51 * paVar1 = FindMTWK_ForCEWP(charaID);
	SetCEWPFlags((int)paVar1, 6, 0);
	EV_UnknownFunc(charaID);
	return;
}

static void SetCEWP_MTWK_FlagTo2(int charaID)
{
	astruct_51 *paVar1 = FindMTWK_ForCEWP(charaID);
	SetCEWPFlags((int)paVar1, 6, 2);
	EV_UnknownFunc(charaID);
	return;
}

static void SetCEWP_MTWK_FlagTo0_Wrapper(void)
{
	SetCEWP_MTWK_FlagTo0(FOURCC('R', 'Y', 'O', '_'));
	SetCEWP_MTWK_FlagTo0(FOURCC('S', 'I', 'N', '_'));
        
	EV_UnknownFunc(FOURCC('a','9','8','8'));
	EV_UnknownFunc(FOURCC('a','9','9','0'));
	EV_UnknownFunc(FOURCC('a','9','9','2'));
	EV_UnknownFunc(FOURCC('a','9','9','4'));
	EV_UnknownFunc(FOURCC('a','8','4','0'));
	EV_UnknownFunc(FOURCC('a','8','4','2'));
	EV_UnknownFunc(FOURCC('a','8','4','4'));
	EV_UnknownFunc(FOURCC('a','8','4','8'));
	return;
}

static void SetCEWP_MTWK_FlagTo2_Wrapper(void)
{
	SetCEWP_MTWK_FlagTo2(FOURCC('R', 'Y', 'O', '_'));
	SetCEWP_MTWK_FlagTo2(FOURCC('S', 'I', 'N', '_'));
        
	EV_UnknownFunc(FOURCC('a','9','8','8'));
	EV_UnknownFunc(FOURCC('a','9','9','0'));
	EV_UnknownFunc(FOURCC('a','9','9','2'));
	EV_UnknownFunc(FOURCC('a','9','9','4'));
	EV_UnknownFunc(FOURCC('a','8','4','0'));
	EV_UnknownFunc(FOURCC('a','8','4','2'));
	EV_UnknownFunc(FOURCC('a','8','4','4'));
	EV_UnknownFunc(FOURCC('a','8','4','8'));
	return;
}

static void CutsceneHandler(astruct_86 *evt_ctx)
{
	int iVar1 = FUN_0c1542c0(-1);
	if (iVar1 == 0) {
		SetCEWP_MTWK_FlagTo0_Wrapper();
		*(undefined2 *)&evt_ctx->pTASK->field7_0xa = 0;
		if (*(short *)&evt_ctx->pTASK->field5_0x8 == 3) {
			//FUN_0c0540e0((HLib_Task_t *)0x7f148d12);
		}
		if (*(short *)&evt_ctx->pTASK->field5_0x8 == 0) {
			FUN_0c093d20();
			SetTaskDestroyCallback(evt_ctx->pTASK, (undefined *)0x1e);
		}
		else {
			FUN_0c093d20();
		}
		FUN_0c054200();
	}
	return;
}

static void InitCutscene(int scene_num)
{
	uint uVar1;
	uint uVar2;
	char *cutsceneID;
	int sceneID;
  
	FUN_0c171e80(&unk_struct);
	unk_struct.field5_0x5 = '\0';
  
	undefined4 *tmp_AFS = evl_AFS_Utils(0,IsLoaded,"KWW1",(uint *)0x0,0);
	if (tmp_AFS != (undefined4 *)0x0) {
		evl_AFS_Utils(0,IsLoaded_6,"KWW1",(uint *)0x0,0);
	}
        
	tmp_AFS = evl_AFS_Utils(0,IsLoaded,"KWA1",(uint *)0x0,0);
	if (tmp_AFS != (undefined4 *)0x0) {
		evl_AFS_Utils(0,IsLoaded_6,"KWA1",(uint *)0x0,0);
	}
        
	tmp_AFS = evl_AFS_Utils(0,IsLoaded,"KWA2",(uint *)0x0,0);
	if (tmp_AFS != (undefined4 *)0x0) {
		evl_AFS_Utils(0,IsLoaded_6,"KWA2",(uint *)0x0,0);
	}

	char *sceneDirectory;
	if (scene_num == 0) {
		unk_struct.field4_0x4 = '\b';
    
		sceneDirectory = Filepath_Generator(SceneDirectory);
		evl_AFS_Utils(0,MOUNT_AFS_PARTITION,sceneDirectory,(uint *)"KWW1",0);
		evl_AFS_Utils(0,NewLoadPAK,(char *)0x0,(uint *)0x0,0);
		cutsceneID = "KWW1";
		sceneID = scene_num;
	}
	else {
		if ((scene_num < 0) || (2 < scene_num)) {
			unk_struct.field4_0x4 = '\x12';
      
			sceneDirectory = Filepath_Generator(SceneDirectory);
			cutsceneID = "KWA2";
		}
		else {
			unk_struct.field4_0x4 = '\x12';
      
			sceneDirectory = Filepath_Generator(SceneDirectory);
			cutsceneID = "KWA1";
		}
                
		evl_AFS_Utils(0, MOUNT_AFS_PARTITION, sceneDirectory, (uint *)cutsceneID, 0);
                
		evl_AFS_Utils(0, NewLoadPAK, (char *)0x0, (uint *)0x0, 0);
                
		sceneID = 0;
	}
  
	evl_AFS_Utils(2, WAIT_PAK_LOAD, cutsceneID, (uint *)0x0, sceneID);
	FUN_0c171e00(&unk_struct);
  
	FUN_0c118220();
	if (scene_num == 1) {
		FUN_0c0939a0(2,0);
	}
	else {
		if (scene_num == 3) {
			uVar2 = 0;
			FUN_0c094520(0xc, 0);
			uVar1 = FOURCC('l','1','4','1');
		}
		else {
			if (scene_num != 4) {
				FUN_0c0c1120(1);
				FUN_0c0c01c0(0, 2);
				FUN_0c0c0020(0, 1);
				return;
			}
			uVar2 = 0;
			FUN_0c094520(0xc, 0);
			uVar1 = FOURCC('l','1','5','1');
		}
		FUN_0c0c1cc0(uVar1, uVar2);
		FUN_0c118000();
	}
	return;
}

static void CutscenePlayStateHandler(astruct_86 *evt_ctx)
{
	HLib_Task_t *EVNT = EnqueueTaskWithParameter(CutsceneHandler, 0x04, 0xb, 8, FOURCC('E','V','N','T'));
	astruct_89 *ppaVar2 = (astruct_89 *)GetTaskParameterPointer(EVNT);
	ppaVar2->field0_0x0 = (astruct_88*)evt_ctx;
	ppaVar2->field1_0x4 = 0;
	if (evt_ctx->scene_num == 3) {
                //EnqueueTaskWithoutParameter (FUN_0517_runtime__0c348760_fsca_wrapper3,'\x04',0xb,0x544e5645);
	}
	FUN_0c1b0ce0();
	if (evt_ctx->scene_num == 4) {
		FUN_0c1afdc0(1,0,0);
	}
	else {
		FUN_0c1afdc0(1,0,0);
	}
	FUN_0c1b0b40();
	FUN_0c093d20();
	SetCEWP_MTWK_FlagTo2_Wrapper();
	FUN_0c1542c0((int)(short)evt_ctx->scene_num);
	evt_ctx->cur_state = 2;
	return;
}

static void MainStateHandler(astruct_86 *evt_ctx)
{
        if (evt_ctx->cur_state == START_CUTSCENE) 
        {
                CutscenePlayStateHandler(evt_ctx);
        }
        else if (evt_ctx->cur_state < UNK_STATE) 
        {
                if (evt_ctx->cur_state == SELECT_CUTSCENE) 
                {
                        // handle button presses
                        uint controllerData = EVT_GetControllerInput(0, 1);
                        if (controllerData == A_BTN) 
                        {
                                evt_ctx->cur_state = START_CUTSCENE;
                                
                                InitCutscene((int)(short)evt_ctx->scene_num);
                        } 
                        else 
                        {
                                // Left = Backwards
                                if (controllerData == LEFT) 
                                {
                                        evt_ctx->scene_num--;
                                        if (evt_ctx->scene_num == (MIN_CUTSCENE_ID - 1) || evt_ctx->scene_num == 0xFFFF)
                                                evt_ctx->scene_num = MAX_CUTSCENE_ID;
                                } 
                                // Right = Forwards
                                else if (controllerData == RIGHT) 
                                {
                                        evt_ctx->scene_num++;
                                        if (MAX_CUTSCENE_ID < evt_ctx->scene_num)
                                                evt_ctx->scene_num = MIN_CUTSCENE_ID;
                                }
                        }
        
                        // output current selection
                        set_debug_screen_text_position(2,4); 
                        switch(evt_ctx->scene_num) {
                                case 0:
                                        debug_log_to_screen("0517A000.c\n");
                                        break;
                                case 1:
                                        debug_log_to_screen("0517A011.c\n");
                                        break;
                                case 2:
                                        debug_log_to_screen("0517A012.c\n");
                                        break;
                                case 3:
                                        debug_log_to_screen("0517A014.c\n");
                                        break;
                                case 4:   
                                        debug_log_to_screen("0517A015.c\n");
                        }
                        set_debug_screen_text_position(2,5);
                        debug_log_to_screen("seqdata%x.avb\n", evt_ctx->scene_num);
                }
        }
        else if (evt_ctx->cur_state == LOAD_STATE) 
        {
                //AllocateEventStorageWrapper(evt_ctx);
        }
        return;
}
void LoadWCONDBin(void)
{
        EV_SetPlayerControlFlags(0);
        FUN_0c1a93c0(1, (uint *)"0517");
        
        char* path = Filepath_Generator(SceneDirectory);
        LoadFile_Wrapper(path, "W_COND.BIN");
        return;
}

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

void _entry start(void)
{
        HLib_Task_t* EVNT = EnqueueTaskWithParameter(MainStateHandler, 0x04, 0xb, 0xc, FOURCC('E','V','N','T'));
        astruct_86 * EVNT_params = (astruct_86 *)GetTaskParameterPointer(EVNT);
        EVNT_params->pTASK = EVNT;
        
        unsigned int scene = *(int*)(0x0c020164);
        unsigned int area  = *(int*)(0x0c020168);
        
        int MOTI = ReadMotiFromDirectory(scene, area, "0517A.MOT");  
        EVNT_params->MOTI_memblock = MOTI;
        EVNT_params->scene_num = 0;
        EVNT_params->cur_state = 0;
        
        LoadWCONDBin();
        FUN_0c1003a0();
        
        EV_NPC_NewLoadSw(0);
        FUN_0c1003a0();
        
        //if (TASK != (HLib_Task_t *)0x0) {
                // SetTaskDestroyCallback(TASK, (undefined *)0x0);
        //}
        // EnqueueTaskWithoutParameter(LOAD_Callback, 0x06,0xb,0x64616f6c);
}