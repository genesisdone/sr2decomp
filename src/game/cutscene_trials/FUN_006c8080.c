/* Full guarded append: 006c8080..006c80db. The original tests the same
 * three-flag guard twice and checks capacity twice (count < capacity, then
 * count+1 <= capacity); both are kept rather than assuming an invariant.
 * The guard's meaning is not established; cs_active is a structural name. */
#include "../cutscene_types.h"
typedef struct CsGuardedWordListView {
    unsigned char unknown_000[0xb10];
    CsWordList list;
} CsGuardedWordListView;
extern CsGuardedWordListView *DAT_02527d10;
extern unsigned char DAT_02527d14,DAT_02527cf7,DAT_02527d15;
static __forceinline int cs_active(void)
{
    return (DAT_02527d14!=0 && DAT_02527cf7!=0) || DAT_02527d15!=0;
}
static __forceinline void cs_append(CsWordList *list, CsWord value)
{
    int count=list->count;
    if (count+1>list->capacity) return;
    list->count=count+1;
    list->items[count]=value;
}
__declspec(noinline) void __cdecl FUN_006c8080(CsWord value)
{
    if (cs_active()) {
        if (cs_active()) {
            CsGuardedWordListView *instance=DAT_02527d10;
            if (instance->list.count<instance->list.capacity)
                cs_append(&instance->list,value);
        }
    }
}
