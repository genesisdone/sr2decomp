#include "../cutscene_types.h"
/* Whole find-or-append 006c97e0..006c982b. ECX=list, stack=value, RET 4. */
static __forceinline int cs_find_word(const CsWordList *list, const CsWord *value)
{
    int index;
    for (index=0; index<list->count; ++index)
        if (list->items[index]==*value) return index;
    return -1;
}
__declspec(noinline) int __fastcall FUN_006c97e0(CsWordList *list, void *unused, const CsWord *value)
{
    int index=cs_find_word(list,value);
    int count;
    if (index>=0) return index;
    count=list->count;
    if (count+1>list->capacity) return -1;
    list->count=count+1;
    list->items[count]=*value;
    return count;
}
