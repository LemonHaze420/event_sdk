/*
        Shenmue II Event Script SDK
        
        Name:           Cutscene Viewer
        Description:    A sample debug cutscene viewer based on 0517.EV3.
*/
#include "common.h"
#include "cutscene_viewer.h"
 
#define MIN_CUTSCENE_ID 0
#define MAX_CUTSCENE_ID 4

static char s_SIN__0517_runtime__0c348e04[] = { 0x53, 0x49, 0x4e, 0x5f, 0xff, 0xff, 0xff, 0xff };

void SetCharacterFlags_Wrapper(int param_1)
{
  return;
}
void SetCharacterFlags2_Wrapper(int param_1)
{
  return;
}
void SetCharacterFlags(void)
{
  return;
}
void SetCharacterFlagsAndHandleTaskDestroy(astruct_86 *evt_ctx)
{  
  return;
}
void FUN_0517_runtime__0c348760()
{
  return;
}
void FUN_0517_runtime__0c3489e0(int param_1)
{
  return;
}
void FUN_0517_runtime__0c348a60(int param_1)
{
  return;
}
void FUN_0517_runtime__0c3488e0(void)
{
  return;
}
void HandleStartCutsceneState(astruct_86 *evt_ctx)
{
  return;
}

static astruct_193 unk_struct;

void StartCutscene(int scene_num)
{
  undefined4 *tmp_AFS;
  char *sceneDirectory;
  uint uVar1;
  uint uVar2;
  char *cutsceneID;
  int sceneID;
  
  FUN_0c171e80(&unk_struct);
  unk_struct.field5_0x5 = '\0';
  
  tmp_AFS = evl_AFS_Utils(0,IsLoaded,"KWW1",(uint *)0x0,0);
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
      FUN_0c094520(0xc,0);
      uVar1 = 0x3134316c;
    }
    else {
      if (scene_num != 4) {
        FUN_0c0c1120(1);
        FUN_0c0c01c0(0,2);
        FUN_0c0c0020(0,1);
        goto RET;
      }
      uVar2 = 0;
      FUN_0c094520(0xc,0);
      uVar1 = 0x3135316c;
    }
    FUN_0c0c1cc0(uVar1,uVar2);
    FUN_0c118000();
  }
  
RET:
  return;
}
 
void FUN_0517_runtime__0c348c60(int *param_1)
{
  return;
}

void AllocateEventStorageWrapper(astruct_86 *param_1)
{
  return;
}
static void DebugSelector_EVNT_Callback(astruct_86 *evt_ctx)
{
        if (evt_ctx->cur_state == START_CUTSCENE) 
        {
                HandleStartCutsceneState(evt_ctx);
        }
        else if (evt_ctx->cur_state < UNK_STATE) 
        {
                if (evt_ctx->cur_state == SELECT_CUTSCENE) 
                {
                        // handle button presses
                        uint controllerData = EVT_GetControllerInput(0,1);
                        if (controllerData == A_BTN) 
                        {
                                evt_ctx->cur_state = START_CUTSCENE;
                                
                                StartCutscene((int)(short)evt_ctx->scene_num);
                        } 
                        else 
                        {
                                // Left = Backwards
                                if (controllerData == LEFT) 
                                {
                                        evt_ctx->scene_num--;
                                        if (evt_ctx->scene_num == (MIN_CUTSCENE_ID - 1))
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
        LoadFile_Wrapper(path,"W_COND.BIN");
        return;
}

void FUN_0517_runtime__LOAD_Callback(void)
{
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
        HLib_Task_t* EVNT = EnqueueTaskWithParameter(DebugSelector_EVNT_Callback, 0x04, 0xb, 0xc, 0x544e5645);
        astruct_86 * EVNT_params = (astruct_86 *)GetTaskParameterPointer(EVNT);
        EVNT_params->pTASK = &EVNT->taskCallback;
        
        unsigned int scene = *(int*)(0x0c020164);
        unsigned int area  = *(int*)(0x0c020168);
        int MOTI = ReadMotiFromDirectory(scene, area, "0517A.MOT");  
        EVNT_params->MOTI_memblock = MOTI;
        EVNT_params->scene_num = 0;
        EVNT_params->cur_state = 0;
        
        LoadWCONDBin();
        
        EV_NPC_NewLoadSw(1);
        FUN_0c1003a0();
        
        //if (TASK != (HLib_Task_t *)0x0) {
                // SetTaskDestroyCallback(TASK, (undefined *)0x0);
        //}
        // EnqueueTaskWithoutParameter(FUN_0517_runtime__LOAD_Callback, 0x06,0xb,0x64616f6c);
}