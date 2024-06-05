#ifndef FLUFF_GIMMICK_H
#define FLUFF_GIMMICK_H

#include "types.h"
#include "game/object/gameobject.h"
#include "game/object/gimmick/gimmicklist.h"
#include "gfl/gfl.h"

// where gimmick tables are observed to start (american)
#define GIMMICK_TABLES_ADDRS 0x8083b468

// size: 0x130 (i think)
class Gimmick : FlfGameObj {
public:
    Gimmick();
    ~Gimmick();
public:
    u32 _80;
    u32 _84;
    u32 _88;
    Vec3f _8C;
    Vec3f _98;
    u8 _A4;
    u8 pad1[3];
    u32 _A8;
    u8 _AC;
    u8 pad2[3];
    u32 _B0;
    u32 _B4;
    u32 _B8;
    void* _BC[5];
    void* _D0[5];
    gfl::String::BasicString strings[5];
    u32 _120;
    u32 _124;
    u32 _128;
    u32 _12C;
};

// size unknown
class GimmickTable {
public:
    wchar_t* description;  // ShiftJIS, not ASCII
    char* name;
    Gimmick (*build)();
    void (*stringRelatedFunction)();
};

#endif