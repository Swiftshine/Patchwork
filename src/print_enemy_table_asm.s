#include <macros.S>
#include <kamek/kamek_asm.S>

.data
printName:  .string "table->name: %s\n\0"
printCtor:  .string "table->ctor/caller: %p\n\0"
printRelatedEnemyName: .string "table->relatedEnemyName: %s\n\0"
printPath:  .string "table->path: %s\n\0"
#printID:    .string "table->someID: %d\n\0"
.text

# a comment
// psuedocode

# print name
# hook into `getEnemyNameByID()`
kmBranchDef 0x8012E958
    # original instruction
    lwz r3, 0x4(r3)

    # r3 is currently the ptr to the name string
    SaveVolatileRegisters

    // r4 = r3
    mr r4, r3
    // r3 = &printName
    lis r3, printName@ha
    addi r3, r3, printName@l

    // OSReport(r3, r4)
    kamek_bl 0x806649C0

    # done
    RestoreVolatileRegisters
    kamek_b 0x8012E95C # 'blr'

# print constructor (or constructor caller) address
# hook into `getEnemyConstructorByID()`
kmBranchDef 0x8012D484
    # original instruction
    lwz r3, 0x8(r3)

    # r3 is currently the ctorCaller addr (the one we want to print)
    SaveVolatileRegisters

    // r4 = r3
    mr r4, r3
    // r3 = &printCtor
    lis r3, printCtor@ha
    addi r3, r3, printCtor@l

    // OSreport(r3, r4)
    kamek_bl 0x806649C0

    # done
    RestoreVolatileRegisters
    kamek_b 0x8012D488 # 'blr'

# print related enemy name
# hook into `getEnemyRelatedEnemyNameByID()`
kmBranchDef 0x8012E970
    # original instruction
    lwz r3, 0xC(r3)

    # you get it by this point. just look at the EnemyTable struct
    SaveVolatileRegisters
    mr r4, r3
    lis r3, printRelatedEnemyName@ha
    addi r3, r3, printRelatedEnemyName@l
    kamek_bl 0x806649C0
    RestoreVolatileRegisters
    kamek_b 0x8012e974 # 'blr'

# print enemy resource path
kmBranchDef 0x8012e988
    # original instruction
    lwz r3, 0x10(r3)
    SaveVolatileRegisters
    mr r4, r3
    lis r3, printPath@ha
    addi r3, r3, printPath@l
    kamek_bl 0x806649C0
    RestoreVolatileRegisters
    kamek_b 0x8012e98C

# currently no in-game function to return an EnemyTable.someID but dw about it for now