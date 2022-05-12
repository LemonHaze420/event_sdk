/*
        Shenmue II Event Script SDK
        
        Name:           Cutscene Viewer
        Description:    A sample debug cutscene viewer based on 0517.EV3.
*/
#include "common.h"

unsigned char s_SIN__0517_runtime__0c348e04[] = {
     0x53, 0x49, 0x4e, 0x5f, 0xff, 0xff, 0xff, 0xff, 0x00 , 0x00 , 0x00 , 0x00, 0x00, 
};

unsigned char tmp[7] = { 
        0,0,0,0,0,0,0 
};

enum State {
        SELECT_CUTSCENE         = 0,
        START_CUTSCENE          = 1,
        UNK_STATE               = 2,
        LOAD_STATE              = 3,
        
};

__FORCEINLINE void FUN_0517_runtime__0c348960_SetCharacterFlags() {
  FUN_0c0932c0(0x5f4f5952);
  FUN_0c0932c0(0x5f4e4953);
  FUN_0c0932c0(0x38383961);
  FUN_0c0932c0(0x30393961);
  FUN_0c0932c0(0x32393961);
  FUN_0c0932c0(0x34393961);
  FUN_0c0932c0(0x30343861);
  FUN_0c0932c0(0x32343861);
  FUN_0c0932c0(0x34343861);
  FUN_0c0932c0(0x38343861);
}

void FUN_0517_runtime__0c348680(astruct_86 *param_1)
{
  int iVar1 = FUN_0c1542c0(-1);
  if (iVar1 == 0) {
    FUN_0517_runtime__0c348960_SetCharacterFlags();
    *(undefined2 *)((int)param_1->pTASK + 10) = 0;
    if (*(short *)(param_1->pTASK + 2) == 3) {
      FUN_0c0540e0((HLib_Task_t *)0x7f148d12);
    }
    if (*(short *)(param_1->pTASK + 2) == 0) {
      FUN_0c093d20();
      SetTaskDestroyCallback((HLib_Task_t *)param_1->pTASK,(undefined *)0x1e);
    }
    else {
      FUN_0c093d20();
    }
    FUN_0c054200();
  }
  return;
}
void FUN_0517_runtime__0c348760(ulonglong param_1)
{
  FUN_0c093320();
  FUN_0c093320();
  FUN_0c093320();
  FUN_0c093320();
  return;
}
static void SetState2_And_EnqueueTasks(astruct_86 *evt_ctx)
{
  HLib_Task_t* pHVar1 = EnqueueTaskWithParameter(FUN_0517_runtime__0c348680,'\x04',0xb,8,0x544e5645);
  astruct_89* ppaVar2 = (astruct_89 *)GetTaskParameterPointer(pHVar1);
  ppaVar2->field0_0x0 = (astruct_88 *)evt_ctx;
  ppaVar2->field1_0x4 = 0;
  
  if (evt_ctx->scene_num == 3) {
    HLib_Task_t* tmp = EnqueueTaskWithoutParameter(FUN_0517_runtime__0c348760,'\x04',0xb,0x544e5645);
  }
  
  FUN_0c1b0ce0();
  FUN_0c1afdc0(1,0,0);
  FUN_0c1b0b40();
  FUN_0c093d20();
  FUN_0517_runtime__0c348960_SetCharacterFlags();  
  FUN_0c1542c0((int)(short)evt_ctx->scene_num);
  evt_ctx->cur_state = 2;
  return;
}

static void StartCutscene(int scene_num)
{
  FUN_0c171e80(tmp);
  
  undefined4 *tmp_AFS = evl_AFS_Utils(0,IsLoaded,"KWW1",(uint *)0x0,0);
  if (tmp_AFS != (undefined4 *)0x0) {
    evl_AFS_Utils(0,IsLoaded_6,"KWW1",(uint *)0x0,0);
  }
  evl_AFS_Utils(0,IsLoaded,"KWA1",(uint *)0x0,0);
  return;
}
void FUN_0517_runtime__0c348ce0(int param_1)
{
  EV_EnableCharDisplay();
  FUN_0c077280();
  FUN_0c077280();
  FUN_0c092520();
  FUN_0c0932c0(param_1);
  return;
}
void FUN_0517_runtime__LOAD_Callback(void)
{
  int iVar1 = FUN_0c1005e0(*(int*)0x89023216);
  if (iVar1 != 0) {
    FUN_0517_runtime__0c348ce0(*(int*)0x89023216);
    iVar1 = EV_DispUpHandModel();
    LoadHandsMaybe(iVar1);
    *(unsigned int*)(0x0c348e1c) = *(unsigned int*)(0x8902321a);
    *(unsigned int*)(0x0c348e20) = 0;
    if (*(unsigned int*)(0x8902321a) == -1) {
      *(unsigned int*)(0x0c348e24) = 1;
      FUN_0c054880((undefined4 *)&*(int*)0x8d193210);
      TaskCleanupCurrentTask();
    }
  }
  return;
}


static void EnqueueLoad(undefined4 param_1,astruct_166 *param_2)
{  
  EV_NPC_NewLoadSw(0);
  FUN_0c1003a0();
  if (param_2 != (astruct_166 *)0x0) {
    SetTaskDestroyCallback((HLib_Task_t *)param_2,(undefined *)0x0);
  }
  EnqueueTaskWithoutParameter(FUN_0517_runtime__LOAD_Callback,'\x06',0xb,0x64616f6c);
  return;
}
void FUN_0517_runtime__0c348c60(int *param_1)
{
  int iVar2 = *param_1;
  while (iVar2 != -1) {
    bool bVar1 = EV_IsCharacterExist(param_1);
      FUN_0c100100(*param_1);
      FUN_0c1007e0(*param_1);
    param_1 = param_1 + 1;
    iVar2 = *param_1;
  }
  return;
}
void FUN_0517_runtime__0c348860(astruct_86 *param_1)

{
  FUN_0517_runtime__0c348c60((int *)s_SIN__0517_runtime__0c348e04);
  FUN_0c1a93c0(0,(uint *)"0517");
  FUN_0c0e9320(param_1->MOTI_memblock);
  FUN_0c054220((HLib_Task_t *)param_1->pTASK);
  FUN_0c093e60(*(undefined4*)0x0c020164,0x4151574b,0);
  return;
}

static void DebugSelector_EVNT_Callback(astruct_86 *evt_ctx)
{
  short state = evt_ctx->cur_state;
  if (state == START_CUTSCENE) {
    SetState2_And_EnqueueTasks(evt_ctx);
  }
  else if (state < UNK_STATE) {
    if (state == SELECT_CUTSCENE) {
      uint controllerData = EVT_GetControllerInput(0,1);
      if (controllerData == A_BTN) {
        evt_ctx->cur_state = START_CUTSCENE;
        StartCutscene((int)(short)evt_ctx->scene_num);
      }
      else {
        if (controllerData == LEFT) {
          evt_ctx->scene_num = evt_ctx->scene_num + -1;
          if (evt_ctx->scene_num < 0) {
            evt_ctx->scene_num = 4;
          }
        } else if (controllerData == RIGHT) {
          evt_ctx->scene_num = evt_ctx->scene_num + 1;
          if (4 < evt_ctx->scene_num) {
            evt_ctx->scene_num = 0;
          }
        }
      }
      
      switch(evt_ctx->scene_num) {
              case 0:
                set_debug_screen_text_position(2,4);
                debug_log_to_screen("0517A000.c\n");
                break;
              case 1:
                set_debug_screen_text_position(2,4);
                debug_log_to_screen("0517A011.c\n");
                break;
              case 2:
                set_debug_screen_text_position(2,4);
                debug_log_to_screen("0517A012.c\n");
                break;
              case 3:
                set_debug_screen_text_position(2,4);
                debug_log_to_screen("0517A014.c\n");
                break;
              case 4:
                set_debug_screen_text_position(2,4);    
                debug_log_to_screen("0517A015.c\n");
      }
      set_debug_screen_text_position(2,5);
      debug_log_to_screen("seqdata%x.avb\n", evt_ctx->scene_num);
    }
  }
  else if (state == LOAD_STATE) {
    FUN_0517_runtime__0c348860(evt_ctx);
  }
  return;
}

void _entry start(void)
{
  HLib_Task_t* EVNT = EnqueueTaskWithParameter(DebugSelector_EVNT_Callback, '\x04',0xb,0xc,0x544e5645);
  astruct_86 * EVNT_params = (astruct_86 *)GetTaskParameterPointer(EVNT);
  memset((char*)EVNT_params, 0x00, sizeof(astruct_86));
  EVNT_params->pTASK = &EVNT->taskCallback;
  
  unsigned int scene = *(int*)(0x0c020168);
  int MOTI = ReadMotiFromDirectory(scene, "0517A.MOT");  
  EVNT_params->MOTI_memblock = MOTI;
  EVNT_params->scene_num = 0;
  EVNT_params->cur_state = 0;
  
  EV_SetPlayerControlFlags(0);
  FUN_0c1a93c0(1, (uint*)"0517");
  LoadFile_Wrapper(Filepath_Generator(SceneDirectory),"W_COND.BIN");
}