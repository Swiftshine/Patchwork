#ifndef FLUFF_MAPDATA_MAPBIN_H
#define FLUFF_MAPDATA_MAPBIN_H
#include "types.h"
#include "gfl/gfl.h"
// MAPBIN = MAP BINary

struct CountOffsetPair { u32 count; u32 offset; };

namespace Mapdata {
namespace Mapbin {
    struct Header {
        f32 _0;
        Vec2f boundsStart;
        Vec2f boundsEnd;
        u32 triangleCount;
        u32 trianglesOffset;
        u32 dataSegLabelCount;
        u32 dataSegLabelOffset;
        u32 strings1Count;
        u32 strings1Offset;
        u32 gimmickCount;
        u32 gimmicksOffset;
        u32 strings3Count;
        u32 strings3Offset;
        u32 strings4Count;
        u32 strings4Offset;
        u32 strings5Count;
        u32 strings5Offset;
        u32 parameterOffset;
        u32 colbinFooterOffset;
        u32 colbinFooterEnd;
    };

    struct GimmickEntry {
        char name[0x30];
        Vec3f position;

    };

    struct ParamHeader {
        u32 count; // ?
    };

    struct Param {
        char name[0x20];

    };
    struct Struct1 {

    };

    // size: 0x98
    struct Struct2 {
        int _0;
        Vec3f _4;
        Vec3f _10;
        char _1C[8];
        u8 _24;
        u8 pad[3];
        u32 _28;
        u32 _2C;
        u32 _30;
        char _34[20];
        char _48[20];
        gfl::String::BasicString strings[5];
        u32 _98;
    };
    
    // size: 0x28
    struct Struct3 {
        u8 _0;
        u8 _1;
        u16 pad;
        u32 _4;
        char _8[0x20];
    };

    // size: 0x54
    struct Struct4 {
        gfl::String::BasicString _0;
        Vec3f _C;
        u32 _18[3];
        Vec3f _24;
        gfl::String::BasicString _30[3];
    };

    // size: 0x50
    struct Struct5 {
        u32 _0;
        u32 _4;
        u32 _8;
        u32 _C;
        u32 _10;
        u32 _14;
        Vec3f _18;
        gfl::String::BasicString _24[3];
        u32 _48;
        Vec2f* _4C;
    };


    // size: 0x58
    struct Struct6 {
        gfl::String::BasicString _0;
        Vec3f _C;
        u32 _18[3];
        gfl::String::BasicString _24[3];
        Vec2f _48;
        Vec2f _50;
    };

    // size: 0x54
    struct Struct7 {
        
    };
}
}

#endif