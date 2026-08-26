//#AbstractConfig:default
//#LinkerScript:linker-script-orphan-handling.ld
//#Object:runtime.c
// RISC-V: BFD complains about missing __global_pointer$ (defined in the default linker script)
//#SkipArch:riscv64
//#ReferenceLinkers:bfd
//#DiffIgnore:segment.LOAD.RX.alignment
//#DiffIgnore:segment.LOAD.RW.alignment
//#DiffIgnore:segment.LOAD.RWX.alignment

//#Config:orphan-place:default
//#LinkArgs:--orphan-handling=place
//#Contains:.orphan_section

//#Config:orphan-warn:default
//#LinkArgs:--orphan-handling=warn
//#ExpectWarning:unplaced orphan section .\.orphan_section' from .*linker-script-orphan-handling\.c\.o'

//#Config:orphan-error:default
//#LinkArgs:--orphan-handling=error
//#ExpectError:unplaced orphan section .\.orphan_section' from .*linker-script-orphan-handling\.c\.o'

//#Config:orphan-discard:default
//#LinkArgs:--orphan-handling=discard
//#DoesNotContain:.orphan_section

#include "../common/runtime.h"

__attribute__((section(".orphan_section"), retain, used)) int orphan_var = 42;

void _start(void) { exit_syscall(42); }
