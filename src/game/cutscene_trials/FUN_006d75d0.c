/* Complete CSEffect handler: TOD character shadows.
 * Dispatch proof: table record 00dd2ae0 stores function pointer 006d75d0.
 * Body evidence: native option byte +8 -> DAT_00e97d4e. */
#include "../cutscene_types.h"
extern unsigned char DAT_00e97d4e;
__declspec(noinline) void __cdecl FUN_006d75d0(const CsEffectBoolOption *option)
{
    DAT_00e97d4e=option->value;
}
