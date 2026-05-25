//#Mode:dynamic
//#RunEnabled:false
//#EnableLinker:lld
//#LinkArgs:-shared -z now -T ./linker-script-discard.ld
//#DiffIgnore:section.got
//#DiffIgnore:section.riscv.attributes
//#DiffIgnore:segment.RISCV_ATTRIBUTES.*
// GNU ld emits `.riscv.attributes`, but Wild does not
//#DiffIgnore:riscv_attributes.*
//#DiffIgnore:segment.LOAD.RX.alignment
//#DiffIgnore:segment.LOAD.RWX.alignment
//#DoesNotContain:/DISCARD/
//#DoesNotContain:.text
//#NoSym:foo

static int foo() { return 0; }
