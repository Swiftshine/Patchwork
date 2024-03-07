#include "gfl/file/file.h"
#include "gfl/functor.h"
#include "gfl/functorclassmethod.h"
#include "gfl/param.h"
#include "gfl/task.h"
#include "gfl/string.h"

namespace GFL {
    void alloc(int heapID, size_t size, int alignment);
    u32 getHashFromStr(char* str);
    void* cast(void* unk1, u32 unk2, void* destType, void* sourceType, u32 unk3);
} // namespace GFL