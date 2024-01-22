#ifndef FLUFF_BEAD_H
#define FLUFF_BEAD_H

#include "game/gimmick.h"

// Size: 0x21C
class Bead : Gimmick {
public:

void setBeadWeight(f64 weight);

public:

    f64 weight; // 0x17C, 0x8, this value is used to determine how much the bead should bounce up and down when hitting the ground. higher values = less bounce.
};

#endif