#include "kamek/kamek.h"
#include "game/playerbase.h"

// default value is 3.5f
float whipLength = 5.0f;

kmBranchDefAsm(0x8009b6d0, 0x8009b6d8) {
    // upper bits of whipLength address
    lis r4, whipLength@ha;

    // lower bits of whipLength address
    addi r4, r4, whipLength@l;

    // load whipLength into f0
    lfs f0, 0x0(r4);
}