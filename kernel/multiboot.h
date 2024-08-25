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
#define MULTIBOOT_INFO_MEM_MAP 0x00000040

/*Is there drive info*/
#define MULTIBOOT_INFO_DRIVE_INFO 0x00000080

/*is there a config table */
#define MULTIBOOT_INFO_CONFIG_TABLE 0x00000100

/*is there a boot loader naem? */
#define MULTIBOOT_INFO_BOOT_LOADER_NAME 0x00000200

/*Is there a APM table*/
#define MULTIBOOT_INFO_APM_TABLE 0x00000400

/*Is there video information*/
#define MULTIBOOT_INFO_VBE_INFO 0x00000800
#define MULTIBOOT_INFO_FRAMEBUFFER_INFO 0x00001000

#ifndef ASM_FILE

typedef unsigned char multiboot_uint8_t;
typedef unsigned short multiboot_uint16_t;
typedef unsigned int multiboot_uint32_t;
typedef unsigned long long multiboot_uint64_t;

struct multiboot_header
{
	/*Must be MUTLBOOT_MAGIC - see above*/
	multiboot_uint32_t magic;

	/*Feature flags*/
	multiboot_uint32_t flags;

	/*the above fields plus this one must equal 0 mod 2^32*/
	multiboot_uint32_t checksum;


	/*These are only valid if MULTIBOOT_AOUT_LUDGE is set*/
	multiboot_uint32_t header_addr;
	multiboot_uint32_t load_addr;
	multiboot_uint32_t load_end_addr;
	multiboot_uint32_t bss_end_addr;
	multiboot_uint32_t entry_addr;

	multiboot_uint32_t mode_type;
	multiboot_uint32_t width;
	multiboot_uint32_t height;
	multiboot_uint32_t depth;

}


struct multiboot_aout_symbol_table
{
	multiboot_uint32_t tabsize;
	multiboot_uint32_t strsize;
	multiboot_uint32_t addr;
	multiboot_uint32_t reserved;
}
typedef struct multiboot_aout_symbol_table multiboot_aout_symbol_table_t;

struct multiboot_elf_section_header_table
{
	multiboot_uint43_t num;
	multiboot_uint43_t size;
	multiboot_uint43_t addr;
	multiboot_uint43_t shndx;
}
typedef struct multiboot_elf_section_header_table multiboot_elf_section_header_table_t;

struct multiboot_info
{
	multiboot_uint32_t flags;

	multiboot_uint32_t mem_lower;
	multiboot_uint32_t mem_upper;

	multiboot_uint32_t boot_device;

	multiboot_uint32_t cmdline;
	multiboot_uint32_t mods_count;
	multiboot_uint32_t mods_addr;

	union{
		multiboot_auot_symbol_table_t aout_sym;
		multiboot_elf_section_header_table_t elf_sec;

	}u;

	multiboot_uint32_t mmap_length;
	multiboot_uint32_t mmap_addr;
	multiboot_uint32_t drives_length;
	multiboot_uint32_t drives_addr;
	multiboot_uint32_t config_table;
	multiboot_uint32_t boot_loader_name;
	multiboot_uint32_t apm_table;

	
	/* Video */
	multiboot_uint32_t vbe_control_info;
	multiboot_uint32_t vbe_mode_info;
	multiboot_uint16_t vbe_mode;
	multiboot_uint16_t vbe_interface_seg;
	multiboot_uint16_t vbe_interface_off;
	multiboot_uint16_t vbe_interface_len;

	multiboot_uint64_t framebuffer_addr;
	multiboot_uint32_t framebuffer_pitch;
	multiboot_uint32_t framebuffer_width;
	multiboot_uint32_t framebuffer_height;
	multiboot_uint8_t framebuffer_bpp;

#define MULTIBOOT_FRAMEBUFFER_TYPE_INDEXED 0 /*index color mode*/	
#define MULTIBOOT_FRAMEBUFFER_TYPE_RGB     1 /*rgb mode, pixel represents combination red green blue*/
#define MULTIBOOT_FRAMEBUFFER_TYPE_EGA_TEXT	2  /*enhance graphic adapter, only show text*/
	multiboot_uint8_t framebuffer_type;
	union
	{
		struct
		{
			multiboot_uint32_t framebuffer_palette_addr;
			multiboot_uint16_t framebuffer_palette_num_colors;
		};
		struct
		{
			multiboot_uint8_t framebuffer_red_field_position;
			multiboot_uint8_t framebuffer_red_mask_size;
			multiboot_uint8_t framebuffer_green_field_position;
			multiboot_uint8_t framebuffer_green_mask_size;
			multiboot_uint8_t framebuffer_blue_field_position;
			multiboot_uint8_t framebuffer_blue_mask_size;
		};
	};
};

typedef struct multiboot_info multiboot_info_t;

struct multiboot_color
{
	multiboot_uint8_t red;
	multiboot_uint8_t green;
	multiboot_uint8_t blue;
};

struct multiboot_mmap_entry
{
	multiboot_uint32_t size;
	multiboot_uint32_t addr_low;
	multiboot_uint32_t addr_high;
	multiboot_uint32_t len_low;
	multiboot_uint32_t len_high;
#define MULTIBOOT_MEMORY_AVAILABLE		1
#define MULTIBOOT_MEMORY_RESERVED		2
#define MULTIBOOT_MEMORY_ACPI_RECLAIMABLE       3
#define MULTIBOOT_MEMORY_NVS                    4
#define MULTIBOOT_MEMORY_BADRAM                 5
	multiboot_uint32_t type;
} __attribute__((packed));
typedef struct multiboot_mmap_entry multiboot_memory_map_t;

struct multiboot_mod_list
{
	/* the memory used goes from bytes 'mod_start' to 'mod_end-1' inclusive */
	multiboot_uint32_t mod_start;
	multiboot_uint32_t mod_end;

	/* Module command line */
	multiboot_uint32_t cmdline;

	/* padding to take it to 16 bytes (must be zero) */
	multiboot_uint32_t pad;
};
typedef struct multiboot_mod_list multiboot_module_t;

/* APM BIOS info.  */
struct multiboot_apm_info
{
	multiboot_uint16_t version;
	multiboot_uint16_t cseg;
	multiboot_uint32_t offset;
	multiboot_uint16_t cseg_16;
	multiboot_uint16_t dseg;
	multiboot_uint16_t flags;
	multiboot_uint16_t cseg_len;
	multiboot_uint16_t cseg_16_len;
	multiboot_uint16_t dseg_len;
};

#endif /* ! ASM_FILE */

#endif /* ! MULTIBOOT_HEADER */

	
}



