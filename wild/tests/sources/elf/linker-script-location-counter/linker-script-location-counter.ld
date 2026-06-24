ENTRY(begin_here)

SECTIONS
{
    . = 0x300000 * 2;
	start_of_sections = .;
    .text : {
        . = 0x10;
        *(.text)
        . = 0x1000;
    }
    . = 0x800000;
	start_of_data = .;
    .data : {
        *(.data)
    }
}

ASSERT(start_of_sections == 0x600000, "start_of_sections should be 0x600000");
ASSERT(start_of_data == 0x800000, "start_of_data should be 0x800000");
ASSERT(SIZEOF(.text) == 0x1000, "text section should be 0x1000 bytes");
