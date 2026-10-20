/* Complete CSEffect handler: City Render Fade Dist Scale.
 * Dispatch proof: record 00dd28f4 -> 006d81f0; native FLD option+8, FSTP DAT_00e996b4. */
#include "../cutscene_types.h"
extern float DAT_00e996b4;
__declspec(noinline) void __cdecl FUN_006d81f0(const CsEffectFloatOption *option)
{
    DAT_00e996b4=option->value;
}
