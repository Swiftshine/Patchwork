#include "kamek/kamek.h"
#include "game/playerbase.h"

// default value is 3.5f
float whipLength = 5.0f;

kmBranchDefAsm(0x8009b6d0, 0x8009b6d8) {
    // r4 = &whipLength
    lis r4, whipLength@ha;
    addi r4, r4, whipLength@l;

    // f0 = *(r4)
    lfs f0, 0x0(r4);
}
