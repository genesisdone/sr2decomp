/* Volatile qualifiers in this recovery preserve the observed memory-access
 * order. They do not establish the original source declarations. */
/* Drug Effect: native 006d8200..006d8222. Preserve the second payload
 * pointer reload after the first float store; the original permits aliasing. */
#include "../cutscene_types.h"
typedef struct CsDrugEffectView {
    unsigned char unknown_0000[0x15d8];
    volatile float field_15d8,field_15dc;
} CsDrugEffectView;
extern CsDrugEffectView *DAT_02527d10;
typedef struct CsDrugOption { CsWord unknown_00,unknown_04; const float *volatile value; } CsDrugOption;
__declspec(noinline) const CsDrugOption * __cdecl FUN_006d8200(const CsDrugOption *option)
{
    double first=option->value[0];
    CsDrugEffectView *instance=DAT_02527d10;
    instance->field_15d8=(float)first;
    instance->field_15dc=option->value[1];
    return option; /* Native EAX retains the argument across both stores. */
}
