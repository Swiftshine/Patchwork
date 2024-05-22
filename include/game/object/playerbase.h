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
    // such as entity collision. undefined states are indicated
    // by their hex value. at some point these undefined states become
    // the same few, just rotated around.
    enum PlayerState {
        PlayerState_Default             = 0, // this applies to many situations, such as entering a door, being carried by Angie, or being used in the controls menu. think of it as a state for situations that dont fit the others
        PlayerState_OnGround            = 1, // the player is on the ground
        PlayerState_Jump                = 2, // the player is in the air because of a jumping action
        PlayerState_Undefined3          = 3, // identical to 0xE
        PlayerState_YarnWhip            = 4, // the player is using the yarn whip
        PlayerState_Weight              = 5, // the player becomes a weight
        PlayerState_Falling             = 6, // the player is in the air but not because of a jumping action
        PlayerState_JumpThenParachute   = 7, // the player jumps then becomes a parachute
        PlayerState_Undefined1          = 8, // the player stays in the air
        PlayerState_TakeDamage          = 9, // the player takes damage
        PlayerState_Sled                = 0xA, // the player is a sled
        PlayerState_YarnWhipLockOn      = 0xB, // the player was able to lock onto a target with yarn whip
        PlayerState_ThrowItem           = 0xC, // the player is throwing an item
        PlayerState_Parachute           = 0xE, // the player is a parachute. it's unclear how this is different from state 0x3
        PlayerState_UndefinedD          = 0xD, // similar to player state 0x8, but the player's y position drops a little bit first
        PlayerState_Tangled             = 0xF, // player is damaged and yarn becomes tangled. takes a moment to recover
        PlayerState_Crumple             = 0x10, // the player crumples up into a little ball
        PlayerState_SideBump            = 0x11, // bumping into an enemy or into terrain as a car
        PlayerState_EntityCollision     = 0x12, // player collided with a non-terrain entity. this includes water
        PlayerState_Undefined13         = 0x13, // the behaviour of this state is odd. it essentially resets player animations and the player starts falling
        PlayerState_Baseball            = 0x14, // the player turns into a baseball when yarn whipped by another player
        PlayerState_Undefined15         = 0x15, // identical to 0x6
        PlayerState_DropItem            = 0x16, // the player drops the item held
        PlayerState_Undefined17         = 0x17, // the player jumps, but gravity is not applied. this leads to an infinite y position increase with consecutive jumps
        PlayerState_Undefined18         = 0x18, // identical to 0x8
        PlayerState_Undefined1B         = 0x1B, // similar to 0x17, but jumping occurs only once
        PlayerState_Undefined1D         = 0x1D, // similar to 0x17, but at a much faster rate
        PlayerState_Undefined1E         = 0x1E, // similar to 0xD, but with the intended animation. maybe this state is intentional?
        PlayerState_Undefined24         = 0x24, // similar to 0x4, but with a shorter duration; the yarn whip does not extend all the way
        PlayerState_Undefined27         = 0x27, // similar to 0x5, but in an odd way. the player never hits the ground and the animation stops instead of looping
        PlayerState_Undefined2C         = 0x2C, // the player jumps, then free falls.
    };

    enum PlayerTransformation {
        PlayerTransformation_None        = 0x0,
        PlayerTransformation_Submarine   = 0x1,
        PlayerTransformation_String      = 0x2,  // used in tight spaces. looks like a silly little worm
        PlayerTransformation_Surfboard   = 0x3,  // called "Boat" internally. is the penguin on the surfboard
        PlayerTransformation_Robot       = 0x4,
        PlayerTransformation_OffRoader   = 0x5,  // called "Vehicle" internally
        PlayerTransformation_Firetruck   = 0x6,  // called "Splash" internally
        PlayerTransformation_Train       = 0x7,  // called "TrainFree" internally
        PlayerTransformation_Dolphin     = 0x8,  // called "AquaRide" internally
        PlayerTransformation_Rocket      = 0x9,
        PlayerTransformation_WarpStar    = 0xA,
        PlayerTransformation_UFO         = 0xB,

        PlayerTransformation_Digger      = 0xD,  // called "BrightRobot" internally
    };

public:
    
    void setWoolWhipRange(f32 newRange, bool ignoreConditions);
    void setupCallbacks();
    void setPlayerState(PlayerState state);
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