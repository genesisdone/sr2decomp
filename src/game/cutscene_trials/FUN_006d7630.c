/* Complete CSEffect handler: Camera moves with target.
 * Dispatch proof: table record 00dd28b8 stores function pointer 006d7630.
 * Body evidence: native option byte +8 -> DAT_025f5d90. */
#include "../cutscene_types.h"
extern unsigned char DAT_025f5d90;
__declspec(noinline) void __cdecl FUN_006d7630(const CsEffectBoolOption *option)
{
    DAT_025f5d90=option->value;
}
