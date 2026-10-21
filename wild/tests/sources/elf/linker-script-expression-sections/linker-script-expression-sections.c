//#AbstractConfig:base
//#RunEnabled:false
//#DiffEnabled:false
//#ReferenceLinkers:bfd
//#SkipArch:riscv64

//#Config:addr-alias:base
//#ReferenceLinkers:bfd,lld
//#LinkArgs:-T ./addr-alias.ld
//#ExpectSym:after_addr section=".text",address=0x10010
//#ExpectSym:section_addr section=".text",address=0x10000

//#Config:min-max-number:base
//#LinkArgs:-T ./min-max-number.ld
//#ExpectSym:min_right section=".text",address=0x10000
//#ExpectSym:min_left section=".text",address=0x10000
//#ExpectSym:max_right section=".text",address=0x10010
//#ExpectSym:max_left section=".text",address=0x10010

//#Config:min-max-location:base
//#LinkArgs:-T ./min-max-location.ld
//#ExpectSym:padded_end section=".text",address=0x10100

//#Config:absolute-arithmetic:base
//#ReferenceLinkers:bfd,lld
//#LinkArgs:-T ./absolute-arithmetic.ld
//#ExpectSym:product is_abs=true,address=0x20000
//#ExpectSym:quotient is_abs=true,address=0x8000
//#ExpectSym:shifted is_abs=true,address=0x8000
//#ExpectSym:reverse_difference is_abs=true,address=0x10000

//#Config:relative-plus-absolute:base
//#LinkArgs:-T ./relative-plus-absolute.ld
//#ExpectSym:absolute_offset is_abs=true,address=0x10
//#ExpectSym:derived is_abs=true,address=0x10010
//#ExpectSym:derived_reverse is_abs=true,address=0x10010

//#Config:expression-arith:base
//#LinkArgs:-T ./expression-arith.ld
//#ExpectSym:in_sec_add section=".text",address=0x10010
//#ExpectSym:in_sec_sub section=".text",address=0x10010
//#ExpectSym:in_sec_mul section=".text",address=0x10020
//#ExpectSym:in_sec_add_rev section=".text"
//#ExpectSym:in_sec_sub_rev section=".text"
//#ExpectSym:in_sec_loadaddr_sub is_abs=true,address=0xf000
//#ExpectSym:in_sec_loadaddr_mul is_abs=true,address=0x20000
//#ExpectSym:in_sec_loadaddr_and is_abs=true,address=0x0
//#ExpectSym:out_add is_abs=true,address=0x11000
//#ExpectSym:out_sub is_abs=true,address=0xf000
//#ExpectSym:out_sub_rev is_abs=true,address=0x20000
//#ExpectSym:out_mul is_abs=true,address=0x20000
//#ExpectSym:out_div is_abs=true,address=0x8000
//#ExpectSym:out_shift is_abs=true,address=0x8000
//#ExpectSym:out_diff is_abs=true,address=0x100
//#ExpectSym:out_rel_plus_abs is_abs=true,address=0x10020
//#ExpectSym:out_loadaddr_and is_abs=true,address=0x0

void _start(void) {}
