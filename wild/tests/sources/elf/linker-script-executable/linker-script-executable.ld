ENTRY(begin_here)

SECTIONS
{
    . = 0x300000 * 2;
    start_of_sections = .;
    .text : {
        *(.text)
    }
    . = 0x800000;
    . = ALIGN(4);
    .data : {
        start_of_data = .;
        *(.data)
        . = ALIGN(512);
        start_of_512 = .;
        *(.data.2)
    }
    .got : { *(.got) }
    .bss : { *(.bss) }

    .comment 0 : { *(.comment) }
    .strtab 0 : { *(.strtab) }
    .symtab 0 : { *(.symtab) }
    .shstrtab 0 : { *(.shstrtab) }
}
