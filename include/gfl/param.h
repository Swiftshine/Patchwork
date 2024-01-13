#ifndef GFL_PARAM_H
#define GFL_PARAM_H

// no padding pls
#pragma pack(push, 1)
#include <types.h>

namespace GFL {

    // offset, size, comment

    typedef union { // 0x28, 0x4
        u32 uinteger;
        s32 sinteger;
        f32 floating;
    } ParamValue;

    struct Param {
        char* ParamType; // 0x0, 0x4, ParamName?
        void* BaseCallback; // 0x4, 0x4
        u8 unk[0x20]; // 0x8, 0x20
        ParamValue value; // 0x28, 0x4
        void* ParamType2; // 0x2C, 0x4, I still don't know what this is
    };
}

#endif
#pragma pack(pop)