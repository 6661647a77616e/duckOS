#pragma once

#include "tasking/Thread.h"

namespace StackWalker{
    struct Frame {
        Frame* next_frame;
        VirtualAddress ret_addr;
    };

    Frame* walk_stack(const kstd::Arc<Thread>& thread, uintptr_t* addr_buf, size_tptr_bufsz, StackWalker::Frame* start_frame);
};