#ifndef FLUFF_ENEMY_LIST_H
#define FLUFF_ENEMY_LIST_H

#include <types.h>

// These are NOT the same thing as enemy ids.
// These are just the numbers listed in the string.
enum EnemyLabels {
    EnemyLabel_WaddleDee    = 26,
    EnemyLabel_WaddleDeeWithSpear = 27,
    EnemyLabel_Monkey       = 29,
    EnemyLabel_Blipper      = 33,
    EnemyLabel_BrontoBurt   = 35,
};

enum BulletLabels {
    BulletLabel_Spear   = 7,
    BulletLabel_Rocket  = 26,
};

enum EnemyIDs {
    EnemyID_WaddleDee = 0x1A, // 26

};

enum EnemyConstructors {
    EnemyCtor_WaddleDee     = 0x802D3CF4,
    EnemyCtor_WaddleDeeWithSpear = 0x802E1E0C,
    EnemyCtor_Monkey        = 0x802f0688,
    EnemyCtor_Blipper       = 0x80335DD8,
    EnemyCtor_BrontoBurt    = 0x80356CD8,

    BulletCtor_Spear        = 0x8032EF14,
    BulletCtor_Rocket       = 0x805ECE1C,
};

enum EnemyConstructorCallers {

};

#endif