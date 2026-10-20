#include "../cutscene_types.h"
/* Whole Shot Fade In shot option handler (option table 0x00DD28A0): for an ordered positive time, starts
 * a fade of time*E5C0D8 ms to target 0 and marks instance +B03 unless +B02 is set. FUN_004d1270 is a /GL
 * context stand-in; the interface LTCG chooses for it is NOT claimed as the native ABI (native: flag DL,
 * duration and target on the stack, caller pops 8). */
typedef struct CsFadeRootTrial { unsigned char unknown_00[0xb02]; unsigned char field_b02,field_b03; } CsFadeRootTrial;
extern CsFadeRootTrial *DAT_02527d10;
extern double DAT_00e5c0d8;
int FUN_004d1270(unsigned char flag,int duration,float target);
__declspec(noinline) void __cdecl FUN_006d7750(const CsEffectFloatOption *option)
{
    if (option->value>0.0f) {
        CsFadeRootTrial *instance;
        int duration=(int)(option->value*DAT_00e5c0d8);
        FUN_004d1270(0,duration,0.0f);
        instance=DAT_02527d10;
        if (instance->field_b02==0) instance->field_b03=1;
    }
}
