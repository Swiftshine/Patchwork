#include "kamek/kamek.h"

u32 customBeadValue = 10;


// This hooks into Bead::setValue()
kmBranchDefAsm(0x800b066c, 0x800b0670) {
    // r3 is current address of bead
    // r4 is newValue

    // r4 = &customBeadValue
    lis r4, customBeadValue@ha;
    addi r4, r4, customBeadValue@l;

    // r4 = *(r4)
    lwz r4, 0x0(r4);

    // 0x180 is the offset of the bead value

    // *(r3 + 0x180) = r4
    stw r4, 0x180(r3);
}