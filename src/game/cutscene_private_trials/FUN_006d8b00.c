#include "../cutscene_types.h"
/* Whole 006d8b00..006d8b3f. Native EDI=list, stack=name pointer, RET 4.
 * Full private /GL trial; the gate must verify actual cleanup and all bytes. */
typedef struct CsNamedPair { const char *name; CsWord field_04; } CsNamedPair;
typedef struct CsNamedPairList { CsNamedPair *items; int capacity,count; } CsNamedPairList;
extern int __cdecl FUN_00c99030(const char *left, const char *right);
__declspec(noinline) int __stdcall FUN_006d8b00(CsNamedPairList *list, const char **name)
{
    /* Address taken only so /LTCG keeps the name an incoming stack word, as natively. */
    const char ***keep=&name;
    int index=0;
    (void)keep;
    if (list->count>0) {
        do {
            CsNamedPair *item=&list->items[index];
            if (FUN_00c99030(item->name,*name)==0) return index;
            ++index;
        } while (index<list->count);
    }
    return -1;
}
static CsNamedPairList *volatile list_input;
static const char **volatile name_input;
static int volatile result;
void comparison_entry(void) { result=FUN_006d8b00(list_input,name_input); }
