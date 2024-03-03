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
        void appendFromGFLString(int offset, u32 numChars, GFL::BasicString* source);
        u32 compare(u32 pos, char* str1, void* unk, u32 strLen);
        void removeTrailingSlash();
        void free();
        GFL::BasicString* fromCString(char* source);
        GFL::BasicString* fromGFLString(GFL::BasicString* source);
        bool matches(char* other);
        void reserve(u32 len);
    public:
        char* strBegin;
        char* strEnd;
        char* string;
    };
} // namsepace GFL

#endif