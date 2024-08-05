#pragma once

#include <kernel/kstd/types.h>

class KernelMapper {
public:
    struct Symbol{
        char* name;
        size_t location;
    };

    static void load_map();
    static Symbol* get_symbol(size_t location);
    static void print_stacktrace();
    static void print_stacktrace(size_t ebp);
    static void print_userspace_stacktrace();
    
}