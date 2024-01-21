#ifndef FLUFF_MGR_BASE_H
#define FLUFF_MGR_BASE_H

// One thing I should note is that
// this isn't a real class (as far as I know),
// I'm just using it for simplicity.

#include "gfl/gfl.h"

// Size: 0x18
class MgrBase {
public:
    void* baseObject; // 0x0, 0x4
    GFL::Task* task;  // 0x4, 0x4
    void* _8;         // 0x8, 0x4
    GFL::Functor* functor; // 0xC, 0x4
    GFL::FunctorClassMethod* functorClassMethod; // 0x10, 0x4
    void* _14; // 0x14, 0x4
};

#endif