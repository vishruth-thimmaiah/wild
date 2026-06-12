//#RunEnabled:false
//#LinkArgs:-shared -T ./linker-script-region.ld
//#EnableLinker: lld

static int var1 __attribute__((used, section(".data.ram1"))) = 0x01;
static int var2 __attribute__((used, section(".data.rom"))) = 0x02;
static int var3 __attribute__((used, section(".data.ram2"))) = 0x03;
static int var4 __attribute__((used, section(".data.ram3"))) = 0x04;

void _start(void) {}
