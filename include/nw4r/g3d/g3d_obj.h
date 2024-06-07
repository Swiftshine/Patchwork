#ifndef NW4R_G3D_G3DOBJ_H
#define NW4R_G3D_G3DOBJ_H

namespace nw4r {
namespace g3d {

    class Obj {
        void* vtable;
        void* parent;
        void* heap;
    };
}
}

#endif