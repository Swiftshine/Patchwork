#ifndef GFL_TASK_H
#define GFL_TASK_H

#include <types.h>
#include "gfl/functorclassmethod.h"

namespace GFL {

// Size unknown, but I think it's 0x18
class Task {
public:
    void setName(char* name);
public:
    void* baseObject;                               // 0x0, 0x4
    char* taskName;                                 // 0x4, 0x4
    GFL::Functor* functor;                          // 0x8, 0x4
    GFL::FunctorClassMethod0* functorClassMethod;   // 0xC, 0x4
    u32 _10;                                        // 0x10, 0x4
    u32 _14;                                        // 0x14, 0x4
};


} // namespace GFL


#endif