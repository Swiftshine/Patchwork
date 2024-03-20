#include <macros.S>
#include <kamek/kamek_asm.S>
.text


kmBranchDef 0x8002BD88
    SaveVolatileRegisters

    kamek_const_float f1, 30.0, r3

    stfs f2, 0x54(r30)
    stfs f2, 0x58(r30)
    stfs f2, 0x5C(r30)
    
    # original value
    kamek_const_float f2, 0.0, r3

    RestoreVolatileRegisters
    kamek_b 0x8002BD94