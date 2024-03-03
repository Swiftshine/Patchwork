#include "gfl/file/file.h"
#include "gfl/functor.h"
#include "gfl/functorclassmethod.h"
#include "gfl/param.h"
#include "gfl/task.h"

namespace GFL {
    void* dynamicCast(void* unk1, u32 unk2, void* destType, void* sourceType, u32 unk3);
    void initStructures(void* dest, void* ctor, void* dtor, size_t structureSize, u32 numStructures);
} // namespace GFL