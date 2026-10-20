/* Letterbox Fade Out effect: complete 006d78d0..006d78ee.
 * Only option byte exactly 1 sets current shot +16c; no null guards exist. */
#include "../cutscene_types.h"
extern CsCurrentShotInstanceView *DAT_02527d10;
__declspec(noinline) void __cdecl FUN_006d78d0(const CsEffectBoolOption *option)
{
    if (option->value==1)
        DAT_02527d10->current_shot->field_16c=1;
}
