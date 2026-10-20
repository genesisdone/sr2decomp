/* Complete CSEffect handler: Disable Trees.
 * Dispatch proof: table record 00dd2924 stores function pointer 006d7640.
 * Body evidence: native option byte +8 -> DAT_00e878bb. */
#include "../cutscene_types.h"
extern unsigned char DAT_00e878bb;
__declspec(noinline) void __cdecl FUN_006d7640(const CsEffectBoolOption *option)
{
    DAT_00e878bb=option->value==0;
}
