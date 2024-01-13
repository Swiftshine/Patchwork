/*
 * Kamek Standard Library
 * Wii game patching engine
 * (c) Treeki 2010-2018
 */

#ifndef __KAMEK_H
#define __KAMEK_H

#ifndef __MWERKS__
#error "Kamek requires the CodeWarrior compiler!"
#endif

#include <types.h>

#define NULL 0
typedef volatile s64 vs64;
typedef volatile s32 vs32;
typedef volatile s16 vs16;
typedef volatile s8 vs8;
typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef volatile u8 vu8;
typedef volatile f64 vf64;
typedef volatile f32 vf32;

typedef unsigned long size_t;

#include "kamek/hooks.h"
#include "c_stdlib.h"
#include "revolution/os.h"

#endif

