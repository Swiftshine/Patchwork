#ifndef FLUFF_ENV_MGR_H
#define FLUFF_ENV_MGR_H

#include "gfl/gfl.h"

// Size: 0x98 (i think)

class EnvMgr {
public:
    void* vtable;
    GFL::Task* task;
};



#endif