#ifndef FLUFF_GAME_ROOT_MGR_H
#define FLUFF_GAME_ROOT_MGR_H

#include "gfl/gfl.h"
#include "game/mgr/mgrbase.h"

// Size: 0x70
// Offset, size, comment
class GameRootMgr {
public:

public:
    MgrBase self; // 0x0, 0x18
    MgrBase updateAftAnm; // 0x18, 0x18
    MgrBase changeMatrix; // 0x30, 0x18
    MgrBase updateAftAnmForEnv; // 0x48, 0x18
    u8 unk1[0x70 - 0x60]; // 0x60, 0x10
};

static_assert(sizeof(GameRootMgr) == 0x70, "GameRootMgr is not the correct size.");
#endif