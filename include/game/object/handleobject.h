#ifndef FLUFF_HANDLE_OBJECT_H
#define FLUFF_HANDLE_OBJECT_H

#include "gfl/gfl.h"

class FlfHandleObj {
public:
    void* vtable;       // 0x0, 0x4
    GFL::Task task;     // 0x4, 0x4
    void* _8;           // 0x8, 0x4  
};


#endif