#ifndef GFL_FUNCTOR_CLASS_METHOD_H
#define GFL_FUNCTOR_CLASS_METHOD_H

#include <types.h>

namespace gfl {

    // Size: 0x14
    template <typename T>
    class FunctorClassMethod0 {
    public:
    public:
        void* vtable;       // 0x0, 0x4
        T* owner;           // 0x4, 0x8
        PTMF ptmf;          // 0xC, 0x4
    };

} // namespace gfl
#endif