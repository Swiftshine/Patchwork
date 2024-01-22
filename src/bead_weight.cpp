#include "kamek/kamek.h"

// Set the bead weight to a custom value


// Small weight is 1.01f
// Medium weight is 1.05f
// Large weight is 1.1f
// Huge weight is 1.1f

float beadWeight = 2.0f;

kmBranchDefAsm(0x800ad234, 0x800b1218) {
    // r3 is current address of bead
    // f0 is bead weight

    // r4 = &beadWeight
    lis r4, beadWeight@ha;
    addi r4, r4, beadWeight@l;

    // f0 = *(r4)
    lfs f0, 0x0(r4);

    // 0x17C is the offset of the bead weight
    // *(r3 + 0x17C) = f0
    stfs f0, 0x17C(r3);
}