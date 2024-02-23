#ifndef GFL_PARAM_H
#define GFL_PARAM_H

// no padding pls
#pragma pack(push, 1)
#include <types.h>

namespace GFL {

    // offset, size, comment

    typedef union {
        u32 uinteger;   // size - 0x4
        s32 sinteger;   // size - 0x4
        f32 floating;   // size - 0x4
        char* str;      // size - 0x4
        bool boolean;   // size - 0x1
    } ParamValue;

    struct Param {
        void* vtable;       // 0x0, 0x4
        void* baseCallback; // 0x4, 0x4
        u8 unk[0x20];       // 0x8, 0x20
        ParamValue value;   // 0x28, 0x4
        void* paramType2;   // 0x2C, 0x4, I still don't know what this is
    };

    struct ParamGroup {
        GFL::Param base;    // 0x0, 0x30
        char* _30;          // 0x30, 0x4
    };

    
}

#endif
#pragma pack(pop)