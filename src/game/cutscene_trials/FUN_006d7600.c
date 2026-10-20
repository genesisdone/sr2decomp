/* Volatile qualifiers in this recovery preserve the observed memory-access
 * order. They do not establish the original source declarations. */
/* Motion Blur Override: native 006d7600..006d7624. Three word copies,
 * not float conversions; payload+8 points to the source triple. */
#include "../cutscene_types.h"
typedef struct CsMotionBlurOverrideView {
    unsigned char unknown_0000[0x15e4];
    CsWords3 field_15e4;
} CsMotionBlurOverrideView;
extern CsMotionBlurOverrideView *volatile DAT_02527d10;
__declspec(noinline) CsWord __cdecl FUN_006d7600(const CsEffectVectorOption *option)
{
    const volatile CsWords3 *value=option->value;
    CsWord first=value->x;
    CsWord last;
    CsWords3 *out=&DAT_02527d10->field_15e4;
    out->x=first;
    out->y=value->y;
    last=value->z;
    out->z=last;
    return last; /* Native last word is loaded into EAX at 006D761D. */
}
