/* Lightning effect: complete 006d7d70..006d7da6.
 * Native signed time threshold is 1800000000; do not replace it with a
 * modulo period or clamp. Input byte zero stores the -1 sentinel.
 * The native SUB at 006D7D90 comes from a compound -= on the global
 * (a local temporary compiles to ADD of the negated constant). */
#include "../cutscene_types.h"
extern int DAT_00e843ac,DAT_00e9a848;
__declspec(noinline) void __cdecl FUN_006d7d70(const CsEffectBoolOption *option)
{
    if (option->value!=0) {
        DAT_00e9a848=DAT_00e843ac+5000;
        if (DAT_00e9a848>1800000000)
            DAT_00e9a848-=1800000000;
    } else {
        DAT_00e9a848=-1;
    }
}
