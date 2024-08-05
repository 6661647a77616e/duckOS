#include "multiboot.h"
#include <kernel/kstd/unix_types.h>

struct multiboot_info parase_mboot(uint32_t physaddr);
extern "C" int kmain(uint32_t mbootptr);
void kmain_late();
