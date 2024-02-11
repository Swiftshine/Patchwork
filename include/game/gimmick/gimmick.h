#ifndef FLUFF_GIMMICK_H
#define FLUFF_GIMMICK_H

#include "types.h"

// where gimmick tables are observed to start
#define GIMMICK_TABLES_ADDRS 0x8083B474

class GimmickTable {
public:
    char* description;  // ShiftJIS, not ASCII
    char* objectName;
    void (*constructor)();
    u32 someID;         // unsure if this is really an ID
};

#endif