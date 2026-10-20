/* Complete CSEffect handler: Near Clip (DANGER).
 * Dispatch proof: record 00dd2a50 -> 006d7740; native FLD option+8, FSTP DAT_00e9898c. */
#include "../cutscene_types.h"
extern float DAT_00e9898c;
__declspec(noinline) void __cdecl FUN_006d7740(const CsEffectFloatOption *option)
{
    DAT_00e9898c=option->value;
}
