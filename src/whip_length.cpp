#include "kamek/kamek.h"
#include "gfl/param.h"
using GFL::Param;

// default value is 3.5f
float whip_length = 7.0f;

kmBranchDefAsm(0x8009b6d0, 0x8009b6d8) {
    // upper bits of whip_length address
    lis r4, whip_length@ha;

    // lower bits of whip_length address
    addi r4, r4, whip_length@l;

    // load whip_length into f0
    lfs f0, 0x0(r4);
}