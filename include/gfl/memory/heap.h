#ifndef GFL_MEMORY_HEAP_H
#define GFL_MEMORY_HEAP_H

#include "types.h"

namespace gfl {
namespace Memory {
    
    enum HeapIDs {
        HeapID_None = 0,
        HeapID_LIB1,
        HeapID_LIB2,
        HeapID_String,
        HeapID_ETC,
        HeapID_Sound,
        HeapID_Work,
        HeapID_Resource,
    };

    struct ExpHeap;

    struct Heap {
        u8 heapID;
        char name[25];
        bool _1A;
        u8 _1B;
        void* heapHandle;
        void* alloc;
        gfl::Memory::ExpHeap* expHeap;
        u32 heapExpFlags;
        gfl::Memory::Heap* _2C;
        void* _30;
        void* _34;
        u32 flags;
        gfl::Memory::Heap* _3C;
        u32 memType;
    };

    struct ExpHeap {
        char magic[0x4]; // "EXPH"
        u32 _4;
        u32 alignment;
        Heap* heap;
        void* _10;
        void* _14;
        void* start;
        void* end;
        u32 _20;
        u32 _24;
        u32 _28;
        u32 _2C;
        u32 _30;
        u32 _34;
        u32 _38;
        u32 _3C;
        u32 _40;
        u32 _44;
        u32 _48;
        u16 _4C;
        u16 _4E;
    };
}
}

#endif