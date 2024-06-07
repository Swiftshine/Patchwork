#ifndef FLUFF_IOBJHITCB_H
#define FLUFF_IOBJHITCB_H

#include "types.h"


// size might be 0x24
class IObjHitCB {
    u32 _0;
    u32 _4;
    u32 _8;
    u32 _C;
    u32 _10;
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
};


// size 0x460 maybe
class Callbacks {
public:


public:
    void* vtable;
    PTMF callbacks[93];
};

#endif