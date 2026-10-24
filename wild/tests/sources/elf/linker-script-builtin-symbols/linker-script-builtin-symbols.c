//#AbstractConfig:default
//#Object:runtime.c
//#ReferenceLinkers:lld

//#Config:no_sections:default
//#LinkerScript:builtin-symbols-no-sections.ld
//#ExpectSym:start_symbol
//#ExpectSym:_etext

//#Config:sections:default
//#LinkerScript:builtin-symbols.ld
//#ExpectError:(?i-u)symbol( not found:)? '?_etext'?
//#ExpectErrorWild:Symbol '_etext' referenced by linker script does not exist

#include "../common/runtime.h"

void _start() {
  runtime_init();
  exit_syscall(42);
}
