#ifndef FLUFF_COLBIN_H
#define FLUFF_COLBIN_H

#include "types.h"

enum CollisionType {
    ColType_None            = 0,
    ColType_Normal          = 1,        // "NML"
    ColType_CANCEL_METAMO   = 1 << 1,   // "CANCEL_METAMO"
    ColType_InstaKill       = 1 << 2,   // "GO_HEAVEN"
    ColType_GO_SEC          = 1 << 3,   // "GO_SEC"
    ColType_SolidOnTop      = 1 << 5,   // "THROUGH"
    ColType_SLOW            = 1 << 6,   // "SLOW"
    ColType_NONE_SLIP       = 1 << 7,   // "NONE_SLIP"

    ColType_CAMERA          = 1 << 11,  // "CAMERA"
    ColType_CAMERA_MORI     = 1 << 11,  // "CAMERA_MORI"
    ColType_CAMERA_THROUGH  = 1 << 12,  // "CAMERA_THROUGH"
    ColType_CAMERA_PLAYER_Y = 1 << 13,  // "CAMERA_PLAYER_Y"

};

enum CollisionAttribute {
    ColAtt_None     = 0,

    ColAtt_URA      = 1 << 1,   // "URA"

    ColAtt_Soft     = 1 << 3,   // "SOFT"
    ColAtt_Hard     = 1 << 4,   // "HARD"

    ColAtt_Fire     = 1 << 16,  // "FIRE"
};

namespace CollisionStrings {
    /* easily described */
    char* NONE          = "";
    char* NORMAL        = "NML";
    char* INSTANT_KILL  = "GO_HEAVEN";
    char* SOLID_ON_TOP  = "THROUGH";

    /* not as easily described */    
    char* CANCEL_METAMO = "CANCEL_METAMO";
    char* SLOW          = "SLOW";
}

// Size is not fixed
namespace Colbin {
    struct Header {
        float multiplier; // i think? i know it's a float though
        u32 numEntries;
        u32 entryOffset;
        u32 footerOffset;
    };

    // each entry is a triangle
    struct Entry {
        Vec2f point1;
        Vec2f point2;
        Vec2f point3;
        u32 index;
        u32 collisionTypeIndex;
    };


    struct Footer {
        u32 numCollisionTypes;
        /* present is a char [0x20][numCollisionTypes] */

        /* padding until next multiple of 0x10 (0x20?)*/
    };
}

#endif