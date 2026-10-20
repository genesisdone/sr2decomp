#include "../cutscene_types.h"
/* Whole 006c3820..006c3894, native EDI=list (LTCG-chosen). Both selection
 * paths share one fallback return of the first record. No null guard added.
 * Agent-1 probe 2026-10-19: both /LTCG links equal, 116/116 bytes; canonical
 * private gate not yet run on this revision. */
typedef struct CsChoice18 { int first,second,identifier; CsWord unknown_0c[3]; } CsChoice18;
typedef struct CsChoiceList { CsChoice18 *items; int capacity,count; } CsChoiceList;
typedef struct CsIdentifierView { CsWord unknown_00[2]; int identifier; } CsIdentifierView;
typedef struct CsSelectionActorView { unsigned char unknown_000[0x190]; CsIdentifierView *identity; } CsSelectionActorView;
typedef struct CsSelectionInstanceView { unsigned char unknown_0000[0x1688]; CsSelectionActorView *actor; } CsSelectionInstanceView;
extern CsSelectionInstanceView *DAT_02527d10;
extern unsigned char __cdecl FUN_004d9900(int first, int second);
__declspec(noinline) CsChoice18 * __cdecl FUN_006c3820(CsChoiceList *list)
{
    CsSelectionActorView *actor=DAT_02527d10->actor;
    if (actor) {
        int count=list->count;
        int index=0;
        if (count>0) {
            int identifier=actor->identity->identifier;
            CsChoice18 *item=list->items;
            do {
                if (item->identifier==identifier) return item;
                ++index;
                ++item;
            } while (index<count);
        }
    } else {
        int index;
        for (index=0; index<list->count; ++index) {
            CsChoice18 *item=&list->items[index];
            if (FUN_004d9900(item->first,item->second)==1) return item;
        }
    }
    return list->items;
}
static CsChoiceList *volatile list_input;
static CsChoice18 *volatile result;
void comparison_entry(void) { result=FUN_006c3820(list_input); }
