/* Complete CSEffect handler: City No Render AL.
 * Dispatch proof: table record 00dd28dc stores function pointer 006d7660.
 * Body evidence: native option byte +8 -> DAT_02526cc5. */
#include "../cutscene_types.h"
extern unsigned char DAT_02526cc5;
__declspec(noinline) void __cdecl FUN_006d7660(const CsEffectBoolOption *option)
{
    DAT_02526cc5=option->value;
}
