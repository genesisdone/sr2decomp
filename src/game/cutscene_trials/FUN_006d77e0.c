/* Shot Fade Out Midway: full 006d77e0..006d7833.
 * Keep the rounded clock difference, rounded subtraction and both stores. */
#include "../cutscene_types.h"
extern CsCurrentShotInstanceView *DAT_02527d10;
extern float DAT_027e6714,DAT_027e6710,DAT_00dd1c8c;
__declspec(noinline) void __cdecl FUN_006d77e0(const CsEffectFloatOption *option)
{
    if (option->value>0.0f) {
        CsCurrentShotInstanceView *instance=DAT_02527d10;
        float remaining=DAT_027e6714-DAT_027e6710;
        remaining=remaining-option->value;
        instance->current_shot->field_164=remaining;
        instance->current_shot->field_168=DAT_00dd1c8c;
    }
}
