#include <kamek/kamek_asm.S>
#include <macros.S>

.data
# default value = 9.80665
gravityConstantCustom: .float 11.0
# default value = 60.0
timeIntervalCustom: .float 75.0
.text
# hook into getGravity()
kmBranchDef 0x8009b194
    # save link register and r3
    mflr r0
    stw r0, -0x4(r1)
    stw r3, -0x8(r1)

    // r3 = &gravityConstantCustom
    lis r3, gravityConstantCustom@ha
    addi r3, r3, gravityConstantCustom@l

    // f0 = *r3
    lfs f0, 0x0(r3)

    // GravityConstant = f0
    stfs f0, -0x759c(r2)

    // r3 = &timeIntervalCustom
    lis r3, timeIntervalCustom@ha
    addi r3, r3, timeIntervalCustom@l

    // f0 = *r3
    lfs f0, 0x0(r3)

    // TimeInterval = f0
    stfs f0, -0x7E58(r2)


    # restore link register and r3
    lwz r3, -0x8(r1)
    lwz r0, -0x4(r1)
    mtlr r0

    # original instruction
    lfs f0, -0x7E58(r2)
    kamek_b 0x8009b198 # continue to next instruction