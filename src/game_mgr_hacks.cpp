// todo - figure out why this results in a loading loop

#include "kamek/kamek.h"


static bool doPrintStageSetup = true;


u32* printStageSetup(u32* gameMgr, int setupState) {
    if (!doPrintStageSetup) return gameMgr;

    const char* str = "";
    switch (setupState) {
        case 0:
        case 1: {
            str = "";
            break;
        }

        case 2: {
            str = "Creating game scene...";
            break;
        }

        case 3: {
            str = "Setting up gimmicks...";
            break;
        }

        case 4: {
            str = "Waiting for a sec... (WaitSecInit)";
            break;
        }

        case 5: {
            str = "Starting game scene!";
            break;
        }

        case 6: {
            str = "Starting player setup...";
            break;
        }

        case 7: {
            str = "Finishing player setup...";
            break;
        }

        default: {
            str = "Encountered an undocumented loading state.";
            break;
        }
    }

    OSReport("\n%s\nLoading with state ID %d\n", str, setupState);
    return gameMgr;
}

kmBranchDefAsm(0x8001065c, 0x80010660) {
    // original instruction
    lwz r0, 0x3C(r3)

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

    lwz r4, 0x3C(r3)
    bl printStageSetup

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