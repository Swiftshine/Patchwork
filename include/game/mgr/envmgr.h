#ifndef FLUFF_ENV_MANAGER_H
#define FLUFF_ENV_MANAGER_H

#include "gfl/gfl.h"

// Size: 0x98 (i think)

class EnvMgr {
public:
    void* vtable;
    gfl::Task* task;
};



#endif
