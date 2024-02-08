#ifndef FLUFF_WORK_MANAGER_H
#define FLUFF_WORK_MANAGER_H

#include <types.h>
#include "gfl/gfl.h"
// Size: 0x786

class WorkMgr {
    // primaryTask's name is set to "WorkManager"
public:
    void* baseObject;       // 0x0, 0x4
    GFL::Task* primaryTask; // 0x4, 0x4
    u32 _8;                 // 0x8, 0x4
    GFL::Functor* functor;  // 0xC, 0x4
    GFL::FunctorClassMethod0* functorClassMethod; // 0x10, 0x4
    /* "gfl::FunctorClassMethod0<void, WorkManager *, void (WorkManager::*)()const >"*/
};

#endif