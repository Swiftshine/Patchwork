#ifndef FLUFF_ENEMY_H
#define FLUFF_ENEMY_H

#include "gfl/gfl.h"
#include "game/object/enemy/enemylist.h"
#include "game/object/gameobject.h"
#include "types.h"

// where enemy tables are observed to start
#define ENEMY_TABLE_ADDRS 0x80844A14

// Size: 0x1D0 (?)
class EnemyBase : public FlfGameObj {
public:

public:

};


class EnemyTable {
public:
    u32 enemyID;
    char* name;
    union {
        void (*constructor)(); // ctor function ptr
        void (*constructorCaller)(); // function ptr to a function that calls the constructor
    };
    char* linkedEnemyName; // the name of either this enemy or another (linked) enemy it depends on
    char* path; // path to the enemy's file
};


//static_assert(sizeof(EnemyTable) == 0x14, "EnemyTable is not the correct size.");

#endif