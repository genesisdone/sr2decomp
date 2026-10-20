/* Tree Shadows: DD28A0 table points here. Native 006d75b0..006d75c5.
 * The output is 1 or 2, not a direct byte flag. */
#include "../cutscene_types.h"
extern int DAT_00e98994;
__declspec(noinline) void __cdecl FUN_006d75b0(const CsEffectBoolOption *option)
{
    DAT_00e98994=(option->value!=0)+1;
}
