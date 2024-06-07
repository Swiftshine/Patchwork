#ifndef GFL_SCN_MODEL_WRAPPER_H
#define GFL_SCN_MODEL_WRAPPER_H

#include "types.h"
#include "gfl/renderobj.h"

namespace gfl {

    class ScnMdlWrapper : public gfl::RenderObj {
    public:
        ScnMdlWrapper();
        ~ScnMdlWrapper();
    public:
        void* _18;
        u32 _1C;
        Vec3f _20;
        void* function1;
        void* function2;
    };
}

#endif