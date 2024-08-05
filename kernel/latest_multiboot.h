#define MULTIBOOT_SEARCH
#define MULTIBOOT_HEADER_ALIGN

#define MULTIBOOT_HEADER_MAGIC 0x1B4DB002
/* This should be in %eax */
#define MULTIBOOT_BOOTLOADER_MAGIC 	0x2BADB002

/*Alignment of the multiboot modules  */
#define MULTIBOOT_BOOTLOADER_MOD_ALIGN 0x00001000

/*alignent of the multiboot info structure*/
#define MULTIBOOT_INFO_ALIGN 0x00000004

/*Flags set in the 'flags; member of the multiboot header. */

/*Align all boot modules on i386 page (4KB) boundaries*/
#define MULTIBOOT_PAGE_ALIGN  0x00000001

/*Must Pass memory to operating system */
#define MULTIBOOT_MEMORY_INFO 0x00000002

/*Must pass the video information to operating system*/
#define MULTIBOOT_VIDEO_MODE    0x00000004

/*This flag indicates the use of the address fields in the header. */
#define MULTIBOOT_AUOT_KLUDGE   0x00010000

/*Flags to be set in the 'fags' member of the multiboot info structure */
/*Is there basic lower/upper memory information?*/
#define MULTIBOOT_INFO_MEMORY   0x0000001

/*is there a boot device set?*/
#define MULTIBOOT_INFO_BOOTDEV 0x0000002


/*is the command0line defined?*/
#define MULTIBOOT_INFO_CMDLINE 0x0000004

/*are there modules to do something with? */
#define MULTIBOOT_INFO_MODS 0x0000008

/* These next two are mutually exclusice*/

/*is there a symbol table loaded?*/
#define MULTIBOOT_INFO_AOUT_SYMS 0x00000010

/*is there a ELF section header table? */
#define MULTIBOOT_INFO_ELF_SHDR 0x00000020

/**is there a full memory map?*/
#define 



#define 
