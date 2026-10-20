/* Motion Blur: native 006d75e0..006d75f8. Negated option -> instance +15e0. */
#include "../cutscene_types.h"
typedef struct CsMotionBlurView {
    unsigned char unknown_0000[0x15e0];
    unsigned char field_15e0;
} CsMotionBlurView;
extern CsMotionBlurView *DAT_02527d10;
__declspec(noinline) void __cdecl FUN_006d75e0(const CsEffectBoolOption *option)
{
    DAT_02527d10->field_15e0=(option->value==0);
}
