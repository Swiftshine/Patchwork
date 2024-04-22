#include "gfl/file/file.h"
#include "gfl/functor.h"
#include "gfl/functorclassmethod.h"
#include "gfl/param.h"
#include "gfl/task.h"
#include "gfl/string.h"

namespace gfl {
    void alloc(int heapID, size_t size, int alignment);
    u32 getHashFromStr(char* str);
    void* cast(void* unk1, u32 unk2, void* destType, void* sourceType, u32 unk3);
    void memcpy(void* dst, u32 len, void* src);
} // namespace gfl