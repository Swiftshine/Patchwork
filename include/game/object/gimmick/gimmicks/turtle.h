#ifndef FLUFF_GIMMICK_TURTLE_H
#define FLUFF_GIMMICK_TURTLE_H

#include "game/object/gimmick/gimmick.h"
#include "game/object/playerbase.h"

// it actually inherits from PhysicsGimmick but they're the same size
class GmkTurtle : Gimmick {
    enum TurtleState {
        State_0,
        MoveLeft,
        TurningRight,
        State_3,
        MoveRight,
        TurningLeft,
        State_6,
        State_7,
        State_8,
    };

public:
    static GmkTurtle* build(void* unk1);   // returns a new GmkTurtle

    GmkTurtle(void* unk1);
    ~GmkTurtle();

    void update();  // occurs every frame
    void turn();    // called when the turtle is instructed to turn by internal or external factors
    int turnOnPlayerWeight(PlayerBase* player); // called by player. occurs when the player is a weight

    /* unknown functions (these use American addresses)*/

    void FUN_804FB1CC();
    void FUN_804FB1D4();
public:
    u32 counterDefaultValue;    // the counter is always reset to this value once it hits zero
    f32 speed;                  // x speed
    f32 _138;
    bool _13C;
    bool _13D;
    u16 _13E;
    u32 counter;                // used for various computations
    u32 numTurtles;             // determines the number of turtle objects to spawn in.
    // TurtleState state;
    u32 state;
    Gimmick* water;
    void* anmCtrl;              // animation control
    void* colObjTrans;          // collision object
    void* flfRideHitCtrlTrans;  // makes it rideable
};

typedef GmkTurtle Turtle;

#endif