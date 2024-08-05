#pragma once

#include "api/stdint.h"
#include "arch/i386/CPUID.h"

class Processor{
public:
    static void init();

    static const char* vendor_string(){return s_vendor;}
    static CPUFeatures& features(){return s_features;}

    static void save_fpu_state(void*& fpu_state);
    static void load_fpu_state(void*& fpu_state);

private:
    struct CPUID{
        uint32_t eax;
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;
    };

    static CPUID cpuid(uint32_t op);

    static char s_vendor[sizepf(uint32_t) * 3 + 1];
    static CPUFeatures s_features;
};