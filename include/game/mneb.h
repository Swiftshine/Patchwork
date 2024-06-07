#ifndef FLUFF_MNEB_H
#define FLUFF_MNEB_H

#include "types.h"

namespace MNEB {
    struct Header {
        char magic[0x4];    // MNCH
        u32 entryOffset;
        u32 _8;
        u32 numEntries;
        u32 _10;
        u16 _14;
        bool _16;
        u8 pad;
    };

    struct Entry {
        char magic[0x4];    // MNCN
        u32 _4;
        char name[0x10];
    };
}

#endif