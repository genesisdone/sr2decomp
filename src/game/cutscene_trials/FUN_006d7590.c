/* Complete CSEffect handler: Level Lights.
 * Dispatch proof: table record 00dd29cc stores function pointer 006d7590.
 * Body evidence: native option byte +8 -> DAT_025295c9. */
#include "../cutscene_types.h"
extern unsigned char DAT_025295c9;
__declspec(noinline) void __cdecl FUN_006d7590(const CsEffectBoolOption *option)
{
    DAT_025295c9=option->value==0;
}
