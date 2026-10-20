/* Shot Cut Out Midway: full 006d7840..006d7890.
 * Same rounded clock arithmetic, but second stored float is zero. */
#include "../cutscene_types.h"
extern CsCurrentShotInstanceView *DAT_02527d10;
extern float DAT_027e6714,DAT_027e6710;
__declspec(noinline) void __cdecl FUN_006d7840(const CsEffectFloatOption *option)
{
    if (option->value>0.0f) {
        CsCurrentShotInstanceView *instance=DAT_02527d10;
        float remaining=DAT_027e6714-DAT_027e6710;
        remaining=remaining-option->value;
        instance->current_shot->field_164=remaining;
        instance->current_shot->field_168=0.0f;
    }
}
