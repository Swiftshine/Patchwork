#ifndef GFL_OBJECT_H
#define GFL_OBJECT_H

#include <types.h>
#include "gfl/task.h"
// Size currently unknown

namespace GFL {


class Object {
public:
    void* baseObject;
    GFL::Task* task;
};

} // namespace GFL
#endif