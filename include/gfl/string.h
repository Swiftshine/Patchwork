#ifndef GFL_STRING_H
#define GFL_STRING_H

#include "types.h"

namespace GFL {

    // size: 0xC
    class BasicString {
    public:
        // all of these are this_calls
        BasicString();

        void appendFromCString(u32 offset, u32 numChars, char* sourceBegin, char* sourceEnd);
        void appendFromCString(u32 offset, u32 numChars, char* source);
        void appendFromCString(char* source);
        void appendFromGFLString(int offset, u32 numChars, GFL::BasicString* source);
        void appendFromGFLAndCStrings(GFL::BasicString* source1, char* source2);
        u32 compare(u32 pos, char* str1, void* unk, u32 strLen);
        void copyFromCString(char* source);
        void copyFromGFLString(GFL::BasicString* source);
        void freeCStr(char* str);
        void freeGFLStr(int unk);
        GFL::BasicString* fromCString(char* source);
        GFL::BasicString* fromGFLString(GFL::BasicString* source);
        bool matches(char* other);
        void removeTrailingSlash();
        void reserve(u32 len);
    public:
        char* strBegin;
        char* strEnd;
        char* string;
    };
} // namsepace GFL

#endif