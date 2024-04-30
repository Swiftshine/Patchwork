#ifndef GFL_TASK_H
#define GFL_TASK_H

#include <types.h>
#include "gfl/functorclassmethod.h"

namespace gfl {

    // Size: ??
    struct TaskInfo {
        char name[23];      // 0x0, 0x17
        u8 flag;            // 0x17, 0x1
        u32 _18;            // 0x18, 0x4
        u32 _1C;            // 0x1C, 0x4
        gfl::TaskInfo* _20; // 0x20, 0x4
    };

    // Size: 0x18
    class Task {
    public:
        void init(char* name);
    public:
        void* vtable;                                   // 0x0, 0x4
        gfl::TaskInfo* taskInfo;                        // 0x4, 0x4
        gfl::Functor* functor;                          // 0x8, 0x4
        void* functorClassMethod;                       // 0xC, 0x4
        // gfl::FunctorClassMethod0* functorClassMethod;   // 0xC, 0x4
        u32 _10;                                        // 0x10, 0x4
        u32 _14;                                        // 0x14, 0x4
    };

    // Unofficially named struct
    // Size: 0xE038
    class TaskManager {
    public:
        TaskManager* getInstance();
        void removeInstance();
    public:
        bool taskEnabled[1400];
        gfl::TaskInfo taskInfo[1400];
    };


} // namespace gfl


#endif