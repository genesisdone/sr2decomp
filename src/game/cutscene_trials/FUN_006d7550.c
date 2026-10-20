#include "../cutscene_types.h"
/* Whole 006d7550..006d758f. Flag meanings beyond these accesses unknown. */
extern unsigned char DAT_0215da1d,DAT_0215d9fd,DAT_02529620;
extern void __cdecl FUN_0093c660(void);
extern void __cdecl FUN_00b81130(void);
__declspec(noinline) void __cdecl FUN_006d7550(const CsEffectBoolOption *option)
{
    if (option->value==1) {
        DAT_0215da1d=0;
        FUN_0093c660();
        DAT_0215d9fd=0;
        FUN_00b81130();
        DAT_02529620=1;
        return;
    }
    DAT_0215d9fd=1;
    FUN_00b81130();
    DAT_02529620=1;
}
