#include "common.h"

#define VIEW                    FOURCC('V','I','E','W')

struct SceneInfo {
        public:
                int SceneID;
                int AreaID;
                const char* description;
                const char* location;
};

static SceneInfo g_sceneinfos[] = {
        { 01,  AK00,         "Fortune's Pier (Main Area)",                                       "Aberdeen"                                                                            },
        { 01,  AKS0,         "Forturne's Eatery",                                                "Aberdeen"                                                                            },
        { 01,  AKS1,         "Blue Sky",                                                         "Aberdeen"                                                                            },
        { 01,  AR01,         "Fortune's Pier",                                                   "Aberdeen"                                                                            },
        { 01,  AR03,         "Queen's Street",                                                   "Aberdeen"                                                                            },
        { 01,  AR09,         "Queen's Street (Unknown Copy)",                                    "Aberdeen"                                                                            },
        { 01,  ARA0,         "Bar Swing",                                                        "Aberdeen"                                                                            },
        { 01,  ARZ0,         "General Store",                                                    "Aberdeen"                                                                            },
        { 01,  ARM0,         "Hong Kong Souveniers",                                             "Aberdeen"                                                                            },
        { 01,  ARSF,         "Rooftop Fight",                                                    "Aberdeen"                                                                            },
        { 01,  ARC0,         "Pigeon Cafe",                                                      "Aberdeen"                                                                            },
        { 01,  AKT0,         "Gambling Warehouse 0",                                             "Aberdeen"                                                                            },
        { 01,  AKT1,         "Gambling Warehouse 1",                                             "Aberdeen"                                                                            },
        { 01,  AKT2,         "Gambling Warehouse 2",                                             "Aberdeen"                                                                            },
        { 01,  AKT3,         "Gambling Warehouse 3",                                             "Aberdeen"                                                                            },
        { 01,  AKY0,         "Warehouse F",                                                      "Aberdeen"                                                                            },
        { 01,  AR02,         "Worker's Pier",                                                    "Aberdeen"                                                                            },
        { 01,  AK09,         "Fortune's Pier (Unknown Copy)",                                    "Aberdeen"                                                                            },
        { 01,  WB00,         "Scarlet Hills",                                                    "Wan Chai"                                                                            },
        { 01,  WE00,         "Golden Quarter",                                                   "Wan Chai"                                                                            },
        { 01,  WECF,         "Moon Cafe",                                                        "Wan Chai"                                                                            },
        { 01,  WEM1,         "S.I.C. Pool Hall",                                                 "Wan Chai"                                                                            },
        { 01,  WET0,         "Tomato Convenience Store",                                         "Wan Chai - Golden Quarter"                                                           },
        { 01,  WEM1,         "Slot House W",                                                     "Wan Chai - Golden Quarter"                                                           },
        { 01,  WEG0,         "Pine Game Arcade",                                                 "Wan Chai - Golden Quarter"                                                           },
        { 01,  WB01,         "Man Mo Temple",                                                    "Wan Chai - Scarlet Hills"                                                            },
        { 01,  WK00,         "South Carmain Quarter",                                            "Wan Chai"                                                                            },
        { 01,  WK09,         "South Carmain Quarter (Lucky Hit Job)",                            "Wan Chai"                                                                            },
        { 01,  WKA0,         "Yan Tin Apartments",                                               "Wan Chai - South Carmain Quarter"                                                    },
        { 01,  WN00,         "Lucky Charm Quarter",                                              "Wan Chai"                                                                            },
        { 01,  WR00,         "White Dynasty Quarter",                                            "Wan Chai"                                                                            },
        { 01,  WRS2,         "Bar Liverpool",                                                    "Wan Chai - White Dynasty Quarter"                                                    },
        { 01,  WS00,         "Green Market Quarter",                                             "Wan Chai"                                                                            },
        { 01,  WS09,         "Green Market Quarter (Lucky Hit Job)",                             "Wan Chai"                                                                            },
        { 01,  WSG1,         "Green Market Quarter (Guang Martial Arts School)",                 "Wan Chai - Green Market Quarter"                                                     },
        { 01,  WSY0,         "Come Over Guest House",                                            "Wan Chai - Green Market Quarter"                                                     },
        { 01,  WT00,         "Wise Mens Quarter",                                                "Wan Chai"                                                                            },
        { 01,  WTA0,         "Da Yuan Apartments",                                               "Wan Chai"                                                                            },
        { 01,  AR01,         "Worker's Pier (Intro Area + Free Stay Lodge)",                     "Aberdeen"                                                                            },
        { 02,  AB00,         "Beverly Hills Wharf",                                              "Aberdeen"                                                                            },
        { 02,  WBBK,         "Scarlet Hills (Airing Out Books)",                                 "Wan Chai"                                                                            },
        { 03,  Q100,         "Thousand White Quarter",                                           "Kowloon"                                                                             },
        { 03,  Q109,         "Thousand White Quarter (Unknown Copy)",                            "Kowloon"                                                                             },
        { 03,  Q200,         "Stand Quarter",                                                    "Kowloon"                                                                             },
        { 03,  Q300,         "Dimsum Quarter",                                                   "Kowloon"                                                                             },
        { 03,  QA00,         "Three Birds Building",                                             "Kowloon - Dimsum Quarter"                                                            },
        { 03,  QA11,         "Three Birds Roof",                                                 "Kowloon - Dimsum Quarter - Three Birds Building"                                     },
        { 03,  QA22,         "Slot House K",                                                     "Kowloon - Dimsum Quarter - Dimsum Building"                                          },
        { 03,  QAW1,         "Dimsum Building",                                                  "Kowloon - Dimsum Quarter"                                                            },
        { 03,  QAW6,         "Dancing Dragon Building",                                          "Kowloon - Stand Quarter"                                                             },
        { 03,  QB00,         "Great View Building",                                              "Kowloon - Thousand White Quarter"                                                    },
        { 03,  QBAA,         "Great View Herbs",                                                 "Kowloon - Thousand White Quarter - Great View Building"                              },
        { 03,  QC00,         "Thousand White Building",                                          "Kowloon - Thousand White Quarter"                                                    },
        { 03,  QC01,         "Thousand White Building (Unknown Copy)",                           "Kowloon - Thousand White Quarter"                                                    },
        { 03,  QC06,         "Thousand White Building (Unknown Copy)",                           "Kowloon - Thousand White Quarter"                                                    },
        { 03,  QCAE,         "Thousand White Warehouse",                                         "Kowloon - Thousand White Quarter"                                                    },
        { 03,  QD00,         "Ghost Hall Building",                                              "Kowloon - Thousand White Quarter"                                                    },
        { 03,  QD01,         "God of Wealth Building",                                           "Kowloon - Thousand White Quarter"                                                    },
        { 03,  QDKJ,         "Five Stars Corp. (Yuanda Zhu's Room)",                             "Kowloon - Thousand White Quarter - Ghost Hall Building (10th Floor)"                 },
        { 03,  QE00,         "Moon Child Building",                                              "Kowloon - Stand Quarter"                                                             },
        { 03,  QE01,         "Moon Child Building (Unknown Copy)",                               "Kowloon - Stand Quarter"                                                             },
        { 03,  QE03,         "Golden Flower Building",                                           "Kowloon - Stand Quarter"                                                             },
        { 03,  QE09,         "Black Heaven Building",                                            "Kowloon - Stand Quarter"                                                             },
        { 03,  QEDJ,         "Yuan's Room",                                                      "Kowloon - Stand Quarter - Golden Flower Building (4th Floor)"                        },
        { 03,  QEH1,         "Moon Child Orphanage",                                             "Kowloon - Stand Quarter - Moon Child Building (8th Floor)"                           },
        { 03,  QF00,         "Yellow Head Building",                                             "Kowloon - Stand, Thousand White, and Dimsum Quarters"                                },
        { 03,  QF01,         "Yellow Head Building (1st - 2nd Floors)",                          "Kowloon - Stand, Thousand White, and Dimsum Quarters"                                },
        { 03,  QF02,         "Yellow Head Building (3rd - 4th Floors)",                          "Kowloon - Stand, Thousand White, and Dimsum Quarters"                                },
        { 03,  QF06,         "Yellow Head Building (Unknown Copy)",                              "Kowloon - Stand, Thousand White, and Dimsum Quarters"                                },
        { 03,  QF39,         "Yellow Head Building (40th Floor)",                                "Kowloon - Stand, Thousand White, and Dimsum Quarters"                                },
        { 03,  QF40,         "Yellow Head Building (40th Floor Unknown Copy)",                   "Kowloon - Stand, Thousand White, and Dimsum Quarters"                                },
        { 03,  QFRR,         "Yellow Head Building Rooftop",                                     "Kowloon - Stand, Thousand White, and Dimsum Quarters"                                },
        { 03,  QGBT,         "Blue Dragon Garden",                                               "Kowloon - Stand Quarter"                                                             },
        { 03,  QJBT,         "Phoenix Building",                                                 "Kowloon - Dimsum Quarter - Tea Break Building"                                       },
        { 03,  QKBT,         "Big Ox Building (B5 Floor)",                                       "Kowloon - Yellow Head Building"                                                      },
        { 03,  QLBT,         "Black Heaven Building (Unknown Copy)",                             "Kowloon - Stand Quarter"                                                             },
        { 03,  QR00,         "Dragon Street",                                                    "Kowloon"                                                                             },
        { 03,  QR09,         "Dragon Street (Unknown Copy)",                                     "Kowloon"                                                                             },
        { 03,  QRC0,         "Huang's Room",                                                     "Kowloon - Dimsum Quarter - Tea Break Building - 9th Floor - Room 902"                },
        { 03,  QRR0,         "Ren's Hideout",                                                    "Kowloon - Dragon Street"                                                             },
        { 03,  QSFA,         "Former Barracks",                                                  "Kowloon - Thousand White Quarter (Street Fighting Area)"                             },
        { 03,  QSFB,         "Small Dragon Garden",                                              "Kowloon - Stand Quarter (Street Fighting Area)"                                      },
        { 03,  QSFD,         "Construction Base",                                                "Kowloon - Thousand White Quarter (Street Fighting Area)"                             },
        { 03,  QT09,         "???",                                                              "Kowloon - ???"                                                                       },
        { 03,  QTB1,         "Former Factory Site",                                              "Kowloon - Thousand White Quarter (Street Fighting Area)"                             },
        { 03,  QTB2,         "Old Government Office Site",                                       "Kowloon - Thousand White Quarter (Gambling Area)"                                    },
        { 03,  QTB3,         "Thunder House",                                                    "Kowloon - Dimsum Quarter (Gambling Area)"                                            },
        { 03,  QSFC,         "Star Gazing Point",                                                "Kowloon - Stand Quarter (Street Fighting Area)"                                      },
        { 03,  QTB4,         "Fighting Place",                                                   "Kowloon - Stand Quarter (Street Fighting Area)"                                      },
        { 03,  QUG0,         "Underground - ???",                                                "Kowloon - Yellow Head Building - ???"                                                },
        { 03,  QAXX,         "Handcuff QTE Jump Scene",                                          "Kowloon - QTE"                                                                       },
        { 03,  QAE1,         "Tea Break Building 1st Floor",                                     "Kowloon - Dimsum Quarter"                                                            },
        { 03,  QAE1,         "Three Birds Building 1st Floor",                                   "Kowloon - Dimsum Quarter"                                                            },
        { 03,  QAE6,         "Tea Break Building 6th Floor",                                     "Kowloon - Dimsum Quarter - Tea Break Building"                                       },
        { 03,  QAE6,         "Three Birds Building 6th Floor",                                   "Kowloon - Dimsum Quarter - Three Birds Building"                                     },
        { 03,  QABT,         "UNKNOWN (Follow Yuan Scene?)",                                     "Kowloon - UKNOWN"                                                                    },
        { 04,  KES1,         "Stone Pit",                                                        "Guilin"                                                                              },
        { 04,  KMZ1,         "Forest 1",                                                         "Guilin"                                                                              },
        { 04,  KMZ2,         "Forest 2",                                                         "Guilin"                                                                              },
        { 04,  KMZ3,         "Forest 3",                                                         "Guilin"                                                                              },
        { 04,  KMZ4,         "Forest 4",                                                         "Guilin"                                                                              },
        { 04,  KRF1,         "Kowloon (Disc 4 Intro)",                                           "Guilin"                                                                              },
        { 04,  KRH1,         "Langhuishan",                                                      "Guilin"                                                                              },
        { 04,  KSH1,         "Shenhua's House",                                                  "Guilin"                                                                              },
        { 04,  KWM1,         "Green Field",                                                      "Guilin"                                                                              },
        { 04,  KWW1,         "Path Through A Wood",                                              "Guilin"                                                                              },
        { 04,  KWW4,         "Cloud Bird Trail",                                                 "Guilin"                                                                              },
        { 04,  KSH1,         "Shenhua's House - Name Flashback",                                 "Guilin - Shenhua's House"                                                            },
        { 04,  KSH2,         "Shenhua's House - Name Flashback",                                 "Guilin - Shenhua's House"                                                            },
        { 04,  KSH3,         "Shenhua's House - Name Flashback",                                 "Guilin - Shenhua's House"                                                            },
};

static int current_selection = 0x0, current_entry_sel = 0x0;

static void list_current_selection()
{
        if (current_selection > 110 || 0 > current_selection)
                current_selection =  0x0;
        if (current_entry_sel > 99 || 0 > current_entry_sel)
                current_entry_sel = 0x0;        
        
        int Area = g_sceneinfos[current_selection].AreaID;        
        int Scene = g_sceneinfos[current_selection].SceneID;
        
        debug_log_to_screen("[%d] %s \n(%s) \n[%c%c%c%c][Disk: %d][Entry: %d]\n", current_selection, g_sceneinfos[current_selection].description, g_sceneinfos[current_selection].location, (char)Area, Area >> 8, Area >> 16, Area >> 24, Scene, current_entry_sel);
        if (GetCurrentDiskNum() != Scene)
                debug_log_to_screen("Doesn't exist on current disk! (%d != %d)\n", GetCurrentDiskNum(), Scene);
        
}
static void boot_game(void)
{
        int scene = g_sceneinfos[current_selection].SceneID;
        int area = g_sceneinfos[current_selection].AreaID;
        
        LoadScene(scene, area, current_entry_sel);
}
static void my_callback(void)
{      
        uint controller_input = EVT_GetControllerInput(0,1);
        if (controller_input & LEFT) {
                current_selection--;
        } else if (controller_input & RIGHT) {
                current_selection++;
        } else if (controller_input & RB) {
                current_entry_sel++;
                if (100 == current_entry_sel)
                        current_entry_sel = 0;
        } else if (controller_input & LB) {
                current_entry_sel--;
                if (0 > current_entry_sel)
                        current_entry_sel = 99;
        } else if (controller_input & START) {
                boot_game();
                TaskCleanupCurrentTask();
        }
        list_current_selection();
}

void _entry start(void) 
{
        current_selection = 0x0;
        current_entry_sel = 0x0;
        
        // This is needed unless 1ST_READ has been patched, or sm2_demul_logger is used, or we don't wanna run on the JP retail build
        #ifdef RETAIL_MEMORY
                *(int*)(0x8c020298) = 0x8c1e4220;            // patch in debug_log_to_file_REMOVED, replacing it for the screen func
                *(int*)(0x8c0202a0) = 0x8c1e4220;            // patch back in debug_log_to_screen
                *(int*)(0x8c02029c) = 0x8c1e4120;            // patch back in set_debug_screen_text_position
        #endif

        LOG("LemonHaze - 2022\n");
        EV_SetPlayerControlFlags(1);
        EV_FinishLoading();
        EnqueueTaskWithParameter(my_callback, 4, 0xb, 8, EVNT);
        return;
}