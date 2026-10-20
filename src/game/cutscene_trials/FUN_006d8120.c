/* Complete CSEffect handler: Glares.
 * Dispatch proof: table record 00dd2978 stores function pointer 006d8120.
 * Body evidence: native option byte +8 -> DAT_00e97d56. */
#include "../cutscene_types.h"
extern unsigned char DAT_00e97d56;
__declspec(noinline) void __cdecl FUN_006d8120(const CsEffectBoolOption *option)
{
    DAT_00e97d56=option->value!=0;
}
