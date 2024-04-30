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
    enum PlayerState {
        Callback_OnEnterDoor        = 0,
        Callback_OnTouchGround      = 1,
        Callback_OnJump             = 2,
        Callback_Unk1               = 3,
        Callback_OnYarnWhip         = 4,
        Callback_OnGroundPound      = 5,
        Callback_OnFall             = 6,
        Callback_Unk2               = 7,
        Callback_Unk3               = 8,
        Callback_OnDamage           = 9,
        Callback_Unk4               = 10,

    };

public:
    
    void setWoolWhipRange(f32 newRange, bool ignoreConditions);
    void setupCallbacks();
public:
    // these functions are called via callbacks
    // it's good to think of these as state callbacks
    void onEnterDoor();
    void onTouchGround();
    void onJump();

    void onYarnWhip();
    void onGroundPound();
    void onFall();


    void onDamage();
public:
    IObjHitCB callbacks; // 0x80, 0x460, these callbacks align with the player's state
};


// gfl::FunctorClassMethod0<void,PlayerBase*,void(PlayerBase::*)()const>


//static_assert(sizeof(PlayerBase) == 0xF68, "PlayerBase is not the correct size.");

#endif