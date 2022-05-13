#ifndef _CUTSCENE_VIEWER_H
#define _CUTSCENE_VIEWER_H

unsigned char s_CutsceneViewerStaticData[] = {
     0x53, 0x49, 0x4e, 0x5f, 0xff, 0xff, 0xff, 
     0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

unsigned char tmp[7] = { 
        0, 0, 0, 0, 0, 0, 0 
};

enum State {
        SELECT_CUTSCENE         = 0,
        START_CUTSCENE          = 1,
        UNK_STATE               = 2,
        LOAD_STATE              = 3,
        
};

#endif