/* Whole find-or-append helper: 006d5cf0..006d5d4c. Native ECX=list, EDI=value.
 * The two-word identity comparison and the third appended word are distinct.
 * The loop bound reads list->count in the condition; the append re-reads it. */
#include "../cutscene_types.h"
typedef struct CsWords3List { CsWords3 *items; int capacity,count; } CsWords3List;
__declspec(noinline) int __fastcall FUN_006d5cf0(CsWords3List *list, const CsWords3 *value)
{
    CsWords3 *record;
    int i; int count;
    for (i=0;i<list->count;++i)
        if (list->items[i].x==value->x && list->items[i].y==value->y) {
            if (i>=0) return i;
            break;
        }
    count=list->count;
    if (count+1 > list->capacity)
        return -1;
    list->count = count+1;
    record = list->items+count;
    record->x = value->x;
    record->y = value->y;
    record->z = value->z;
    return count;
}
static CsWords3List *volatile output;
static const CsWords3 *volatile input;
static volatile int result;
void comparison_entry(void) { result=FUN_006d5cf0(output,input); }
