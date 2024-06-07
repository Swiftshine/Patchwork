#ifndef FLUFF_MESSAGE_MESSAGEBIN_H
#define FLUFF_MESSAGE_MESSAGEBIN_H

#include "types.h"

namespace MessageBin {
    enum TextFlags : u32 {
        Flag_FrameStart  = 0xA5047,   // "\0\nPG" - the start of the text frame
        Flag_FrameEnd    = 0xB5047,   // "\0\vPG" - the end of a text frame

        Flag_TX = 0xA5458,   // "TX" - comes before actual text data
    };


    struct Header {
        char magic[0x4];    // "GFMC" - GoodFeel Message Contents?
        u32 _4;             // always 0x10000
        u32 filesize;
        u32 _C;             // always 0x1C. an offset to something
        u32 _10;            // always 0x81C. it's an offset to the beginning of entries of some sort
        u32 _14;            // an offset to some table
        u32 textOffset;     // an offset to the actual text
    };

    struct EntryType1 {
        u32 _0;
        u32 _4;
        u32 _8;
        u32 index;
    };

    struct ROStringEntry {
        u32 hash;
        u32 _4;
        u32 _8;
        u32 _C;
        u32 _10;
        u32 _14;
    };

    struct StringEntry {
        TextFlags begin;
        TextFlags flag;
        u32 stringLength;
        wchar_t* string; // the string is wchar (to support japanese characters)
        TextFlags end;
    };
}

#endif