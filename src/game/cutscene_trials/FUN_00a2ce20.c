/* cutscene_play_check_done: full 00a2ce20..00a2ce85.
 * Preserve the instance +aff condition and both script-result append paths;
 * no extra instance-null guard is present in the original. */
#include "../cutscene_types.h"
typedef struct CsDoneInstanceView {
    unsigned char unknown_000[0xaff];
    unsigned char field_aff;
} CsDoneInstanceView;
extern CsDoneInstanceView *DAT_02527d10;
extern unsigned char DAT_02527d14,DAT_02527cf7,DAT_02527d15;
__declspec(noinline) int __cdecl FUN_00a2ce20(CsScriptContextView *context)
{
    CsScriptResultView *result;
    if ((DAT_02527d14==0 ||
        (DAT_02527d10->field_aff!=0 && DAT_02527cf7==0)) && DAT_02527d15==0) {
        result=context->top;
        result->field_08=1;
        result->field_00=1;
        ++context->top;
        return 1;
    }
    result=context->top;
    result->field_08=0;
    result->field_00=1;
    ++context->top;
    return 1;
}
