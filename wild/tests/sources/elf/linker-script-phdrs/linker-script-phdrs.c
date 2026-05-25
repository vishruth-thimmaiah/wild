//#Mode:dynamic
//#RunEnabled:false
//#CompArgs:-fPIE -fPIC
//#LinkArgs:-shared -z now -T ./linker-script-phdrs.ld
//#DiffIgnore:section.got
//#DiffIgnore:section.riscv.attributes
//#DiffIgnore:segment.RISCV_ATTRIBUTES.*
// GNU ld emits `.riscv.attributes`, but Wild does not
//#DiffIgnore:riscv_attributes.*

const char message[] = "Hello PHDRS";

int foo(void) { return 42; }

const char* bar() { return &message[0]; }
