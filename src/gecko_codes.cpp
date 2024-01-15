#include "kamek/kamek.h"

// This file contains ASM that matches various gecko codes
// that were made for this game. If you want to use any 
// of these, uncomment them. If you are aware of the
// authors of these codes, let me know!

// All 52 Tunes
/*
kmBranchDefAsm(0x804B319C, 0x804b31a4) {
    li r0, 0x1;
    stw r0, 0x0(r3);
}*/

// All 9 Flicks
/*
kmBranchDefAsm(804B41C8, 0x804b41d0) {
    li r0, 0x3;
    stw r0, 0x0(r27);
}*/

// Invincible
/*
kmBranchDefAsm(0x80088CC8, 0x80088CCC) {
    stw r4, 0x834(r3);  
}*/