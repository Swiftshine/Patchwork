#ifndef FLUFF_ENEMY_H
#define FLUFF_ENEMY_H

#include "gfl/gfl.h"
#include "game/gimmick/enemylists.h"
#include "game/gameobject.h"
#include "types.h"

// where enemy tables are observed to start
#define ENEMY_TABLE_ADDRS 0x80844A14

class EnemyBase : public GameObject {
public:

public:
    void* baseObject;           // 0x0
    u8 _4[0x1D0 - 0x4];         // 0x4
};

//static_assert(sizeof(EnemyBase) == 0x1D0, "Enemy is not the correct size.");

class EnemyTable {
public:
    char* name;
    union {
        void (*constructor)(); // ctor function ptr
        void (*constructorCaller)(); // function ptr to a function that calls the constructor
    };
    char* linkedEnemyName; // the name of either this enemy or another (linked) enemy it depends on
    char* path; // path to the enemy's file
    u32 someID; // this value always seems to be 0, 1, or 2 less than the number listed in the enemy's actual name...
};


//static_assert(sizeof(EnemyTable) == 0x14, "EnemyTable is not the correct size.");

#endif