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

    // a list of states for the player to typically be in.
    // these are (mostly) exclusive to whenever the player
    // does not have a transformation applied, save for states
    // such as entity collision
    enum PlayerState {
        PlayerState_Default             = 0, // this applies to many situations, such as entering a door, being carried by Angie, or being used in the controls menu. think of it as a state for situations that dont fit the others
        PlayerState_OnGround            = 1, // the player is on the ground
        PlayerState_Jump                = 2, // the player is in the air because of a jumping action

        PlayerState_YarnWhip            = 4, // the player is using the yarn whip
        PlayerState_Weight              = 5, // the player becomes a weight
        PlayerState_Falling             = 6, // the player is in the air but not because of a jumping action

        PlayerState_TakeDamage          = 9, // the player takes damage
        
        PlayerState_YarnWhipLockOn      = 0xB, // the player was able to lock onto a target with yarn whip
        PlayerState_Throw               = 0xC, // the player is throwing an item
        PlayerState_Parachute           = 0xE, // the player is a parachute
        PlayerState_Tangled             = 0xF, // player is damaged and yarn becomes tangled. takes a moment to recover

        PlayerState_SideBump            = 0x11, // bumping into an enemy or into terrain as a car
        PlayerState_EntityCollision     = 0x12, // this includes water
        PlayerState_Baseball            = 0x14, // the player turns into a baseball when yarn whipped by another player
        PlayerState_DropItem            = 0x16, // the player drops the item held
    };

public:
    
    void setWoolWhipRange(f32 newRange, bool ignoreConditions);
    void setupCallbacks();
public:
    // these functions are called via callbacks
    // it's good to think of these as state callbacks
    // todo - give accurate names to such callbacks

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