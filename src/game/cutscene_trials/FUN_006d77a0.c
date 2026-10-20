/* Shot Fade Out effect: complete 006d77a0..006d77d4.
 * A strictly positive option writes both float fields, retaining two reads. */
#include "../cutscene_types.h"
extern CsCurrentShotInstanceView *DAT_02527d10;
__declspec(noinline) void __cdecl FUN_006d77a0(const CsEffectFloatOption *option)
{
    if (option->value>0.0f) {
        CsCurrentShotInstanceView *instance=DAT_02527d10;
        instance->current_shot->field_164=option->value;
        instance->current_shot->field_168=option->value;
    }
}
