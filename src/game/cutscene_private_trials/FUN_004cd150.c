#include "../cutscene_types.h"
/* Whole 004cd150..004cd191. Native exponent ECX, base on stack, ST0 result.
 * Preserve the do-once loop, unsigned magnitude shift and float rounding.
 * Used by 00b74260's scientific-notation path with base 10.0f. */
__declspec(noinline) float __cdecl FUN_004cd150(int exponent, float base)
{
    unsigned int magnitude=(unsigned int)exponent;
    float result;
    if (exponent<0) magnitude=0-magnitude;
    result=1.0f;
    for (;;) {
        if ((magnitude&1)!=0) result=result*base;
        magnitude>>=1;
        if (magnitude==0) break;
        base=base*base;
    }
    result=exponent<0?1.0f/result:result;
    return result;
}
static int volatile exponent_input;
static float volatile base_input,result;
void comparison_entry(void) { result=FUN_004cd150(exponent_input,base_input); }
