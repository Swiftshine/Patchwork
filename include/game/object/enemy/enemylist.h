#ifndef FLUFF_ENEMY_LIST_H
#define FLUFF_ENEMY_LIST_H

#include <types.h>

// note to self, &EnemyGenerator + 0xE4 is a string that determines
// what enemy gets spawned. i'll have to look into that...


// These are NOT the same thing as enemy ids.
// These are just the numbers listed in the string.
enum EnemyLabels {
    EnemyLabel_Enemy0               = 0,
    EnemyLabel_Uniclod              = 2,
    EnemyLabel_Buttonbee            = 3,
    EnemyLabel_Sulkworm             = 5,
    EnemyLabel_Dandan               = 6,
    EnemyLabel_Candlemander         = 12,
    EnemyLabel_Gator                = 25,
    EnemyLabel_WaddleDee            = 26,
    EnemyLabel_WaddleDeeWithSpear   = 27,
    EnemyLabel_Ooki                 = 29,
    EnemyLabel_Scarfy               = 32,
    EnemyLabel_Blipper              = 33,
    EnemyLabel_BrontoBurt           = 35,
    EnemyLabel_WaddleDeeWithBow     = 38,
    EnemyLabel_WaddleDeeWithParasol = 39,
    EnemyLabel_Chilly               = 40,
    EnemyLabel_WaddleDeeWithBalloons= 41,
    EnemyLabel_SleepingWaddleDee    = 43,
    EnemyLabel_Cyclod               = 45,
    EnemyLabel_Buttonfly            = 46,
    EnemyLabel_Dropso               = 60,
    EnemyLabel_WickedWillow         = 115,
};

enum BulletLabels {
    BulletLabel_DandanBullet        = 0,
    BulletLabel_Spear               = 7,
    BulletLabel_Cannonball          = 13,
    BulletLabel_Bullet14            = 14,
    BulletLabel_Arrow               = 15,
    BulletLabel_Balloons            = 19,
    BulletLabel_Parasol             = 20,
    BulletLabel_Bullet22            = 22,
    BulletLabel_WickedWillowBullet  = 25,
    BulletLabel_Rocket              = 26,
    BulletLabel_UniclodBullet       = 80,
    BulletLabel_ButtonflyBullet     = 85,
};

// might have to double-check a few of these IDs
enum EnemyIDs {
    EnemyID_Uniclod                 = 2,
    EnemyID_Buttonbee               = 3,
    EnemyID_Candlemander            = 12,
    EnemyID_Gator                   = 24,
    EnemyID_WaddleDee               = 25,
    EnemyID_WaddleDeeWithSpear      = 26,
    EnemyID_Ooki                    = 28,
    EnemyID_Blipper                 = 32,
    EnemyID_BrontoBurt              = 34,
    EnemyID_WaddleDeeWithBow        = 0x25, // 37
    EnemyID_WaddleDeeWithParasol    = 38,
    EnemyID_Chilly                  = 0x28, // 40
    EnemyID_Cyclod                  = 43,
    EnemyID_Buttonfly               = 44,


    BulletID_Spear                  = 104, // 104
    BulletID_Parasol                = 115,
    BulletID_Bullet22               = 0x75, // 117
    BulletID_Rocket                 = 121, // 121

    EnemyID_ENGMK_BALL              = 173,
    EnemyID_Help                    = 174, // "help" is Angie; the angel that rescues you when you, for example, fall in a pit
    Enemy_HelpRobot                 = 175, // "help robot" is simply the controls screen when you press minus
};

enum EnemyConstructors {
    EnemyCtor_Enemy5                = 0x80172c24,
    EnemyCtor_Dropso                = 0x8022b90c,
    EnemyCtor_Uniclod               = 0x8013D0A0,
    EnemyCtor_Cyclod                = 0x803b2f48,
    EnemyCtor_WaddleDee             = 0x802D3CF4,
    EnemyCtor_WaddleDeeWithSpear    = 0x802E1E0C,
    EnemyCtor_WaddleDeeWithParasol  = 0x803e3244,
    EnemyCtor_WaddleDeeWithBow      = 0x803aaa80,
    EnemyCtor_Ooki                  = 0x802F0688,
    EnemyCtor_Blipper               = 0x80335DD8,
    EnemyCtor_BrontoBurt            = 0x80356CD8,
    EnemyCtor_Buttonbee             = 0x8016EF48,
    EnemyCtor_Buttonfly             = 0x803B6B2C,
    EnemyCtor_Candlemander          = 0x801e16b8,
    EnemyCtor_Gator                 = 0x802de408,
    EnemyCtor_WickedWillow          = 0x805e0464,
    EnemyCtor_Scarfy                = 0x803e7dfc,
    EnemyCtor_ENGMK_BALL            = 0x806190d4,
    EnemyCtor_Dandan                = 0x8017bac8,


    BulletCtor_Bullet14             = 0x803c63bc,
    BulletCtor_Bullet22             = 0x8057acc4,
    BulletCtor_WickedWillowBullet   = 0x805df478,
    BulletCtor_Cannonbal            = 0x803a9f6c,
    BulletCtor_Spear                = 0x8032EF14,
    BulletCtor_Arrow                = 0x803c4930,
    BulletCtor_Rocket               = 0x805ECE1C,
    BulletCtor_Parasol              = 0x80531724,
    BulletCtor_UniclodBullet        = 0x80352B1C,
    BulletCtor_ButtonflyBullet      = 0x80352b1c,
    BulletCtor_DandanBullet         = 0x801f1868,


};

enum EnemyConstructorCallers {
    EnemyCtorCaller_Help            = 0x8012d46c,
    EnemyCtorCaller_HelpRobot       = 0x8012d464,
};

#endif