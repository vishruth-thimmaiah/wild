//#RunEnabled:false
//#LinkArgs:-shared -T ./linker-script-region.ld
//#EnableLinker: lld
//#DiffIgnore:.dynamic.DT_FLAGS_1.NOW
//#DiffIgnore:.dynamic.DT_RELA*
//#DiffIgnore:section.got
//#ExpectProgramHeader:LOAD flags=RW,sections=[.data.ram1,.data.ram2,*]
//#ExpectProgramHeader:LOAD flags=RW,sections=[.data.ram3,*]
//#ExpectProgramHeader:LOAD sections=[.data.rom,*]
//#ExpectSym:var1 address=0x10000000
//#ExpectSym:var3 address=0x10000004
//#ExpectSym:var4 address=0x10000010

static int var1 __attribute__((used, section(".data.ram1"))) = 0x01;
static int var2 __attribute__((used, section(".data.rom"))) = 0x02;
static int var3 __attribute__((used, section(".data.ram2"))) = 0x03;
static int var4 __attribute__((used, section(".data.ram3"))) = 0x04;

void _start(void) {}
