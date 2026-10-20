/* credits_in_cutscene script query: complete 00751860..007518a4.
 * Result record +0=1, +8=canonicalized byte, then context+8 advances 16.
 * Other result words retain their existing values. */
#include "../cutscene_types.h"
extern unsigned char DAT_02527d14,DAT_02527cf7,DAT_02527d15;
__declspec(noinline) int __cdecl FUN_00751860(CsScriptContextView *context)
{
    unsigned char value;
    CsScriptResultView *result;
    if (((DAT_02527d14==0 || DAT_02527cf7==0) && DAT_02527d15==0))
        value=0;
    else
        value=1;
    result=context->top;
    result->field_00=1;
    result->field_08=(value!=0);
    ++context->top;
    return 1;
}
