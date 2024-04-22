#ifndef GFL_FUNCTOR_CLASS_METHOD_H
#define GFL_FUNCTOR_CLASS_METHOD_H

#include <types.h>
#include "gfl/functor.h"

namespace gfl {

// Size: 0x14

class FunctorClassMethod0 {
public:
public:
    void* baseObject;   // 0x0, 0x4
    void* owner;        // 0x4, 0x4
    void* function;     // 0x8, 0x4
    u32 _C;             // 0xC, 0x4
    u32 _10;            // 0x10, 0x4
};

} // namespace gfl
#endif