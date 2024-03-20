#ifndef FLUFF_GAME_OBJECT_H
#define FLUFF_GAME_OBJECT_H

#include <types.h>
#include "game/object/handleobject.h"

// size: 0x80 (i think)
class FlfGameObj : public FlfHandleObj {
public:
    FlfGameObj(char* name);
public:
    Vec3f position;         // 0x0C, 0xC
    Vec3f rotation;         // 0x18, 0xC
    Vec3f scale;            // 0x24, 0xC
    Mtx33 _30;              // 0x30, 0x24
    Vec3f _54;              // 0x54, 0xC
    void* _60;              // 0x60, 0x4
    void* _64;              // 0x64, 0x4
    char* name;             // 0x68, 0x4
    bool _6C;               // 0x6C, 0x1
    bool _6D;               // 0x6D, 0x1
    bool _6E;               // 0x6E, 0x1
    bool _6F;               // 0x6F, 0x1
    float cullingThreshold; // 0x70, 0x4
    void* _74;              // 0x74, 0x4
    void* _78;              // 0x78, 0x4
    bool _7C;               // 0x7C, 0x1
    bool _7D;               // 0x7D, 0x1
    u16  _7E;               // 0x7E, 0x2
};

typedef FlfGameObj GameObject;

#endif