#include "types.h"
#include "kamek/kamek.h"


#define CAT_(a, b) a ## b
#define CAT(a, b) CAT_(a, b)
#define STRUCT_FILL(size) CAT(u8 unk_contents_, __LINE__)[size]
#define RETURN_IF_NULLPTR(ptr) if (ptr == nullptr) return;


namespace Game {
namespace Sound {
    void TryPlayMusic(int id, int delay);
}
}

enum MusicPlayerState {
    STATE_WAITING = 0,
    STATE_PLAY_MUSIC,
    STATE_DONE
};

static int sCurrentState = STATE_WAITING;

u32 GameManager_Instance_Ptr = 0x808E4D38;

struct BGSTFile {
    void CopyImageData(void** pCMPRImage, void** pI4Image, u32 sceneID, u32 x, u32 y);
};

struct BgImage2 {
    STRUCT_FILL(0x110);
    u32 mSceneID;
    BGSTFile* mBGSTFile;
};

struct Layer {
    STRUCT_FILL(0xC);
    BgImage2* mBgImage;
};

struct StageGraphicResources {
    STRUCT_FILL(0x48);
    Layer* mLayers;
};

struct LevelManager {
    STRUCT_FILL(0x18);
    StageGraphicResources mResources;
};

struct Stage {
    STRUCT_FILL(0x30);
    u32 mStageID;
    STRUCT_FILL(0x124);
    LevelManager* mLevelManager;
};

struct GameManager {
    STRUCT_FILL(0x6C);
    Stage* mStage;
};

void DoThing(u32 stageID, u32 layerIndex, u32 x, u32 y) {
    switch (sCurrentState) {
        case STATE_PLAY_MUSIC: {
            Game::Sound::TryPlayMusic(21, 0);
            sCurrentState = STATE_DONE;
        }
        case STATE_DONE: {
            return;
        }
    }

    // get the address of the specified layer's bg image
    GameManager* gameMgr = *((GameManager**)(0x808E4D38));

    RETURN_IF_NULLPTR(gameMgr);

    OSReport("Getting Stage...\n");
    Stage* stage = gameMgr->mStage;

    RETURN_IF_NULLPTR(stage);

    if (stageID != stage->mStageID) {
        OSReport("Not the target stage. Found: %d\n", stage->mStageID);
        return;
    }

    OSReport("Getting Level Manager...\n");
    LevelManager* lvlMgr = stage->mLevelManager;

    RETURN_IF_NULLPTR(lvlMgr);

    OSReport("Getting Stage Resource Manager...\n");
    StageGraphicResources* sgr = &lvlMgr->mResources;
    OSReport("Getting Layer By Index %d...\n", layerIndex);
    Layer* layer = &sgr->mLayers[layerIndex];

    RETURN_IF_NULLPTR(layer);

    OSReport("Getting BgImage...\n");
    BgImage2* bgImage = layer->mBgImage;

    RETURN_IF_NULLPTR(bgImage);
    
    void* cmpr;
    void* i4;

    bgImage->mBGSTFile->CopyImageData(&cmpr, &i4, bgImage->mSceneID, x, y);

    if (cmpr != nullptr) {
        OSReport("CMPR image address: %X\n", ((u32)(cmpr)));
        OSReport("State Address: %X\n", (u32)(&sCurrentState));
    } else {
        OSReport("CMPR image is nullptr!\n");

        if (i4 == nullptr) {
            OSReport("I4 image is nullptr!\n");
        }
    }
}

// entry - 0x801692e0
// exit - 0x801692e4
#define ENTRY 0x80084e10
#define EXIT ENTRY + 4
kmBranchDefAsm(ENTRY, EXIT) {


    // // save volatile registers
    stwu sp, -0x3C(sp)
    stw  r0,  0x08(sp)
    stw  r3,  0x0C(sp)
    stw  r4,  0x10(sp)
    stw  r5,  0x14(sp)
    stw  r6,  0x18(sp)
    stw  r7,  0x1C(sp)
    stw  r8,  0x20(sp)
    stw  r9,  0x24(sp)
    stw  r10, 0x28(sp)
    stw  r11, 0x2C(sp)
    stw  r12, 0x30(sp)
    mfcr r0
    stw  r0,  0x34(sp)
    mfctr r0
    stw  r0,  0x38(sp)
    mflr r0
    stw  r0,  0x40(sp)

    li r3, 50 // target stage id
    li r4, 0x0 // layer index
    li r5, 0x2 // x 
    li r6, 0x1 // y

    bl DoThing;

    // // restore volatile registers
    lwz  r0,  0x38(sp)
    mtctr r0
    lwz  r0,  0x34(sp)
    mtcr r0
    lwz  r0,  0x40(sp)
    mtlr r0
    lwz  r0,  0x08(sp)
    lwz  r3,  0x0C(sp)
    lwz  r4,  0x10(sp)
    lwz  r5,  0x14(sp)
    lwz  r6,  0x18(sp)
    lwz  r7,  0x1C(sp)
    lwz  r8,  0x20(sp)
    lwz  r9,  0x24(sp)
    lwz  r10, 0x28(sp)
    lwz  r11, 0x2C(sp)
    lwz  r12, 0x30(sp)
    addi sp,  sp, 0x3C

        // original instruction
    // lfs f0, -0x7E58(r2)
    // lfs f0, 0x5B0(r3)
    lwz r3, 0xC0C(r3)
}