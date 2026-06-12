MEMORY {
    region1 : ORIGIN = 0x10000000, LENGTH = 0x100000
    region2 : ORIGIN = 0x20000000, LENGTH = 0x100000
}

SECTIONS {
    .data.ram1 : {
        KEEP(*(.data.ram1))
    } > region1

    .data.ram2 : {
        KEEP(*(.data.ram2))
    } > region1

    .data.rom : {
        KEEP(*(.data.rom))
    } > region2

	.data.ram3 : {
		KEEP(*(.data.ram3))
	} > region1

	.note.gnu.property : {
		*(.note.gnu.property)
	} > region2

	.text : {
		*(.text)
	} > region2

	.relro_padding : {
		*(.relro_padding)
	} > region2
}

ASSERT(ORIGIN(RAM) + LENGTH(RAM) == 0x10100000, "RAM region overflowed")
ASSERT(ORIGIN(ROM) + LENGTH(ROM) == 0x20100000, "ROM region overflowed")
