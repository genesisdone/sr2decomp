/* Rain Override: whole 006d8240..006d827a. Preserve float local rounding.
 * Ordinary C comparison is a trial; only complete byte matching certifies it. */
#include "../cutscene_types.h"
extern unsigned char DAT_02526d78;
extern float DAT_02526d7c;
__declspec(noinline) void __cdecl FUN_006d8240(const CsEffectFloatOption *option)
{
    float value=option->value;
    if (value>=0.0f) {
        DAT_02526d78=1;
        DAT_02526d7c=value;
    } else {
        DAT_02526d78=0;
        DAT_02526d7c=0.0f;
    }
}
