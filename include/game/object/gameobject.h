#ifndef FLUFF_GAME_OBJECT_H
#define FLUFF_GAME_OBJECT_H

#include <types.h>
#include "game/object/handleobject.h"
// size unknown
class FlfGameObj : public FlfHandleObj {
public:
    FlfGameObj(char* name);
    bool objectTypeMatches(char* type);
public:
    Vec3f position; // 0xC, 0xC
    void* _18;      // 0x18, 0x4
};


typedef FlfGameObj GameObject;

#endif