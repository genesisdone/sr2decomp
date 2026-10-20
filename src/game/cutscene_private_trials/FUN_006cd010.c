#include "../cutscene_types.h"
/* Whole 006cd010..006cd04c. Native ECX=list, EDI=identifier, AL=result.
 * The search is a separate static helper so the not-found return (loop end,
 * 006CD031) and the NULL return reached from the early exits (006CD03F) stay
 * two distinct blocks, as in the native layout. The helper name describes the
 * code below (linear search on +0 identifier); no original name is known. */
typedef struct CsAction30View { int identifier; CsWord unknown_04[10]; int state; } CsAction30View;
typedef struct CsActionListView { CsAction30View *items; int capacity,count; } CsActionListView;
static CsAction30View *find_item_by_identifier(CsActionListView *list,int identifier)
{
    int index;
    if (identifier==-1) return 0;
    for (index=0;index<list->count;++index)
        if (list->items[index].identifier==identifier) return &list->items[index];
    return 0;
}
__declspec(noinline) unsigned char __cdecl FUN_006cd010(CsActionListView *list, int identifier)
{
    CsAction30View *item=find_item_by_identifier(list,identifier);
    if (item==0) return 1;
    if (item->state==2) return 1;
    return 0;
}
static CsActionListView *volatile list_input;
static int volatile identifier_input;
static unsigned char volatile result;
void comparison_entry(void) { result=FUN_006cd010(list_input,identifier_input); }
