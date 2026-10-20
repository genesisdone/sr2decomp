/* Complete canonical REA initializer and literal 40-byte copy. */
#include <string.h>
extern void __fastcall FUN_00956080(void *object);
__declspec(noinline) void __fastcall FUN_00784560(unsigned char *object) {
    FUN_00956080(object);
    memcpy(object+0x2c,object+0x208,40);
    object[0x204]=0;
    object[0x54]=1;
    *(unsigned int *)(object+0x200)=0;
}
