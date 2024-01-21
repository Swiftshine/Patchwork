#ifndef GFL_TASK_H
#define GFL_TASK_H

#include <types.h>

namespace GFL {

// Size currently unknown
class Task {
public:
    void setName(char* name);
public:
    void* baseObject;
    char* taskName;
    
};


} // namespace GFL


#endif