#ifndef FLUFF_ENEMY_H
#define FLUFF_ENEMY_H

#include "gfl/gfl.h"
#include "game/gimmick/enemylist.h"
#include "game/gameobject.h"

class EnemyBase : public GameObject {
public:

public:
    void* baseObject;           // 0x0
    u8 _4[0x1D0 - 0x4];         // 0x4
};

static_assert(sizeof(EnemyBase) == 0x1D0, "Enemy is not the correct size.");

#endif