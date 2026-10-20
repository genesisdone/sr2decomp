#include "../cutscene_types.h"
/* Whole 006d7510..006d7547. The false branch ends in a native E9 tail
 * transfer to no-argument FUN_00b7da30; its four-byte operand is audited. */
extern unsigned char DAT_0215da25,DAT_0215da05,DAT_02529620;
extern void __cdecl FUN_00b7da30(void);
__declspec(noinline) void __cdecl FUN_006d7510(const CsEffectBoolOption *option)
{
    if (option->value==1) {
        DAT_0215da25=0;
        DAT_0215da05=0;
        FUN_00b7da30();
        DAT_02529620=1;
        return;
    }
    DAT_0215da25=1;
    DAT_0215da05=1;
    FUN_00b7da30();
}
