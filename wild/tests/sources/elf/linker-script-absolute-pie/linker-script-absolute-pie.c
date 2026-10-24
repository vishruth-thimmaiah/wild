//#AbstractConfig:base
//#Arch:x86_64
//#ReferenceLinkers:bfd,lld
//#Object:runtime.c
//#DiffEnabled:false
//#ExpectSym:absolute_value is_abs=true,address=0x1234
//#DiffIgnore:segment.INTERP.alignment

//#Config:pie:base
//#Mode:dynamic
//#CompArgs:-fPIE
//#LinkArgs:-pie
//#LinkerScript:linker-script-absolute-pie.ld

//#Config:no-pie:base
//#CompArgs:-fno-pie
//#LinkArgs:-no-pie
//#LinkerScript:linker-script-absolute-no-pie.ld

#include <stdint.h>

#include "../common/runtime.h"

extern char absolute_value;
char* volatile stored_pointer = &absolute_value;

void _start(void) {
  runtime_init();
  if ((uintptr_t)stored_pointer != 0x1234) {
    exit_syscall(1);
  }
  exit_syscall(42);
}
