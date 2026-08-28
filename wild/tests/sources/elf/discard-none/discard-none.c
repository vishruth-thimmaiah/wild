//#Object:runtime.c
//#CompArgs: -Wa,-L
//#ReferenceLinkers:bfd,lld
//#LinkArgs:--discard-none
//#ExpectSym:.Ltmp0 section=".text"
//#NoSym:unused

#include "../common/runtime.h"

asm(".Ltmp0:");

static int unused = 4;

void _start(void) {
  runtime_init();
  exit_syscall(42);
}
