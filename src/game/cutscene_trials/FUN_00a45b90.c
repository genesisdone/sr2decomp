/* should_skip_intro_cutscene script query: complete 00a45b90..00a45bcb.
 * Both flags and the script-result append are retained. */
#include "../cutscene_types.h"
extern unsigned char DAT_02527d24,DAT_02527c0f;
__declspec(noinline) int __cdecl FUN_00a45b90(CsScriptContextView *context)
{
    unsigned char value;
    CsScriptResultView *result;
    if (DAT_02527d24==0 && DAT_02527c0f==0)
        value=0;
    else
        value=1;
    result=context->top;
    result->field_00=1;
    result->field_08=(value!=0);
    ++context->top;
    return 1;
}
