#include "kamek/kamek.h"
#include "game/misc.h"
#include "game/gimmick/enemy.h"

EnemyTable* printEnemyTable(EnemyTable* table) {
    OSReport("Table->name  : %s\n", table->name);
    OSReport("Table->ctor  : %p\n", table->constructor);
    OSReport("Table->_8    : %s\n", table->_8);
    OSReport("Table->path  : %s\n", table->path);
    OSReport("Table->someID: %u\n", table->someID);

    return table;
}

u32 linkReg;

// Hook into getEnemyConstructorByID
// Entry - 0x8012d474
// Exit  - 0x8012d478

//! this doesn't work
kmBranchDefAsm(0x8012d480, 0x8012d484) {
    // original instruction
    add r3, r3, r0
    // r3 is an EnemyTable* 
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


    // r4 = lr
    mflr r4
    // linkReg = r4
    lis r5, linkReg@ha
    addi r5, r5, linkReg@l
    stw r4, 0x0(r5)

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

    bl printEnemyTable

    lis r5, linkReg@ha
    addi r5, r5, linkReg@l
    lwz r4, 0x0(r5)
    mtlr r4

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