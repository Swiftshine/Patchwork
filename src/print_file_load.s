#include <macros.S>
#include <kamek/kamek_asm.S>

.data
stringContents: .string  "\ngfl::FileWii::open - %s\n\0"
.text

# hook into gfl::FileWii::open()

kmBranchDef 0x80642190
    # original instruction
    stwu r1, -0x10(r1)
    SaveVolatileRegisters
    # r3 is currently the filename

    // r4 = r3
    mr r4, r3
    // r3 = &stringContents
    lis r3, stringContents@ha
    addi r3, r3, stringContents@l

    // OSReport()
    kamek_bl 0x806649C0
    RestoreVolatileRegisters
    # continue
    kamek_b 0x80642194

