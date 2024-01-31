#ifndef GFL_FUNCTOR_H
#define GFL_FUNCTOR_H

#include <types.h>

namespace GFL {

// Size: 0x10

// Offset, size, comment
class Functor {
public:

public:
    void* baseObject; // 0x0, 0x4
    u8 unk1[0x10 - 0x4]; // 0x4, 0xC
};

//static_assert(sizeof(Functor) == 0x10, "GFL::Functor is not the correct size.");


// Size unknown
class FunctorBase {
    public:
};


} // namespace GFL

#endif