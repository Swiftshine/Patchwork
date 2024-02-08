#include <macros.S>
#include <kamek/kamek_asm.S>

.data
linkReg: .int 0
enemyTableAddr: .int 0
printName:  .string "table->name  : %s\n\0"
printCtor:  .string "table->ctor  : %p\n\0"
printEight: .string "table->_8    : %s\n\0"
printPath:  .string "table->path  : %s\n\0"
printID:    .string "table->someID: %d\n\0"

.text

kmBranchDef 0x8012d480
    # original instruction
    add  r3, r3, r0

    # r3 is currently an EnemyTable*
    SaveVolatileRegisters

    # store link register in 'linkReg'
    mflr r4
    lis  r5, linkReg@ha
    addi r5, r5, linkReg@l
    stw r4, 0x0(r5)

    # store r3 in 'enemyTableAddr'
    lis r5, enemyTableAddr@ha
    addi r5, r5, enemyTableAddr@l
    stw r3, 0x0(r5)

    RefreshVolatileRegisters
    # 1st OSReport call
        # r3 = the addr of the 'printName' string
    lis r3, printName@ha
    addi r3, r3, printName@l
        # r4 = enemyTable.name
    lis r4, enemyTableAddr@ha
    addi r4, r4, enemyTableAddr@l
    lwz r4, 0x0(r4)
    kamek_bl 0x806649C0
    RefreshVolatileRegisters

    # 2nd OSReport call
        # r3 = the addr of the 'printCtor' string
    lis r3, printCtor@ha
    addi r3, r3, printCtor@l
        # r4 = enemyTable.constructor
    lis r4, enemyTableAddr@ha
    addi r4, r4, enemyTableAddr@l
    lwz r4, 0x4(r4)
    kamek_bl 0x806649C0
    RefreshVolatileRegisters

    # 3rd OSReport call
        # r3 = the addr of the `printEight` string
    lis r3, printEight@ha
    addi r3, r3, printEight@l
        # r4 = enemyTable._8
    lis r4, enemyTableAddr@ha
    addi r4, r4, enemyTableAddr@l
    lwz r4, 0x8(r4)
    kamek_bl 0x806649C0
    RefreshVolatileRegisters

    # 4th OSReport call
        # r3 = the addr of the `printPath` string
    lis r3, printPath@ha
    addi r3, r3, printPath@l
        # r4 = enemyTable.path
    lis r4, enemyTableAddr@ha
    addi r4, r4, enemyTableAddr@l
    lwz r4, 0xC(r4)
    kamek_bl 0x806649C0
    RefreshVolatileRegisters

    # 5th OSReport call
        # r3 = the addr of the `printID` string
    lis r3, printID@ha
    addi r3, r3, printID@l
        # r4 = enemyTable.someID
    lis r4, enemyTableAddr@ha
    addi r4, r4, enemyTableAddr@l
    lwz r4, 0x10(r4)
    kamek_bl 0x806649C0
    RefreshVolatileRegisters

    # done with printing, restore link register and volatile registers
    lis  r5, linkReg@ha
    addi r5, r5, linkReg@l
    lwz r4, 0x0(r5)
    mtlr r4
    RestoreVolatileRegisters

    kamek_b 0x8012d484