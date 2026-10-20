/* Credits Roll: native 006d82d0..006d82ea. Add option time to the global
 * cutscene clock and store instance+0xb08. */
#include "../cutscene_types.h"
typedef struct CsCreditsTimeView {
    unsigned char unknown_000[0xb08];
    float field_b08;
} CsCreditsTimeView;
extern CsCreditsTimeView *DAT_02527d10;
extern float DAT_027e66fc;
__declspec(noinline) void __cdecl FUN_006d82d0(const CsEffectFloatOption *option)
{
    DAT_02527d10->field_b08=option->value+DAT_027e66fc;
}
