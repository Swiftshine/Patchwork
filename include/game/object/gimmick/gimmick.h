#ifndef FLUFF_GIMMICK_H
#define FLUFF_GIMMICK_H

#include "types.h"
#include "game/object/gameobject.h"
#include "game/object/gimmick/gimmicklist.h"
#include "gfl/gfl.h"

// where gimmick tables are observed to start
#define GIMMICK_TABLES_ADDRS 0x8083B474

class Gimmick : FlfGameObj {
public:

public:

};

// size unknown
class GimmickTable {
public:
    char* description;  // ShiftJIS, not ASCII
    char* objectName;
    void (*constructor)();
    u32 someID;         // unsure if this is really an ID
};

#endif