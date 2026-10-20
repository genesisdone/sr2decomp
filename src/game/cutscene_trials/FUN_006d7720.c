/* Far Clip: native 006d7720..006d773a. Positive float option only.
 * NaN/x87 behavior is uncertified until whole-function byte equality. */
#include "../cutscene_types.h"
extern float DAT_00e98988;
__declspec(noinline) void __cdecl FUN_006d7720(const CsEffectFloatOption *option)
{
    if (option->value>0.0f)
        DAT_00e98988=option->value;
}
