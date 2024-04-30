#ifndef GFL_STRING_H
#define GFL_STRING_H

#include "types.h"

namespace gfl {
namespace String {

    class FixedString512;
    
    // size: 0xC
    class BasicString {
    public:
        BasicString(char* source);
        BasicString(gfl::String::BasicString* source);
        ~BasicString();
    public:
        // i can't tell if these are actual functions or operator overloads
        void append(u32 offset, u32 numChars, char* sourceBegin, char* sourceEnd);
        void append(u32 offset, u32 numChars, char* source);
        void append(char* source);
        void append(int offset, u32 numChars, gfl::String::BasicString* source);
        void append(gfl::String::BasicString* source1, char* source2);
        void append(gfl::String::FixedString512* source);

        int compare(u32 pos, char* other, void* unk, u32 strLen);
        int compare(gfl::String::BasicString* other);

        void copy(char* source);
        void copy(gfl::String::BasicString* source);

        static void freeCStr(char* str);

        bool matches(char* other);
        void removeTrailingSlash();
        void reserve(u32 len);
    public:
        char* strBegin;
        char* strEnd;
        char* string;
    };

    class FixedString512 {
    public:
        FixedString512();
        ~FixedString512();

        void copy(char* source);
        void copy(gfl::String::BasicString* source);
    public:
        bool hasForwardSlash();
    public:
        char    string[512];
        u32     len;
    };
} // namespace String
} // namsepace GFL

#endif