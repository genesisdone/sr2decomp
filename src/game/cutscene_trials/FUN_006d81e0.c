/* Complete CSEffect handler: City Region Blend.
 * Dispatch proof: table record 00dd28e8 stores function pointer 006d81e0.
 * Body evidence: native option byte +8 -> DAT_00e996e6. */
#include "../cutscene_types.h"
extern unsigned char DAT_00e996e6;
__declspec(noinline) void __cdecl FUN_006d81e0(const CsEffectBoolOption *option)
{
    DAT_00e996e6=option->value;
}
