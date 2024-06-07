#ifndef FLUFF_PARAM_H
#define FLUFF_PARAM_H

#include "types.h"

namespace WorkROParam {

    char* magic         = "FWRP";   // "Fluff Work RO Param"
    char* blockStart    = "BLKS";   // "BLocK Start"
    char* blockEnd      = "BLKE";   // "BLocK End"
    enum Flags {
        BlockStart  = 0x424C4B53, // "BLKS"
        BlockEnd    = 0x424C4B45, // "BLKE"
    };
    
    struct Header {
        char magic[0x4];
    };

    struct Block {
        Flags start;
        char* name; // variable length
        u32 pad;

        /* contents unknown */

        Flags end;
    };

    struct AreaWorkRO {
        Flags start;
        char name[0xF];
        Flags end;
    };
}


#endif