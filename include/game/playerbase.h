#ifndef FLUFF_PLAYERBASE_H
#define FLUFF_PLAYERBASE_H

#include <types.h>
#include "gfl/param.h"

// Comments with "quotation marks" are from the
// game's parameters, translated from Japanese.

// Size: 0xF68

class PlayerBase {
public:
    
    void setWoolWhipRange(f64 newRange, PlayerBase* player, bool ignoreConditions);
public:

};

//static_assert(sizeof(PlayerBase) == 0xF68, "PlayerBase is not the correct size.");

#endif