#ifndef FLUFF_GIMMICK_BEAD_H
#define FLUFF_GIMMICK_BEAD_H

#include "game/object/gimmick/gimmick.h"

// Size: 0x21C
class Bead : Gimmick {
public:

void setWeight(f32 weight);
void setValue(u32 value);
u32 getValue();

public:

    f32 weight; // 0x17C, 0x4, this value is used to determine how much the bead should bounce up and down when hitting the ground. higher values = less bounce.
    u32 value; // 0x180, 0x4, this value is used to determine how much the bead is worth.
};

#endif