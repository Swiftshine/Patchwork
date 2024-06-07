#ifndef GFL_RENDER_OBJ_H
#define GFL_RENDER_OBJ_H

#include "types.h"

namespace gfl {

    // size is probably 0xE8
    class UnkRenderRelatedClass { };

    class RenderObj {
    public:
        RenderObj();
        ~RenderObj();
    public:
        void* vtable;
        void* memoryRelated;
        u32 _8;
        u8 _C;
        u8 _D;
        u8 _E;
        u8 _F;
        f32 _10;
        u32 _14;
    };


    class CustomRenderObj : public UnkRenderRelatedClass, public RenderObj {
    public:
        CustomRenderObj(u8 unk1, u8 unk2);
        ~CustomRenderObj();
    public:

    };
}

#endif