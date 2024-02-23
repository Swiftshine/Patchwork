#ifndef GFL_GFA_H
#define GFL_GFA_H

#include "types.h"

struct GFAC {
    char magic[4]; // "GFAC"
    u32 _4;
    u32 version;
    u32 fileCountOffset;
    u32 fileInfoSize;
    u32 dataOffset;
    u32 dataSize;
    u8 padding[0x10];
    u32 fileCount;
}; // size: 0x30

struct FileEntry { // unofficial name
    u32 hash;
    u32 nameOffset;
    u32 size;
    u32 dataOffset;
}; // Size: 0x10

struct GFCP {
    char magic[4]; // "GFCP"
    u32 version;
    u32 compressionType;
    u32 decompressedSize;
    u32 compressedSize;
}; // Size: 0x14 (i think)
#endif