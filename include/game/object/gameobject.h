#ifndef FLUFF_GAME_OBJECT_H
#define FLUFF_GAME_OBJECT_H

#include <types.h>
#include "game/object/handleobject.h"
// size unknown
class FlfGameObj : public FlfHandleObj {
public:
    FlfGameObj(char* name);
public:
    Vec3f position; // 0xC, 0xC
    Vec3f rotation; // 0x18, 0xC
    Vec3f scale;    // 0x24, 0xC
};


typedef FlfGameObj GameObject;

#endif