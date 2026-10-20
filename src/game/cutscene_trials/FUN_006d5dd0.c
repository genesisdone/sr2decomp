#include "../cutscene_types.h"
/* EXE: 006D5DD0-006D5DF2; ECX receiver, value pointer on stack, RET 4.
 * Unused EDX formal expresses that thiscall interface in ordinary /TC C. */
__declspec(noinline) int __fastcall FUN_006d5dd0(CsWordList *list,void *unused,CsWord *value)
{
    int index=list->count;
    if(index+1>list->capacity) return -1;
    list->count=index+1;
    list->items[index]=*value;
    return index;
}
