/* Complete CSEffect handler: City Shadow Dist.
 * Dispatch proof: record 00dd2900 -> 006d76b0; native FLD option+8, FSTP DAT_00e849a0. */
#include "../cutscene_types.h"
extern float DAT_00e849a0;
__declspec(noinline) void __cdecl FUN_006d76b0(const CsEffectFloatOption *option)
{
    DAT_00e849a0=option->value;
}
