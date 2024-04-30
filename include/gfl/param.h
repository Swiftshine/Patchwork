#ifndef GFL_PARAM_H
#define GFL_PARAM_H

// no padding pls
#pragma pack(push, 1)
#include <types.h>

#include "gfl/string.h"
// For the sake of consistency and clarity,
// DO NOT use the terms 'name' and 'label' interchangeably.
// They are not the same thing.


// A label cannot exceed 32 bytes.
// This includes the null terminator.

namespace gfl {
namespace Param {
    /* begin custom stuctures */

    // An unofficial base structure for GFL parameters.
    class ParamBase { };

    /* end custom structures */


    // Confirms if the given label and hash correspond to those of
    // the GFL param.
    static bool isValid(ParamBase* param, char* label, u32 hash);
    // Assigns a label and hash to a GFL param.
    static void set(ParamBase* param, char* label, u32 hash);


    class ParamPtr {
        // this one in particular is relatively vague.
    };

    class ParamBool : public ParamBase {
    public:
        ParamBool(char* label);
        ~ParamBool();
    public:
        void* vtable;           // 0x0, 0x4
        char label[0x20];       // 0x4, 0x20
        u32 hash;               // 0x24, 0x4
        u8 padding[3];          // 0x28, 0x3
        bool value;             // 0x2B, 0x1
        gfl::String::BasicString* _2C;  // 0x2C, 0x4
    };


    class ParamS32 : public ParamBase {
    public:
        ParamS32(char* label);
        ~ParamS32();

        void print(u32 unk1, u32 unk2);
    public:
        void* vtable;           // 0x0, 0x4
        char label[0x20];       // 0x4, 0x20
        u32 hash;               // 0x24, 0x4
        s32 value;              // 0x28, 0x4
        gfl::String::BasicString* _2C;  // 0x2C, 0x4
    };

    class ParamF32 : public ParamBase {
    public:
        ParamF32(char* label);

        void print(u32 unk1, u32 unk2);
    public:
        void* vtable;           // 0x0, 0x4
        char label[0x20];       // 0x4, 0x20
        u32 hash;               // 0x24, 0x4
        f32 value;              // 0x28, 0x4
        gfl::String::BasicString* _2C;  // 0x2C, 0x4
    };

    class ParamStr : public ParamBase {
    public:
        ParamStr(char* label);
        ~ParamStr();

        void print(u32 unk1, u32 unk2);
    public:
        void* vtable;               // 0x0, 0x4
        char label[0x20];           // 0x4, 0x20
        u32 hash;                   // 0x24, 0x4
        gfl::String::BasicString* value;    // 0x28, 0x4
        gfl::String::BasicString* _2C;      // 0x2C, 0x4
        gfl::String::BasicString* _30;      // 0x30, 0x4
    };


    class ParamGroup : public ParamBase {
    public:
        // ParamGroup();
        ~ParamGroup();

        // Prints contents.
        void print(u32 unk1, u32 unk2);

        // Returns a ParamGroup* by its label.
        static ParamGroup* getByLabel(char* label);
        // Generates a ParamGroup* with a label.
        static ParamGroup* fromLabel(char* label);

        // Returns an S32 param by label.
        ParamS32* paramS32ByLabel(char* label);

    public:
        void* vtable;               // 0x0, 0x4
        char label[0x20];           // 0x4, 0x20
        u32 hash;                   // 0x24, 0x4
        void* value;                // 0x28, 0x4
        gfl::String::BasicString* _2C;      // 0x2C, 0x4
        void* _30;                  // 0x30, 0x4
    };


} // namespace Param
} // namespace gfl

#endif
#pragma pack(pop)