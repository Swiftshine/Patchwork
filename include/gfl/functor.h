#ifndef GFL_FUNCTOR_H
#define GFL_FUNCTOR_H

#include <types.h>

namespace gfl {

// Size: 0x10

// Offset, size, comment
class Functor {
public:

public:
    void* baseObject; // 0x0, 0x4
    u8 unk1[0x10 - 0x4]; // 0x4, 0xC
};

//static_assert(sizeof(Functor) == 0x10, "gfl::Functor is not the correct size.");

    
    template <typename T>
    // the 0 probably stands for "0 parameters"?
    class FunctorBase0 {
    public:
        void operator()();
    public:
        void* vtable;
        T* owner;
        PTMF ptmf;
    };

} // namespace gfl

#endif