ENTRY(_start)
abs_offset = 0x20;

SECTIONS {
    .text 0x10000 : {
        sec_start = .;
        in_sec_add = sec_start + 0x10;
        in_sec_sub = (sec_start + 0x20) - 0x10;
        in_sec_mul = (sec_start + 0x10) * 2;
        sec_end = sec_start + 0x100;
        *(.text*)
    }
}

out_add = sec_start + 0x1000;
out_add_rev = 0x1000 + sec_start;
out_sub = sec_start - 0x1000;

out_sub_rev = 0x30000 - sec_start;

out_mul = sec_start * 2;
out_div = sec_start / 2;
out_shift = sec_start >> 1;

out_diff = sec_end - sec_start;

out_rel_plus_abs = sec_start + abs_offset;
