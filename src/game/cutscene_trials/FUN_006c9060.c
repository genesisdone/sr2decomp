#include "../cutscene_types.h"
/* Whole 006C9060..006C908D. Install the native callback address when an
 * instance exists; otherwise perform the same hand-back immediately.
 * 006B5810 has no incoming register/stack input; 007D6B70 uses two cdecl
 * stack inputs (entry +4 flag, +8 location). No helper body is recovered here.
 */
typedef struct CsHandBackInstance {
    unsigned char unknown_00[0x160c];
    void (__cdecl *callback)(void);
} CsHandBackInstance;
extern CsHandBackInstance *DAT_02527d10;
extern unsigned char DAT_02528989;
extern void __cdecl FUN_0068dc50(void);
extern void __cdecl FUN_006b5810(void);
extern void __cdecl FUN_007d6b70(unsigned char flag,void *location);
__declspec(noinline) void __cdecl FUN_006c9060(void)
{
    if (DAT_02527d10) {
        DAT_02527d10->callback=FUN_0068dc50;
        return;
    }
    FUN_006b5810();
    FUN_007d6b70(1,0);
    DAT_02528989=0;
}
