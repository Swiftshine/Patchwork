#ifndef FLUFF_GAME_MGR_H
#define FLUFF_GAME_MGR_H

#include <types.h>

namespace GameMgr {
    // these probably don't actually belong to GameMgr
    void loadLevel(u32* unk1, u32* unk2);
    void loadStageDataFromID(u32* unk1, u32 stageID);
    void loadMapdataFromID(u32* unk1, u32 stageID);
    void loadCommonFromID(u32* unk1, u32 stageID);
    void loadBgFromID(u32* unk1, u32 stageID);
} // namespace GameMgr

#endif