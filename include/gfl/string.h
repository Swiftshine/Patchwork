#ifndef GFL_STRING_H
#define GFL_STRING_H

#include "types.h"

namespace GFL {
namespace String {
    // size: 0xC
    class BasicString {
    public:
        BasicString(char* source);
        BasicString(GFL::String::BasicString* source)
        ~BasicString();
    public:
        void append(u32 offset, u32 numChars, char* sourceBegin, char* sourceEnd);
        void append(u32 offset, u32 numChars, char* source);
        void append(char* source);
        void append(int offset, u32 numChars, GFL::String::BasicString* source);
        void append(GFL::String::BasicString* source1, char* source2);

        int compare(u32 pos, char* other, void* unk, u32 strLen);
        int compare(GFL::String::BasicString* other);

        void copy(char* source);
        void copy(GFL::String::BasicString* source);

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

    public:
        bool hasForwardSlash();
    public:
        char    string[512];
        u32     len;
    };
}
} // namsepace GFL

#endif