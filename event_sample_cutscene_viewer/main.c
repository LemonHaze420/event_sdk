/*
        Shenmue II Event Script SDK
        
        Name:           Cutscene Viewer
        Description:    A sample debug cutscene viewer based on 0517.EV3.
*/
#include "common.h"
#include "cutscene_viewer.h"

static astruct_86 * g_evt_ctx;

static void debug_info_callback(void)
{
        if (bDisplay)
        {
                set_debug_screen_text_position(10, 1);
                debug_log_to_screen("LemonHaze420 - 2022\n");
                
                set_debug_screen_text_position(1, 10);
                debug_log_to_screen("%s\narea = %c%c%c%c\nentry = %d\n",        GetCurrentTake(), 
                                                                                GetCurrentArea(), 
                                                                                GetCurrentArea() >> 8, 
                                                                                GetCurrentArea() >> 16, 
                                                                                GetCurrentArea() >> 24, 
                                                                                GetCurrentEntry());
                                                                                
                debug_log_to_screen("disk = %d \nfile = %s\ndire = %s\n",       GetCurrentDiskNum(), 
                                                                                GetCurrentOpenedFile(), 
                                                                                GetCurrentDirectoryEntry());
                                                                                
                debug_log_to_screen("task = %c%c%c%c\n",                        GetCurrentTaskName(),  
                                                                                GetCurrentTaskName() >> 8,  
                                                                                GetCurrentTaskName() >> 16,  
                                                                                GetCurrentTaskName() >> 24);
                debug_log_to_screen("step = %d\n", GetCurrentStep());
        }
        
        uint controller_input = EVT_GetControllerInput(0, 2);
        if (controller_input & UP)
                bDisplay = !bDisplay;
        else if (controller_input & DOWN)
                ToggleUI();   
        else if (controller_input & LEFT)
                EV_SetPlayerControlFlags(1);   
        else if (controller_input & RIGHT)
                EV_SetPlayerControlFlags(0);         
        return;
}

void _entry start()
{
        EnqueueTaskWithoutParameter(debug_info_callback, 0x4, 0xb, DBGT_NAME);
        init_cutscene_viewer();
        return;
}

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
	SetCEWP_MTWK_FlagTo0(RYO_);
	SetCEWP_MTWK_FlagTo0(SIN_);
        
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
	SetCEWP_MTWK_FlagTo2(RYO_);
	SetCEWP_MTWK_FlagTo2(SIN_);
        
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
			FreeTask(evt_ctx->pTASK);
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
	unk_struct.field5_0x5 = 0x0;
  
	undefined4 *tmp_AFS = evl_AFS_Utils(0, IsLoaded, MAP1_NAME, (uint *)0x0,0);
	if (tmp_AFS != (undefined4 *)0x0) {
		evl_AFS_Utils(0, IsLoaded_6, MAP1_NAME, (uint *)0x0,0);
	}
        
	tmp_AFS = evl_AFS_Utils(0,IsLoaded, MAP2_NAME, (uint *)0x0,0);
	if (tmp_AFS != (undefined4 *)0x0) {
		evl_AFS_Utils(0, IsLoaded_6, MAP2_NAME, (uint *)0x0,0);
	}
        
	tmp_AFS = evl_AFS_Utils(0,IsLoaded, MAP3_NAME, (uint *)0x0,0);
	if (tmp_AFS != (undefined4 *)0x0) {
		evl_AFS_Utils(0, IsLoaded_6, MAP3_NAME, (uint *)0x0,0);
	}

	char *sceneDirectory = Filepath_Generator(SceneDirectory);
	if (scene_num == 0) {
		unk_struct.field4_0x4 = '\b';
    
		evl_AFS_Utils(0, MOUNT_AFS_PARTITION, sceneDirectory, (uint *)MAP1_NAME,0);
		evl_AFS_Utils(0, NewLoadPAK, (char *)0x0, (uint *)0x0,0);
		cutsceneID = MAP1_NAME;
		sceneID = scene_num;
	}
	else {
                unk_struct.field4_0x4 = '\x12';
                
		if ((scene_num < 0) || (2 < scene_num)) {
			cutsceneID = MAP3_NAME;
		} else {
			cutsceneID = MAP2_NAME;
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
			FUN_0c094520(0xc, 0);
			uVar1 = FOURCC('l','1','5','1');
		}
                uVar2 = 0;
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
        FUN_0c1afdc0(1,0,0);
	FUN_0c1b0b40();
	FUN_0c093d20();
	SetCEWP_MTWK_FlagTo2_Wrapper();
	FUN_0c1542c0((int)(short)evt_ctx->scene_num);
	evt_ctx->cur_state = UNK_STATE;
	return;
}

void UnloadCharactersInTable(int *param_1)
{  
        int iVar2 = *param_1;
        while (iVar2 != -1) {
                if (EV_IsCharacterExist(*param_1) != 0) {
                        FUN_0c100100(*param_1);
                        FUN_0c1007e0(*param_1);
                }
                param_1 = param_1 + 1;
                iVar2 = *param_1;
        }
        return;
}

static void AllocateEventStorageWrapper(astruct_86 *evt_ctx)
{
        UnloadCharactersInTable(&character_tbl);
        FUN_0c1a93c0(0, (uint *)"0517");
        FUN_0c0e9320(evt_ctx->MOTI_memblock);
        FreeTask_Wrapper(evt_ctx->pTASK);
        LoadScene(GetCurrentScene(), FOURCC('K','W','Q','A'), 0);
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
                                // Right = Forwards
                                if (controllerData == LEFT || controllerData == RIGHT) 
                                {
                                        controllerData == LEFT ? evt_ctx->scene_num-- : evt_ctx->scene_num++;
                                        
                                        if (evt_ctx->scene_num == (MIN_CUTSCENE_ID - 1) || evt_ctx->scene_num == 0xFFFF)
                                                evt_ctx->scene_num = MAX_CUTSCENE_ID;
                                        
                                        if (MAX_CUTSCENE_ID < evt_ctx->scene_num)
                                                evt_ctx->scene_num = MIN_CUTSCENE_ID;
                                }
                        }
        
                        // output current selection
                        set_debug_screen_text_position(2, 4); 
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
                        set_debug_screen_text_position(2, 5);
                        debug_log_to_screen("seqdata%x.avb\n", evt_ctx->scene_num);
                }
        }
        else if (evt_ctx->cur_state == LOAD_STATE) 
        {
                AllocateEventStorageWrapper(evt_ctx);
        }
        return;
}

void LoadWCONDBin(void)
{
        EV_SetPlayerControlFlags(0);
        FUN_0c1a93c0(1, (uint *)SEQ_NAME);
        
        char* path = Filepath_Generator(SceneDirectory);
        LoadFile_Wrapper(path, W_COND_N);
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

static void SetEnableCharacterFlags(int chara_id)
{
        EV_EnableCharDisplay(chara_id);
        FUN_0c077280();
        FUN_0c077280();
        FUN_0c092520();
        EV_UnknownFunc(chara_id);
        return;
}

static void LOAD_Callback(void)
{
        int *tmp_ptr, *next_ptr;
        int is_valid;
                
        if (global_init == 0) {
                FUN_0c0ffe80(*global_chara_tbl_ptr);
                FUN_0c1005e0(*global_chara_tbl_ptr);
                global_init = 1;
        }
        else {
                is_valid = FUN_0c1005e0(*global_chara_tbl_ptr);
                if (is_valid != 0) {
                        SetEnableCharacterFlags(*global_chara_tbl_ptr);
                        if (global_should_load_hi_poly_hands_flag != 0) {
                                int should_load_hands = EV_DispUpHandModel(*global_chara_tbl_ptr);
                                AllocateHNDL_HNDR_ForChara(should_load_hands);
                        }
                        
                        next_ptr = global_chara_tbl_ptr + 1;
                        global_init = 0;
                        
                        tmp_ptr = global_chara_tbl_ptr + 1;
                        global_chara_tbl_ptr = next_ptr;
                        
                        if (*tmp_ptr == -1) {
                                global_has_loaded_flag = 1;
                                if (global_load_task_ptr != (HLib_Task_t *)0x0) {
                                        SetMainCallbackToDestroy(global_load_task_ptr);
                                }
                                TaskCleanupCurrentTask();
                        }
                }
        }
        return;  
}

static void EnqueueLoad(undefined4 chara_tbl, HLib_Task_t* TASK)
{
        global_init = 0;
        global_has_loaded_flag = 0;
        global_chara_tbl_ptr = chara_tbl;
        global_load_task_ptr = TASK;    
        
        EV_NPC_NewLoadSw(0);
        FUN_0c1003a0();
        if (TASK != (HLib_Task_t *)0x0) 
               SetTaskDestroyCallback(TASK, (undefined *)0x0);
        
        EnqueueTaskWithoutParameter(LOAD_Callback, 6, 0xb, LOAD_NAME);
        return;        
}

void init_cutscene_viewer(void)
{
        HLib_Task_t* EVNT = EnqueueTaskWithParameter(MainStateHandler, 0x04, 0xb, 0xc, CVWR_NAME);
        astruct_86 * EVNT_params = (astruct_86 *)GetTaskParameterPointer(EVNT);
        EVNT_params->pTASK = EVNT;
        g_evt_ctx = EVNT_params;
        
        int MOTI = ReadMotiFromDirectory(GetCurrentScene(), GetCurrentArea(), MOT_NAME);  
        EVNT_params->MOTI_memblock = MOTI;
        EVNT_params->scene_num = 0;
        EVNT_params->cur_state = 0;
        
        LoadWCONDBin();
        
        EnqueueLoad(&character_tbl, EVNT_params->pTASK);
}