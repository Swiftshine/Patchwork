#ifndef FLUFF_IOBJHITCB_H
#define FLUFF_IOBJHITCB_H

#include "types.h"


// size 0x460 maybe
class IObjHitCB {
public:
    enum CallbackIDs {
        Callback_EnterDoor = 0,

    };
public:
    void* vtable;
    PTMF callbacks[93];
};

#endif