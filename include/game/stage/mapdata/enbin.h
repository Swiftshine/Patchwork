#ifndef FLUFF_MAPDATA_ENBIN_H
#define FLUFF_MAPDATA_ENBIN_H
#include "types.h"
// ENBIN = ENemy BINary

namespace Mapdata {
namespace Enbin {

    // The enbin header.
    struct Header {
        char magic[0x4];    // "GFES" - GoodFeel Enemy Settings?
        u32 _4;
        u32 _8;
        u32 _C;
        u32 filesize;       // size of the entire file, excluding the magic
        u32 numEntries;
    };

    // Information for each enemy entry. Size: 0x174
    struct EnemyEntry {
        char name[0x20];
        char behavior[0x20];
        char _40[0x20];
        char beadType[0x10];
        char beadColor[0x10];
        char direction[0x10];
        char orientation[0x10];
        Vec3f position1;
        Vec3f position2;
        Vec3f position3;
        Vec3f _C4;
        u32 _D0;
        u32 _D4;
        u32 _D8;
        Vec3f _DC;
        u32 _E8;
        u32 _EC;
        u32 _F0;
        u32 _F4;
        u32 _F8;
        u32 _FC;
        u32 _100;
        u32 _104;
        u32 _108;
        u32 _10C;
        u32 _110;
        u32 _114;
        u32 _118;
        u32 _11C;
        u32 _120;
        u32 _124;
        u32 _128;
        u32 _12C;
        u32 _130;
        u32 _134;
        u32 _138;
        u32 _13C;
        u32 _140;
        u32 _144;
        u32 _148;
        u32 _14C;
        u32 _150;
        u32 _154;
        u32 _158;
        u32 _15C;
        u32 _160;
        u32 _164;
        u32 _168;
        u32 _16C;
        u32 _170;
    };
}


   
}

#endif