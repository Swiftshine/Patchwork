#include <macros.S>
#include <kamek/kamek_asm.S>

.data
stringContents: .string  "Player state is %X\n\0"
.text

# hook into some PlayerBase function
kmBranchDef 0x80084e10
    # original instruction
    lwz r0, 0xC0C(r3)

    SaveVolatileRegisters

    # r3 is currently the player
    // r4 = r3->playerState
    lwz r4, 0xC10(r3)
    // r3 = &stringContents
    lis r3, stringContents@ha
    addi r3, r3, stringContents@l
    // OSReport()
    kamek_bl 0x806649C0
    RestoreVolatileRegisters
    kamek_b 0x80084e14