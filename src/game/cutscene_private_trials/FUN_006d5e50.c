/* Complete capacity-checked append of a four-word record.
 * Evidence: 006d5e50..006d5e85, native EAX=list, EDX=value. */
#include "../cutscene_types.h"
typedef struct CsWords4 { CsWord a,b,c,d; } CsWords4;
typedef struct CsWords4List { CsWords4 *items; int capacity,count; } CsWords4List;
__declspec(noinline) int __cdecl FUN_006d5e50(CsWords4List *list, const CsWords4 *value)
{
    int index = list->count;
    CsWords4 *destination;
    if (index + 1 > list->capacity)
        return -1;
    list->count = index + 1;
    destination = list->items + index;
    destination->a = value->a;
    destination->b = value->b;
    destination->c = value->c;
    destination->d = value->d;
    return index;
}
static CsWords4List *volatile output;
static const CsWords4 *volatile input;
static volatile int result;
void comparison_entry(void) { result=FUN_006d5e50(output,input); }
