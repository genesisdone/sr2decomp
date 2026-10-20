#include "../cutscene_types.h"
/* Whole logical string fade command. 006CC421 rounds atof to FLOAT before
 * multiplying by DOUBLE E5C0D8; negative and NaN inputs are not clamped.
 * FUN_004d1270 is a /GL context stand-in; the interface LTCG chooses for it is
 * NOT claimed as the native ABI (native: flag DL, duration/target on the stack).
 */
typedef struct CsFadeStringCommandTrial { unsigned char unknown_00[0x10]; const char *time; } CsFadeStringCommandTrial;
typedef struct CsFadeRootTrial { unsigned char unknown_00[0xb02]; unsigned char field_b02,field_b03; } CsFadeRootTrial;
extern double __cdecl FUN_00c984f5(const char *text);
extern double DAT_00e5c0d8;
extern CsFadeRootTrial *DAT_02527d10;
int FUN_004d1270(unsigned char flag,int duration,float target); /* native flag DL, duration and target on the stack, caller pops 8 */
__declspec(noinline) void __cdecl FUN_006cc410(const CsFadeStringCommandTrial *option)
{
    if (option->time!=0) {
        float time=(float)FUN_00c984f5(option->time);
        int duration=(int)(time*DAT_00e5c0d8);
        CsFadeRootTrial *instance;
        FUN_004d1270(0,duration,0.0f);
        instance=DAT_02527d10;
        if (instance->field_b02==0) instance->field_b03=1;
    }
}
