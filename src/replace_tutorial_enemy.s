#include <kamek/kamek_asm.S>

# waddle dee
kmBranchDef 0x803e1810
    kamek_bl 0x803e3244 # parasol waddle dee constructor
    kamek_b 0x803e1814 # next instruction

# blipper
#kmBranchDef 0x803e17dc
    #kamek_bl 0x803aaa80
    #kamek_b 0x803e17E0