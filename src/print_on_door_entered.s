#include <macros.S>
#include <kamek/kamek_asm.S>

.data
stringContents: .string  "PlayerBase::enterDoor() called!\n\0"
.text

# hook into PlayerBase::enterDoor()

kmBranchDef 0x80072ADC
    # original instruction
    stwu r1, -0x20(r1)

    SaveVolatileRegisters
    // r3 = &stringContents
    lis r3, stringContents@ha
    addi r3, r3, stringContents@l

    // OSReport()
    kamek_bl 0x806649C0
    RestoreVolatileRegisters
    kamek_b 0x80072AE0