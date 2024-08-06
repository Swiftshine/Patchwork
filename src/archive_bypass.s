#include <macros.S>
#include <kamek/kamek_asm.S>

# this hack allows you to avoid using gfa files entirely.
# (assuming you're using riivolution) create a folder in the same 
# directory as the archive and place your files there


.data
gfaEnding: .string ".gfa\0"
.text

# gfl::ResArchivedFileInfo::fromArchive


# this is some messy assembly but bear with me
kmBranchDef 0x8002261c
    # original instruction
    li r4, 0x0

    // r3 is currently the filename
    SaveVolatileRegisters
    mr r4, r3

    # strlen(r3)
    kamek_bl 0x8068ca10

    cmpwi r3, 0x4
    bgt IsGreaterThanFour
    RestoreVolatileRegisters
    b Ending

IsGreaterThanFour:

    mr r5, r3
    mr r3, r4
    subi r5, r5, 0x5
    add r3, r5, r3

    lis r5, gfaEnding@ha
    addi r5, r5, gfaEnding@l
    SaveVolatileRegisters
    mr r4, r5

    # strcmp
    kamek_bl 0x806948a8

    cmpwi r3, 0x0
    beq StringsMatch
    RestoreVolatileRegisters
    RestoreVolatileRegisters
    b Ending
StringsMatch:
    RestoreVolatileRegisters
    SaveVolatileRegisters
    mr r3, r4
    # gfl::FileExists
    kamek_bl 0x8063c718
    cmpw r3, 0x1
    beq FileDoesExist
    RestoreVolatileRegisters
    # this part is just to prevent the consecutive restorations from being optimised out
    nop
    nop
    addi r1, r1, 0x4
    nop
    nop
    subi r1, r1, 0x4
    nop
    nop
    # it might have been excessive...
    RestoreVolatileRegisters
    b Ending
FileDoesExist:
    RestoreVolatileRegisters
    RestoreVolatileRegisters
    li r4, 0x1
Ending:
    kamek_b 0x80022620