#ifndef FLUFF_PLAYERBASE_H
#define FLUFF_PLAYERBASE_H

#include <types.h>
#include "game/object/gameobject.h"
#include "game/object/iobjhitcb.h"
#include "gfl/gfl.h"
#include "gfl/functorclassmethod.h"
// Comments with "quotation marks" are from the
// game's parameters, translated from Japanese.

// Size: 0xF68
class PlayerBase : public FlfGameObj {
public:
    
    void setWoolWhipRange(f32 newRange, bool ignoreConditions);

public: // these functions are called via callbacks
    void enterDoor();
public:
    IObjHitCB callbacks; // 0x80, 0x460
};


// gfl::FunctorClassMethod0<void,PlayerBase*,void(PlayerBase::*)()const>


//static_assert(sizeof(PlayerBase) == 0xF68, "PlayerBase is not the correct size.");

#endif