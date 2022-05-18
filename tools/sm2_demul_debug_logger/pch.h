#ifndef PCH_H
#define PCH_H
#include "framework.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <Psapi.h>
#include <string>
#include <fstream>
#include <ostream>

#define APP_TITLE                                                               L"demul_sm2_debug_logger"
#define APP_VER                                                                 L"0.1.2"
#define APP_STR                                                                 APP_TITLE L" " APP_VER

#define LOG_BUFFER_SIZE                                                         8192

#define DEMUL_EXEC_BASE                                                         0x2C000000              // 8c010000 location in Demul RAM

#define SM2_SCREEN_DEBUG_TEXT_BUFFER_GAMEJAM                                    0x2F4510
#define SM2_DEBUG_LOG_TO_SCREEN_ADDRESS_GAMEJAM                                 0xC1DC400

#define SM2_SCREEN_DEBUG_TEXT_BUFFER_US                                         0x3072A0
#define SM2_DEBUG_LOG_TO_SCREEN_ADDRESS_US                                      0x8C1E3EA0

#define SM2_SCREEN_DEBUG_TEXT_BUFFER_JP_RETAIL                                  0x3086E0
#define SM2_DEBUG_LOG_TO_SCREEN_ADDRESS_JP_RETAIL                               0x8C1E4220
#define SM2_SET_DEBUG_TEXT_POSITION_ADDRESS_JP_RETAIL                           0x8C1E4120

#define SM2_DEBUG_LOG_TO_SCREEN_TABLE_ENTRY                                     0x202A0
#define SM2_SET_DEBUG_TEXT_POSITION_ENTRY                                       0x2029C

#define SM2_DEBUG_LOG_TO_CONSOLE_TABLE_ENTRY                                    0x20298
#define SM2_DEBUG_LOG_TO_CONSOLE_TABLE_ENTRY_2                                  0x20294

#define GAMEJAM_DEBUG_ENABLE_PATCH_OFFSET                                       0x254840
#define GAMEJAM_DEBUG_ENABLE_PATCH                                              0x5840

#define GAMEJAM_TIMESTAMP_ADDR                                                  0x22472C
#define GAMEJAM_TIMESTAMP                                                       0x20766F4E

#define US_TIMESTAMP_ADDR                                                       0x230F78
#define US_TIMESTAMP                                                            0x20706553

#define JP_RETAIL_TIMESTAMP_ADDR                                                0x230E18
#define JP_RETAIL_TIMESTAMP                                                     0x206C754A

#define CHECK(addr,type,value)                                                  *(type*)(executableBase + addr) == value
#define CHECKN(addr,type,value)                                                 *(type*)(executableBase + addr) != value
#define READ(addr,type)                                                         *(type*)(executableBase + addr)
#define PATCH(addr,type,value)                                                  *(type*)(executableBase + addr) = value
#define CHECK_AND_PATCH(addr,type,value)                                        if (CHECKN(addr,type,value))    \
                                                                                        PATCH(addr,type,value)


#endif //PCH_H