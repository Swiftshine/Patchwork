#include "kamek/kamek.h"
#include "gfl/gfl.h"
#include "game/stage/stage.h"

u32* printStageInfo(u32* stageTask, Stage* stage) {
    OSReport("Loading stage with 0x0 value: %d\n", stage->_0);
    OSReport("Loading stage with ID: %d\n", stage->stageID);
    OSReport("Loading stage with 0x8 value: %d\n", stage->_8);
    return stageTask;
}

// Hook into StageMgr::loadStageData
kmBranchDefAsm(0x80044b34, 0x80044b38) {
    // original instruction
    lwz r0, 0x0(r4);

    // save volatile registers
    stwu sp, -0x3C(sp)
    stw  r0,  0x08(sp)
    stw  r3,  0x0C(sp)
    stw  r4,  0x10(sp)
    stw  r5,  0x14(sp)
    stw  r6,  0x18(sp)
    stw  r7,  0x1C(sp)
    stw  r8,  0x20(sp)
    stw  r9,  0x24(sp)
    stw  r10, 0x28(sp)
    stw  r11, 0x2C(sp)
    stw  r12, 0x30(sp)
    mfcr r0
    stw  r0,  0x34(sp)
    mfctr r0
    stw  r0,  0x38(sp)
    mflr r0
    stw  r0,  0x40(sp)

    bl printStageInfo;

    // restore volatile registers
    lwz  r0,  0x38(sp)
    mtctr r0
    lwz  r0,  0x34(sp)
    mtcr r0
    lwz  r0,  0x40(sp)
    mtlr r0
    lwz  r0,  0x08(sp)
    lwz  r3,  0x0C(sp)
    lwz  r4,  0x10(sp)
    lwz  r5,  0x14(sp)
    lwz  r6,  0x18(sp)
    lwz  r7,  0x1C(sp)
    lwz  r8,  0x20(sp)
    lwz  r9,  0x24(sp)
    lwz  r10, 0x28(sp)
    lwz  r11, 0x2C(sp)
    lwz  r12, 0x30(sp)
    addi sp,  sp, 0x3C
}
