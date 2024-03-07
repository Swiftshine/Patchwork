#include <macros.S>
#include <kamek/kamek_asm.S>
.text

# custom scale
# one thing to note is that these scale changes
# will only apply to FlfGameObj instances that
# don't otherwise change their scale.

kmBranchDef 0x8002BD58
    SaveVolatileRegisters

    # replace the float value here with whatever
    kamek_const_float f1, 3.0, r3
    
    stfs f1, 0x24(r30)
    stfs f1, 0x28(r30)
    stfs f1, 0x2C(r30)


    # original value
    kamek_const_float f1, 1.0, r3

    RestoreVolatileRegisters
    kamek_b 0x8002BD64