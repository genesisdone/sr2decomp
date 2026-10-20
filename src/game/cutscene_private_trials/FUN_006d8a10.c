#include "../cutscene_types.h"
/* Distinct original address, same find-or-append operations.
 * Whole find-or-append 006d8a10..006d8a5b. Native ECX=list, stack=value, RET 4. */
__declspec(noinline) int __stdcall FUN_006d8a10(CsWordList *list, const CsWord *value)
{
    /* Address taken only so /LTCG keeps the value an incoming stack word, as natively. */
    const CsWord **keep=&value;
    int index;
    int count;
    (void)keep;
    for (index=0; index<list->count; ++index)
        if (list->items[index]==*value) {
            /* Always true here; kept because the native code tests the found
             * index again before returning it, and this test reproduces that. */
            if (index>=0) return index;
            break;
        }
    count=list->count;
    if (count+1>list->capacity) return -1;
    list->count=count+1;
    list->items[count]=*value;
    return count;
}
static CsWordList *volatile list_input;
static const CsWord *volatile value_input;
static int volatile result;
void comparison_entry(void) { result=FUN_006d8a10(list_input,value_input); }
