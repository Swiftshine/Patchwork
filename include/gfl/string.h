#ifndef GFL_STRING_H
#define GFL_STRING_H

#include "types.h"

namespace GFL {

    // size: 0xC
    class BasicString {
    public:
        BasicString();
    public: 
        static void appendFromCString(GFL::BasicString* dest, u32 offset, u32 numChars, char* sourceBegin, char* sourceEnd);
        static void appendFromCString(GFL::BasicString* dest, u32 offset, u32 numChars, char* source);
        static void appendFromCString(GFL::BasicString* dest, char* source);
        static void appendFromGFLString(GFL::BasicString* dest, int offset, u32 numChars, GFL::BasicString* source);
        static void appendFromGFLAndCStrings(GFL::BasicString* dest, GFL::BasicString* source1, char* source2);
        static u32 compare(u32 pos, char* str1, void* unk, u32 strLen);
        static void copyFromCString(GFL::BasicString* dest, char* source);
        static void copyFromGFLString(GFL::BasicString* dest, GFL::BasicString* source);
        static void freeCStr(char* str);
        static void freeGFLStr(GFL::BasicString* string, int unk = 0xFFFFFFFF);
        static GFL::BasicString* fromCString(char* source);
        static GFL::BasicString* fromGFLString(GFL::BasicString* source);
        static bool matches(GFL::BasicString* first, char* second);
        static void removeTrailingSlash(GFL::BasicString* dest);
        static void reserve(GFL::BasicString* dest, u32 len);
    public:
        char* strBegin;
        char* strEnd;
        char* string;
    };
} // namsepace GFL

#endif