#ifndef FLUFF_GAME_MANAGER_H
#define FLUFF_GAME_MANAGER_H

#include "gfl/gfl.h"

class GameMgr {
public:
    GameMgr();
public:
    void* baseObject;           // 0x0
    u8 _4[0x6C - 0x4];          // 0x4
    GFL::Task* stageTask;       // 0x6C
    u8 unk2[0x84 - 0x70];       // 0x70
    GFL::Task* task2;           // 0x84
    u8 unk3[0x90 - 0x88];       // 0x88
    void* functorClassMethod;   // 0x90
    u8 unk4[0xA0 - 0x94];       // 0x94
    void* buffer;               // 0xA0
    u8 unk5[0xC0 - 0xA4];       // 0xA4
};

static_assert(sizeof(GameMgr) == 0xC0, "GameMgr is not the correct size.");

#endif