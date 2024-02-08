.text

SaveVolatileRegisters: .macro
    stwu r1, -0x3C(r1)
    stw  r0,  0x08(r1)
    stw  r3,  0x0C(r1)
    stw  r4,  0x10(r1)
    stw  r5,  0x14(r1)
    stw  r6,  0x18(r1)
    stw  r7,  0x1C(r1)
    stw  r8,  0x20(r1)
    stw  r9,  0x24(r1)
    stw  r10, 0x28(r1)
    stw  r11, 0x2C(r1)
    stw  r12, 0x30(r1)
    mfcr r0
    stw  r0,  0x34(r1)
    mfctr r0
    stw  r0,  0x38(r1)
    mflr r0
    stw  r0,  0x40(r1)
.endm

RestoreVolatileRegisters: .macro
    lwz  r0,  0x38(r1)
    mtctr r0
    lwz  r0,  0x34(r1)
    mtcr r0
    lwz  r0,  0x40(r1)
    mtlr r0
    lwz  r0,  0x08(r1)
    lwz  r3,  0x0C(r1)
    lwz  r4,  0x10(r1)
    lwz  r5,  0x14(r1)
    lwz  r6,  0x18(r1)
    lwz  r7,  0x1C(r1)
    lwz  r8,  0x20(r1)
    lwz  r9,  0x24(r1)
    lwz  r10, 0x28(r1)
    lwz  r11, 0x2C(r1)
    lwz  r12, 0x30(r1)
    addi r1,  r1, 0x3C
.endm

SafeBranch: .macro __addr__
    SaveVolatileRegisters
    bl __addr__
    RestoreVolatileRegisters
.endm

RefreshVolatileRegisters: .macro
    RestoreVolatileRegisters
    SaveVolatileRegisters
.endm