/* Letterbox Fade In: complete 006d7890..006d78c9.
 * State byte, zero float and signed deadline wrap are all retained.
 * Native SUB at 006D78BE = compound -= on the global (a local temporary
 * compiles to ADD of the negated constant). */
#include "../cutscene_types.h"
extern unsigned char DAT_0140c85a;
extern float DAT_01f76904;
extern int DAT_00e843ac,DAT_00eac468;
__declspec(noinline) void __cdecl FUN_006d7890(const CsEffectBoolOption *option)
{
    if (option->value==1) {
        DAT_0140c85a=1;
        DAT_01f76904=0.0f;
        DAT_00eac468=DAT_00e843ac+1000;
        if (DAT_00eac468>1800000000)
            DAT_00eac468-=1800000000;
    }
}
