#include <macros.S>
#include <kamek/kamek_asm.S>

.data
printSeparator: .string "**********\n\0"
printID:    .string "table->enemyID: %d\n\0"
printCtor:  .string "table->ctor/caller: %p\n\0"
printLinkedEnemyName: .string "table->linkedEnemyName: %s\n\0"
printPath:  .string "table->path: %s\n\0"
printName:  .string "table->name: %s\n\0"
enemyTable: .int 0
.text

# hook into 'getEnemyNameByID()'
kmBranchDef 0x8012E958
    # r3 is currently an EnemyTable** (pointer to a pointer)
    SaveVolatileRegisters

    lis r3, printSeparator@ha
    addi r3, r3, printSeparator@l
    // OSReport()
    kamek_bl 0x806649C0

    RefreshVolatileRegisters
    lis r4, enemyTable@ha
    addi r4, r4, enemyTable@l
    stw r3, 0x0(r4)
        # Print ID
    lwz r4, 0x0(r4) # address
    lwz r4, 0x0(r4) # actual value
    lis r3, printID@ha
    addi r3, r3, printID@l

    
    kamek_bl 0x806649C0

    RefreshVolatileRegisters
        # Print name
    lis r4, enemyTable@ha
    addi r4, r4, enemyTable@l
    lwz r4, 0x0(r4)
    lwz r4, 0x4(r4)
    lis r3, printName@ha
    addi r3, r3, printName@l
    kamek_bl 0x806649C0

    RefreshVolatileRegisters
        # Print constructor
    lis r4, enemyTable@ha
    addi r4, r4, enemyTable@l
    lwz r4, 0x0(r4)
    lwz r4, 0x8(r4)
    lis r3, printCtor@ha
    addi r3, r3, printCtor@l
    kamek_bl 0x806649C0

    RefreshVolatileRegisters
        # Print linked enemy name
    lis r4, enemyTable@ha
    addi r4, r4, enemyTable@l
    lwz r4, 0x0(r4)
    lwz r4, 0xC(r4)
    lis r3, printLinkedEnemyName@ha
    addi r3, r3, printLinkedEnemyName@l
    kamek_bl 0x806649C0

    RefreshVolatileRegisters
        # Print filepath
    lis r4, enemyTable@ha
    addi r4, r4, enemyTable@l
    lwz r4, 0x0(r4)
    lwz r4, 0x10(r4)
    lis r3, printPath@ha
    addi r3, r3, printPath@l
    kamek_bl 0x806649C0

    # done, restore functionality of original function
    RestoreVolatileRegisters
    # original instruction
    lwz r3, 0x4(r3)
    kamek_b 0x8012E95C # jump to next instruction