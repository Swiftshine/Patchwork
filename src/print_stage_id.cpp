#include "kamek/kamek.h"
#include "gfl/gfl.h"
#include "game/stage/stage.h"


u32* printStageID(u32* stageTask, Stage* stage) {
    OSReport("Loading stage with ID: %d\n", stage->stageID);
    return stageTask;
}

// Hook into StageMgr::loadStageData
// This accurately prints that i believe to be the stage ID,
// though it causes the *new* level data to not be loaded,
// meaning the current level loads in its place. hm.

// uncomment below if you want to use this (currently broken but somewhat functional)
/*kmBranchDefAsm(0x80044b34, 0x80044b38) {
    // original instruction
    lwz r0, 0x0(r4);

    // save r3 and r4
    stw r3, -0x4(r1);
    stw r4, -0x8(r1);

    // call 
    bl printStageID;

    // restore r3 and r4
    stw r3, 0x4(r1);
    stw r4, 0x8(r1);
}*/
